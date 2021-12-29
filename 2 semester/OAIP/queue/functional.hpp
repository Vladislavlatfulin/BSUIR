#ifndef functional_hpp
#define functional_hpp

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
};

struct Queue {
    struct Passenger information;
    struct Queue *next;
};


int menu(void);
int push (struct Queue **, struct Queue **);
bool dataChecking(int, int);
int inputChoice (void);
void correctInput (char *, int);

void output (struct Queue*, struct Queue *,int);
void outputOneStructure (struct Queue*, int);
void printNormalString (char*);

void search(struct Queue*, int);
void conversionToUppercase(char array[20]);
void inputUserString(char *, int);
int numberOfFullNode(struct Queue *head, struct Queue *tail);

void deleteNode(struct Queue**, struct Queue** ,int, int);

void saveInFile (struct Queue*, struct Queue*);
int loadFromFile(struct Queue**, struct Queue**);


#endif /* functional_hpp */
