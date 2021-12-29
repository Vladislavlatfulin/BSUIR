
#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


struct Passenger {
    int numberOfFlight;
    char* lastname;
    union dataOrNumber{
        char dataOfDeparture[20];
        int numberOfMinutes;
    }unionVar;
    bool choiceUnion;
    struct Passenger *pointer;
};

bool dataChecking(int, int);
int menu(void);
int inputChoice (void);
void correctInput (char*, int);
int push(struct Passenger **);

void search(struct Passenger*, int);

void conversionToUppercase(char array[20]);
void inputUserString(char *, int);

void outputInformation (struct Passenger);
void output (struct Passenger* , int);
void outputOneStructure (struct Passenger*, int);
void printNormalString (char*);
void printOption(void);
void deleteNode(struct Passenger**, int, int);

void saveInFile (struct Passenger *);
void inputFileName (char*, int);
int loadFromFile (struct Passenger**);

#endif /* functions_hpp */
