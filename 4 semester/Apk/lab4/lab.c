#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>

unsigned int delay_time = 0;
unsigned int delay_ms = 0;
char data[6];

// 0xA1 - RTC service line
// 0x00 - seconds
// 0x02 - minutes
// 0x04 - hours
// 0x07 - day of month
// 0x08 - month
// 0x09 - year
// 0x0A - state register A
// 0x0B - stare register B

// function pointers for system interrupt handlers (timer and alarm)
void interrupt (*__timer_handler_sys)(...);

void interrupt (*__alarm_handler_sys)(...);

unsigned char convert_to_dec(int value);
unsigned char convert_to_bcd(int value);
void refresh_time();
void print_time();
void set_new_time();
void make_delay(unsigned int ms);
void set_alarm();
void reset_alarm();
void enter_new_time();

void interrupt __alarm_handler_usr(...)
{
    outp(0x70, 0x0C);
    
    if (inp(0x71) & 0x20) {
        puts("ALARM!!!\n");
    }
    outp(0x20, 0x20);
    outp(0x0A, 0x20);

    disable();
    setvect(0x70, __alarm_handler_sys);
    enable();
    outp(0x70, 0x0B);
    outp(0x71, (inp(0x71) & 0xDF));
}

void interrupt __timer_handler_usr(...)
{
    outp(0x70, 0x0C);
    if (inp(0x71) & 0x40) {
        delay_time++;
    }
    
    outp(0x20, 0x20);
    outp(0xA0, 0x20);

    if (delay_time == delay_ms) {
        puts("End of delay\n");
        disable();
        setvect(0x70, __timer_handler_sys);
        enable();
        outp(0x70, 0x0B);
        outp(0x71, (inp(0x71) & 0xBF));
    }
}

int main()
{
    int ms;
    while (1)
    {
        printf("[1] Current time\n");
        printf("[2] Set time\n");
        printf("[3] Set alarm\n");
        printf("[4] Set delay\n");
        printf("[5] Exit\n");

        switch (getch())
        {
        case '1':
            system("cls");
            refresh_time();
            print_time();
            break;
        case '2':
            system("cls");
            set_new_time();
            break;
        case '3':
            system("cls");
            set_alarm();
            break;
        case '4':
            system("cls");
            fflush(stdin);
            puts("Enter delay(ms): ");
            scanf("%d", &ms);
            make_delay(ms);
            break;
        case '5':
            system("cls");
            return 0;
        default:
            system("cls");
            puts("Incorrect input!\n");
            break;
        }
    }
}

unsigned char convert_to_dec(int value)
{
    return (unsigned char) ( ( value / 16 * 10 ) + ( value % 16 ) );
}

unsigned char convert_to_bcd(int value)
{
    return (unsigned char) ( ( value / 10 * 16 ) + ( value % 10 ) );
}

#define CMOS_TIME_COUNT 6
void refresh_time()
{
    unsigned int time_cmos[] = { 0x00, 0x02, 0x04, 0x07, 0x08, 0x09 };

    for (int i = 0; i < CMOS_TIME_COUNT; i++) {
        outp(0x70, time_cmos[i]);
        data[i] = inp(0x71);
    }
}

int * convert_time_to_dec()
{
    int * converted = (int*)malloc(CMOS_TIME_COUNT * sizeof(int));

    for (int i = 0; i < CMOS_TIME_COUNT; i++) {
        converted[i] = convert_to_dec(data[i]);
    }
    return converted;
}
#undef CMOS_TIME_COUNT

void print_time()
{
    int * converted = convert_time_to_dec();
    char * format = NULL;

    char * months[] = {
        "Jan", "Feb", "Mar",
        "Apr", "May", "Jun", "Jul",
        "Aug", "Sept", "Oct",
        "Nov", "Dec"
    };

    format = (converted[2] < 10) ? "0%d:" : "%2d:";
    printf(format, converted[2]);

    format = (converted[1] < 10) ? "0%d:" : "%2d:";
    printf(format, converted[1]);

    format = (converted[0] < 10) ? "0%d\n" : "%2d\n";
    printf(format, converted[0]);

    printf("%s, %2d, ",  months[converted[4] - 1], converted[3]);
    
    format = (converted[5] < 10) ? "200%d\n" : "20%2d\n";
    printf(format, converted[5]);
}

void set_new_time()
{
    enter_new_time();

    disable();

    outp(0x70, 0x0B);
    outp(0x71, inp(0x71) & 0x7F);

    int time_cmos[] = { 0x00, 0x02, 0x04 };

    for (int i = 0; i < 3; i++) {
        outp(0x70, time_cmos[i]);
        outp(0x71, data[i]);
    }

    enable();
}

void make_delay(unsigned int ms)
{
    delay_time = 0;
    delay_ms = ms;
    
    disable();

    __timer_handler_sys = getvect(0x70);
    setvect(0x70, __timer_handler_usr);
    outp(0xA1, (inp(0xA0) & 0xFE));
    
    enable();
    outp(0x70, 0x0B);
    outp(0x71, (inp(0x71) | 0x40));
}

void set_alarm()
{
    enter_new_time();

    disable();

    __alarm_handler_sys = getvect(0x70);
    setvect(0x70, __alarm_handler_usr);
    outp(0xA1, (inp(0xA0) & 0xFE));

    int alarm_cmos[] = { 0x01, 0x03, 0x05 };

    for (int i = 0; i < 3; i++) {
        outp(0x70, alarm_cmos[i]);
        outp(0x71, data[i]);
    }

    enable();

    outp(0x70, 0x0B);
    outp(0x71, inp(0x71) | 0x20);

    puts("Alarm enabled!\n");
}

void reset_alarm()
{
    disable();
    setvect(0x4A, __alarm_handler_sys); // set old handler
    outp(0x70, 0x05);                   // set zero values
    outp(0x71, 0);
    outp(0x70, 0x03);
    outp(0x71, 0);
    outp(0x70, 0x01);
    outp(0x71, 0);
    enable();
}

int get_value(int low, int high, char * const instruct)
{
    int value;

    do {
        puts(instruct);
        scanf("%d", &value);
    } while (value > high && value < low);

    return value;
}

void enter_new_time()
{
    int n = get_value(0, 23, "Enter hours: ");
    data[2] = convert_to_bcd(n);

    n = get_value(0, 59, "Enter minutes");
    data[1] = convert_to_bcd(n);

    n = get_value(0, 59, "Enter seconds: ");
    data[0] = convert_to_bcd(n);
}
