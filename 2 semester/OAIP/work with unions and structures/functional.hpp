#ifndef functional_hpp
#define functional_hpp
#define LENGTH 20

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void outputInformation (struct Passenger);
void output (struct Passenger* , int);
void outputOneStructure (struct Passenger*, int);
void printNormalString (char*);
void printOption(void);

bool dataChecking(int, int);
int menu(void);

int inputChoice();
void correctInput (char*, int);
void inputInformation (struct Passenger*, int);
void inputUserString(char *, int);
void search(struct Passenger*, int);
void conversionToUppercase(char array[50]);

void deleteStructure(struct Passenger*, int&);
void deleteOneStructure (struct Passenger*, int&, int);
int confirmation (void);

void addInformation (struct Passenger* ,int&, int&);


struct Passenger {
    
    int numberOfFlights ;
    char *lastname ;
    bool isChoiceUnion ;
    union data {
        int numberOfMinutes;
        char dateOfDeparture[20];
    }unionVar;
    
//    int init (int i) {
//        int choice, check, j;
//        char c;
//        printf("Enter %d number of flights\n", i + 1);
//        numberOfFlights = inputChoice();
//
//        do {
//            if (!(lastname = (char*)malloc(LENGTH * sizeof(char)))) {
//                printf("Reduce the number of characters in the last name\n");
//                continue;
//            }
//        } while(!lastname);
//
//        printf("Enter last name %d trip.\n", i + 1);
//
//        correctInput(lastname);
//
//        printf("Select one information you want to enter.\n 1 - Number of minutes on the way.\n 2 - Check out date.\n");
//
//        do {
//            check = scanf("%d", &choice);
//
//            if (check < 1 || choice < 1 || choice > 2) {
//                rewind(stdin);
//                printf("Choose another item.\n");
//                continue;
//            }
//        }while (check < 1 || choice < 1 || choice > 2);
//
//        if (choice == 1) {
//            isChoiceUnion = true;
//        }
//
//        if (choice == 2) {
//            isChoiceUnion = false;
//        }
//
//        if (isChoiceUnion) {
//            printf("Enter number of minutes.\n");
//            unionVar.numberOfMinutes = inputChoice();
//        }
//
//        else if (!isChoiceUnion) {
//            printf("Enter check out date.\n");
//            do {
//                j = 0;
//                int length = LENGTH;
//                rewind(stdin);
//                while (( c = getchar()) != '\n' && --length > 0) {
//                    unionVar.dateOfDeparture[j++] = c;
//                }
//                for (j = 0; unionVar.dateOfDeparture[j]; j++) {
//                    if (!isdigit(c)) {
//                        printf("You are using prohibited items. Try to enter again.\n");
//                        rewind(stdin);
//                        for (j = 0; unionVar.dateOfDeparture[j]; j++) {
//                            unionVar.dateOfDeparture[j] = '\0';
//                        }
//                        break;
//                    }
//                }
//
//            } while (unionVar.dateOfDeparture[0]  == '\0' || ((unionVar.dateOfDeparture[j]) < '0' && unionVar.dateOfDeparture[j] > '9'));
//            unionVar.dateOfDeparture[j++] = '\n';
//            unionVar.dateOfDeparture[j] = '\0';
//        }
//
//        return 0;
//    }
    
};

#endif /* functional_hpp */
