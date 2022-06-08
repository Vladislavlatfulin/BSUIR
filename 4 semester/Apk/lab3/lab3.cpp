/*
+ 1) c помощью системного таймера генерирует звук заданной частоты (по вариантам);
+ 2) выводит слово состояния для каждого канала в двоичном виде;
+ 3) определяет коэффициент деления для каждого канала в 16-ричном виде.
+ *Реализовать генератор случайных чисел от нуля до заданного с клавиатуры числа.
*/

#include <dos.h>
#include <stdio.h>

const unsigned long int maxValue = 1193180;

int isTask = 0;

int arrSize = 52;
//freq = 0 => delay
const int music[] = {
    123, 390,
    0, 10,
    123, 450,
    93, 50,
    123, 50,
    148, 50,
    185, 190,
    0, 10,
    185, 400,
    110, 600,

    148, 450,
    93, 50,
    165, 100,
    185, 190,
    0, 10,
    185, 400,
    139, 1000,

    69, 390,
    0, 10,
    69, 400,
    148, 200,
    139, 400,
    148, 200,
    139, 400,
    93, 200,

    123, 1000
};

int taskSize = 18;
const int task[] = {
    329, 200,
    329, 100,
    329, 200,
    415, 400,
    523, 200,
    659, 200,
    587, 400,
    523, 200,
    659, 400
};

const unsigned int timesToRepeate = 30000;

struct oneByte{
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int b3 : 1;
    unsigned int b4 : 1;
    unsigned int b5 : 1;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
};

void playOneBeep(int f, int sleepTime)
{
    int delim;
    outp(0x43, 0xB6);                        //10(channel 2) 11(RW lower, than higher) 011(mode 3: with autoloading) 0 (binary)
    delim = maxValue / f;
    outp(0x42, delim % 0x100);
    outp(0x42, delim / 0x100);

    //включаем динамик
    delim = inp(0x61);
    outp(0x61, delim | 0x03);

    delay(sleepTime);

    //выключаем динамик
    delim = inp(0x61);
    outp(0x61, delim & 0xFC);
}

void playSound()
{
    int size = isTask == 0 ? arrSize : taskSize;
    const int *arr = isTask == 0 ? music : task;
    double k = 1.5;
    int i;

    for (i = 0; i < size; ++i, ++i)
    {
        if (arr[i] == 0)
        {
            delay(k * arr[i+1]);
        }
        else
        {
            playOneBeep(arr[i], k*arr[i+1]);
        }
    }
}

//channel must be 0, 1 or 2 only
int getState(int channel)
{
    outp(0x43, 0xE0 + (2 << channel));            //11(RBC mode: read channel mode) 1(not save CE - current state of counter) 0(read value of channel) number_of_channel 0
    return inp(0x40 + channel);
}

void printStateWords()
{
    int i;
    int port = 0x40;
    int valuep;
    struct oneByte* ob = (oneByte*)&valuep;

    printf("State words:\n");

    for (i = 0; i < 3; ++i, port++)
    {
        valuep = getState(i);
        printf("Port 0x%X: %d%d%d%d%d%d%d%d\n", port, ob->b7, ob->b6, ob->b5, ob->b4, ob->b3, ob->b2, ob->b1, ob->b0);
    }
}

int max(unsigned int* m)
{
    unsigned int i, max = 0;

    for (i = 0; i < timesToRepeate; ++i)
    {
        if (max < m[i])
        {
            max = m[i];
        }
    }

    return max;
}

unsigned int getCE(int channel)
{
    int state;
    int delim;
    int port = 0x40;
    state = getState(channel);
    outp(0x43, (state & 0x0F) | (channel << 6));            //(state & 0x0F) => SC (channel number) = 0, RW = 0 (get CE); than add channel number
    outp(0x43, (state & 0x3F) | (channel << 6) | 0x30);            //(state & 0x3F) => SC = 0; ... | 0x30 => RW = 11 (first lower part)
    state = inp(port + channel);
    delim = inp(port + channel);
    delim <<= 8;
    delim += state;
    return delim;
}

void printDelims()
{
    unsigned int m[timesToRepeate];
    int i;
    unsigned int j;
    int port = 0x40;
    int delim = 0;
    int speakerWasOn = 0;

    printf("Delimiters:\n");

    for (i = 0; i < 3; ++i, port++)
    {
        if (i == 2)
        {
            //включаем только канал
            delim = inp(0x61);
            speakerWasOn = delim & 0x01;
            outp(0x61, delim | 0x01);
        }

        for (j = 0; j < timesToRepeate; j++)
        {
            m[j] = getCE(i);
        }

        printf("Port 0x%X: %X\n", port, max(m));
    }

    //выключаем только канал, если нужно
    delim = inp(0x61);
    speakerWasOn |= 0xFFFE;                                    //все биты, кроме последнего
    outp(0x61, delim & speakerWasOn);
}

void AJIOBrandom()
{
    int delim = 0;
    int speakerWasOn = 0;
    unsigned int maxNum = 0;

    printf("Input max random number, please\n");
    scanf("%u", &maxNum);

    //clear buffer
    while (getchar() != '\n');

    outp(0x43, 0xB4);                        //10(channel 2) 11(RW lower, than higher) 010(mode 2: with autoloading) 0 (binary)
    outp(0x42, maxNum % 0x100);
    outp(0x42, maxNum / 0x100);

    //включаем только канал
    delim = inp(0x61);
    speakerWasOn = delim & 0x01;
    outp(0x61, delim | 0x01);

    printf("Press Enter go generate number\n");
    getchar();

    printf("Your number is: %u", getCE(2));

    //выключаем только канал, если нужно
    delim = inp(0x61);
    speakerWasOn |= 0xFFFE;                                    //все биты, кроме последнего
    outp(0x61, delim & speakerWasOn);
}

int main()
{
    printf("Start values:\n");
    printStateWords();
    printDelims();

    playSound();

    printf("\nEnd values:\n");
    printStateWords();
    printDelims();

    AJIOBrandom();
    return 0;
}
