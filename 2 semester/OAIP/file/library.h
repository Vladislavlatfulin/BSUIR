#include <stdio.h>
#if defined(__MACH__)
#include <stdlib.h>
#else
#include <malloc.h>
#endif
#include <math.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

void inputInformation (char* pointer, int length) {
    char c;
    int i = 0, tempLength = length;
    
    do {
        rewind(stdin);
        while ((c = getchar()) != '\n' && --tempLength > 0) {
            pointer[i++] = c;
            if (c == '\n') {
                printf("You are using prohibited items. Try to enter again.\n");
                rewind(stdin);
                i = 0;
                tempLength = length;
            }
        }
    }while (i == 0);
}

void inputFileName (char* pointer, int length) {
    char c;
    int i = 0, tempLength = length;
    
    do {
        rewind(stdin);
        while ((c = getchar()) != '\n' && --tempLength > 0) {
            pointer[i++] = c;
            if (c == '\n' || isdigit(c) || c == ' '||  c == '[' || c == ']' || c == '{' || c == '}' || c == '/' || c == ':' || c == ';' || c == '"' || c == '?' || c == '!' || c == '+' || c == '-' || c == '@' || c == '<' || c == '>' || c == '#' || c == '&' ) {
                printf("You are using prohibited items. Try to enter again.\n");
                rewind(stdin);
                i = 0;
                tempLength = length;
            }
        }
    }while (i == 0);
    
}

void inputInformationIntoFile (FILE* file, int typeFile, char* fileName) {
    int lengthString, check, count;
    char *string = NULL;
    
    if (typeFile == 1) {
        
        if (!(file = fopen(fileName, "w"))) {
            printf("Could not find file\n");
            return;
        }
        
        printf("\nEnter length string\n");
        do {
            check = scanf("%d", &lengthString);
            if (check < 1 || lengthString < 1) {
                printf("Enter number!\n");
                rewind(stdin);
                continue;
            }
        }while(check < 1 || lengthString < 1);
        
        string = (char*)malloc(lengthString * sizeof(char));
        printf("\nEnter information\n");
        inputInformation(string, lengthString);
        
        rewind(file);
        fprintf(file, "%s", string);
    }
    
    else {
        if (!(file = fopen(fileName, "wb"))) {
            printf("Could not find file\n");
            return;
        }
        
        printf("\nEnter information.\n");
        printf("Enter the quantity value.\n");
        do {
            
            check = scanf("%d", &count);
            if (check < 1 || count < 1) {
                printf("Enter number!\n");
                rewind(stdin);
                continue;
            }
            
        }while (check < 1 || count < 1);
        
        for (int i = 0; i < count; i++) {
            int number;
            do {
                printf("\nEnter your number.\n");
                check = scanf("%d", &number);
                if (check < 1 || number < 1) {
                    printf("\nEnter number!\n");
                    rewind(stdin);
                    continue;
                }
            }while (check < 1 || number < 1);
            fwrite(&number, sizeof(int), 1, file);
        }
    }
    
    fclose(file);
    free(string);
}

void outputInformationFile(FILE *file, int typeFile, char* fileName) {
    
    if (typeFile == 1) {
        char c;
        if (!(file = fopen(fileName, "r"))) {
            printf("Could not find file\n");
            return;
        }
        
        printf("\nYour file information\n");
        rewind(file);
        while ((c = getc(file))!= EOF) {
            printf("%c", c);
        }
    }
    
    else if (typeFile == 2) {
        int i;
        if (!(file = fopen(fileName, "rb"))) {
            printf("Could not find file\n");
            return;
        }
        
        printf("\nYour file information\n");
        rewind(file);
        do {
            fread(&i, sizeof(int), 1, file);
            if (feof(file)) {
                break;
            }
            printf("%d ", i);
        }while(1);
    }
}

