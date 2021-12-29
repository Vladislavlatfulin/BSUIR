#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <term.h>

struct RailwayStation{
    struct time {
        int hours;
        int minutes;
    };
    int trainNumber;
    char destination[50];
    int days;
    struct time arrivalTime;
    struct time parkingTime;
};

bool dataChecking(int, int);
void outputInformation(struct RailwayStation);
void chengeInformation(struct RailwayStation*, int);
void searchSelectedField(struct RailwayStation*, int);

void inputTripDays(struct RailwayStation*, int);
void inputTrainNumber(struct RailwayStation*, int);
void inputDestination(struct RailwayStation*, int);
void inputArrivalTime(struct RailwayStation*, int);
void inputParkingTime(struct RailwayStation*, int);
void inputUserString(char*, int);
int inputChoice(void);
int inputParametr(void);
int inputHours(void);
int inputMinutes(void);
int inputIndex(int);

void sortPointer(struct RailwayStation*, int);
void conversionToUppercase(char array[50]);
void deleteStructure(struct RailwayStation*, int&);
void deleteOneStructure(struct RailwayStation*, int&, int);
void printOption(void);
int menu(void);
void partialSearch (struct RailwayStation *, int);
int confirmation(void);

#endif 