void wordCount(FILE* file, char* fileName) {
    int givenLength, count = 0, check;
    fpos_t lastSymbol = 0, firstSymbol = 0;
    
    if (!(file = fopen(fileName, "r"))) {
        printf("Could not find file\n");
        return;
    }
    
    printf ("\nPrint given length\n");
    do {
        check = scanf("%d", &givenLength);
        if (check < 1 || givenLength < 1) {
            printf("Enter number\n");
            rewind(stdin);
            continue;
        }
    } while (check < 1 || givenLength < 1);
    
    rewind(file);
    while (1) {
        char c = '\0';
        while (!feof(file)) {
            fgetpos(file, &firstSymbol);
            fscanf(file, "%c", &c);
            if (c != ' ') {
                break;
            }
        }
        
        if (feof(file)) {
            break;
        }
        
        while (c != ' ' && !feof(file)) {
            fgetpos(file, &lastSymbol);
            fscanf(file, "%c", &c);
        }
        
        if (lastSymbol - firstSymbol == givenLength) {
            count++;
        }
    }
    printf("\nWord number: %d\n", count);
}

void deleteWord(FILE* file, char* fileName) {
    char firstSymbol = '\0', userSymbol = ' ';
    fpos_t firstPosition = 0, lastPosition = 0;
    printf("\nEnter characner\n");
    do {
        rewind(stdin);
        scanf("%c", &userSymbol);
        if (userSymbol == ' ' || userSymbol == '\n') {
            printf("oops"); //todo
            rewind(stdin);
        }
    }while (userSymbol == ' ' || userSymbol == '\n');
    
    if (!(file = fopen(fileName, "r+a"))) {
        printf("Could not find file\n");
        return ;
    }
    
    rewind(file);
    while (!feof(file)) {
        while (!feof(file)) {
            fgetpos(file, &firstPosition);
            fscanf(file, "%c", &firstSymbol);
            if (firstSymbol != ' ') {
                break;
            }
        }
        
        if (userSymbol == firstSymbol) {
            fsetpos(file, &firstPosition);
            while (!feof(file) && (firstSymbol != ' ')) {
                fgetpos(file, &lastPosition);
                fscanf(file, "%c", &firstSymbol);
            }
            
            fsetpos(file, &firstPosition);
            long int length = lastPosition - firstPosition;
            while (length) {
                fprintf(file, "%c", ' ');
                length--;
            }
            rewind(file);
        }
        
        else {
            while (!feof(file)) {
                fscanf(file, "%c", &firstSymbol);
                if (firstSymbol == ' ') {
                    break;
                }
            }
        }
        
    }
    fclose(file);
}

void loadCapacityOfCargo(FILE *file, char* fileName) {
    int carryingCapacity, check, j, sumOfWeights = 0, count = 0;
    
    if (!(file = fopen(fileName, "r + b"))) {
        printf("Could not find file\n");
        return;
    }
    
    for(int i = 0; ;i++) {
        fread(&j, sizeof(int), 1, file);
        if (feof(file)) {
            break;
        }
        printf("\n%d load mass: %d\n", i + 1, j);
    }
    
    printf("\nEnter Carrying capacity.\n");
    do {
        check = scanf("%d", &carryingCapacity);
        if (check < 1 || carryingCapacity < 1) {
            printf("Enter number\n");
            rewind(stdin);
            continue;
        }
    }while(check < 1 || carryingCapacity < 1);
    
    rewind(file);
    do {
        fread(&j, sizeof(int), 1, file);
        sumOfWeights += j;
        if (sumOfWeights > carryingCapacity || feof(file)) {
            break;
        }
        count++;
    }while((carryingCapacity > sumOfWeights) && !feof(file));
    printf("\nNumber of scales: %d", count);
}

void linearTransformation (FILE *file, char* fileName) {
    int functionCoefficient, check, bCoefficient, i, counter = 0;
    
    if (!(file = fopen(fileName, "r+b"))) {
        printf("Could not find file\n");
        return;
    }
    
    printf("\nEnter function coefficient.\n");
    do {
        check = scanf("%d", &functionCoefficient);
        if (check < 1) {
            printf("Enter number\n");
            rewind(stdin);
            continue;
        }
    }while(check < 1);
    
    rewind(file);
    fseek(file, -sizeof(int), 2);
    fread(&i, sizeof(int), 1, file);
    bCoefficient = i;
    
    rewind(file);
    while (!feof(file)) {
        if (fread(&i, sizeof(int), 1, file)) {
            counter++;
            i = (functionCoefficient * i) + bCoefficient;
            fseek(file, (-sizeof(int)), 1);
            fwrite(&i, sizeof(int), 1, file);
        }
    
    }
    fclose(file);
}
