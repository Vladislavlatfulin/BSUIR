#include "functional.hpp"

int menu () {
    int tempMenu = 0, flag = 0, check;
    
    printf("Enter number for change.\n");
    printf("1 - Enter your data.\n");
    printf("2 - Output your data.\n");
    printf("3 - Search selected field.\n");
    printf("4 - Delete selected field.\n");
    printf("5 - Add new information.\n");
    printf("6 - To finish work.\n");
    
    while (!flag) {
        check = scanf("%d", &tempMenu);
        
        if (dataChecking(check, tempMenu)) {
            rewind(stdin);
            printf("There is no such number. Try to enter again.\n");
            continue;
        }
        
        flag += 1;
    }
    return tempMenu;
}


bool dataChecking (int check, int data) {
    return ((data < 1 || check < 1)? true: false);
}

bool timeCheckingHours (int check, int time) {
    return (time < 0 || time > 23 || check < 1)? true: false;
}

bool timeCheckingMinutes (int check, int time) {
    return (time < 0 || time > 59 || check < 1)? true: false;
}

bool parametrCheck (int check, int parametr) {
    return (check < 1 || parametr <= 0 || parametr > 6)? true: false;
}

int inputChoice (void) {
    int check, choice;
    rewind(stdin);
    
    do {
        check = scanf("%d", &choice);
        
        if (dataChecking(check, choice)) {
            rewind(stdin);
            printf("There is no such number. Try to enter again.\n");
            continue;
        }
    }while (dataChecking(check, choice));
    
    return choice;
}

void correctInput (char *string, int length) {
    int j = 0;
    int tempLength = length;
    char c;
    
    do {
        rewind(stdin);
        while ((c = getchar()) != '\n' && --tempLength > 0) {
            string[j++] = c;
            
            if (c == '\n' || isdigit(c)) {
                printf("You are using prohibited items. Try to enter again.\n");
                j = 0;
                tempLength = length;
                break;
            }
        }
        
    } while (!j);
    
    string[j++] = '\n';
    string[j] = '\0';
}


void output (struct Passenger* pointerToPassenger, int numberOfPassenger) {
    int choice, check;
    
    if(pointerToPassenger == NULL) {
        printf("oops\n");
        return;
    }
    
    while (1) {
        printf("\nDisplay:\n1 - Choose passenger\n2 - All passenger\n3 - Exit\n\nYour choice: ");
        choice = inputChoice();
        
        switch (choice) {
            case 1:
                printf("Select number.\n (from 1 to %d)", numberOfPassenger);
                
                do {
                    check = scanf("%d", &choice);
                    
                    if (check < 1 || choice < 0 || choice >= numberOfPassenger) {
                        rewind(stdin);
                        printf("Choose another item.\n");
                        continue;
                    }
                }while (check < 1 || choice < 0 || choice > numberOfPassenger);
                choice -= 1;
                
                printf("-----------------------------------------------------------------------------------------\n");
                printf("| № | number of flights | last name           | number of minutes | check out date      |\n");
                outputOneStructure(pointerToPassenger, choice);
                
                break;
                
            case 2:
                printf("-----------------------------------------------------------------------------------------\n");
                printf("| № | number of flights | last name           | number of minutes | check out date      |\n");
                
                for (choice = 0; choice < numberOfPassenger; choice++) {
                    outputOneStructure(pointerToPassenger, choice);
                }
                
                break;
                
            case 3:
                return;
                
            default:
                printf("Choose another item.\n");
                break;
        }
    }
}

void outputOneStructure (struct Passenger* pointerToPassenger, int index) {
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| %d |", index + 1);
    printf(" %-6d            | ", pointerToPassenger[index].numberOfFlights);
    printNormalString(pointerToPassenger[index].lastname);
    
    if (pointerToPassenger[index].isChoiceUnion) {
        printf(" %-6d           | ------------------- |\n", pointerToPassenger[index].unionVar.numberOfMinutes);
    }
    
    if (!pointerToPassenger[index].isChoiceUnion) {
        printf("----------------- | ");
        printNormalString(pointerToPassenger[index].unionVar.dateOfDeparture);
        printf("\n");
    }
    
    printf("-----------------------------------------------------------------------------------------\n");
    
}

void printNormalString (char *pointer) {
    int i;
    
    for (i = 0; pointer[i] != '\n'; i++) {
        putchar(pointer[i]);
    }
    
    for (; i < 20; i++) {
        printf(" ");
    }
    
    printf("| ");
}

void inputInformation (struct Passenger* onePassenger, int index) {
    int choice, check, j;
    char c;
    int length;
    
    printf("\nEnter %d number of flights\n", index + 1);
    onePassenger[index].numberOfFlights = inputChoice();
    
    printf("\nEnter length last name\n"); // todo
    
    do {
        check = scanf("%d", &length);
        if (check < 1 || length > 20 || length < 1) {
            printf("Enter less number. Try again\n");
            rewind(stdin); // todo
            continue;
        }
        
    }while(check < 1 || length > 20 || length < 1);
    
    
    do {
        if (!(onePassenger[index].lastname = (char*)malloc(length * sizeof(char)))) {
            printf("Reduce the number of characters in the last name\n");
            continue;
        }
    } while(!onePassenger[index].lastname);
    
    printf("\nEnter last name %d passenger.\n", index + 1);
    correctInput(onePassenger[index].lastname, length);
    
    printf("\nSelect one information you want to enter.\n1 - Number of minutes on the way.\n2 - Date of departure.\n");
    do {
        check = scanf("%d", &choice);
        
        if (check < 1 || choice < 1 || choice > 2) {
            rewind(stdin);
            printf("Choose another item.\n");
            continue;
        }
    }while (check < 1 || choice < 1 || choice > 2);
    
    if (choice == 1) {
        onePassenger[index].isChoiceUnion = true;
    }
    
    if (choice == 2) {
        onePassenger[index].isChoiceUnion = false;
    }
    
    if (onePassenger[index].isChoiceUnion) {
        printf("\nEnter number of minutes %d flight.\n", index + 1);
        onePassenger[index].unionVar.numberOfMinutes = inputChoice();
    }
    
    else if (!onePassenger[index].isChoiceUnion) {
        printf("\nEnter date of departure %d flight.\n", index + 1);
        j = 0;
        int length = LENGTH;
        do {
            rewind(stdin);
            while ((c = getchar()) != '\n' && --length > 0) {
                onePassenger[index].unionVar.dateOfDeparture[j++] = c;
                if (c == '\n' || !isdigit(c)) {
                    printf("You are using prohibited items. Try to enter again.\n");
                    rewind(stdin);
                    j = 0;
                    length = LENGTH;
                }
            }
        } while (j == 0);
        
        onePassenger[index].unionVar.dateOfDeparture[j++] = '\n';
        onePassenger[index].unionVar.dateOfDeparture[j] = '\0';
    }
    
}


void search (struct Passenger *pointerToPassenger, int numberOfPassenger) {
    int i, choice, flag = 0, length, j = 0, userVar;
    char *userString1 = NULL, *tempString = NULL;
    int iMax = 0, maxNumberOfMinutes = 0;
    
    while (1) {
        
        printf("\nSelect the parameter by which the search will go.\n");
        printOption();
        rewind(stdin);
        choice = inputChoice();
        
        switch (choice) {
            case 1:
                printf("\nEnter last name passenger.\n");
                printf("Search...\n");
                
                userString1 = (char*)malloc(LENGTH);
                tempString = (char*)malloc(LENGTH);
                inputUserString(userString1, LENGTH);
                
                conversionToUppercase(userString1);
                
                for (i = 0; i < numberOfPassenger; i++) {
                    strcpy(tempString, pointerToPassenger[i].lastname);
                    conversionToUppercase(tempString);
                    
                    if (strstr(tempString, userString1)) {
                        outputOneStructure(pointerToPassenger, i);
                        flag = 1;
                    }
                }
                
                free(userString1);
                free(tempString);
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
                
            case 2:
                printf("\nEnter number of flights.\n");
                printf("Search...\n");
                userVar = inputChoice();
                
                for (i = 0; i < numberOfPassenger; i++) {
                    if (pointerToPassenger[i].numberOfFlights == userVar) {
                        outputOneStructure(pointerToPassenger, i);
                        printf("\n");
                        flag = 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
            
            case 3:
                printf("\nEnter number of minutes.\n");
                printf("Search...\n");
                userVar = inputChoice();
                
                for (i = 0; i < numberOfPassenger; i++) {
                    if (pointerToPassenger[i].unionVar.numberOfMinutes == userVar && pointerToPassenger[i].isChoiceUnion) {
                        outputOneStructure(pointerToPassenger, i);
                        printf("\n");
                        flag = 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
            
            case 4:
                char c;
                printf("\nEnter date of departure.\n");
                printf("Search...\n");
               
                length = LENGTH;
                userString1 = (char*)malloc(LENGTH);
                
                do {
                    rewind(stdin);
                    while ((c = getchar()) != '\n' && --length > 0) {
                        userString1[j++] = c;
                        if (c == '\n' || !isdigit(c)) {
                            printf("You are using prohibited items. Try to enter again.\n");
                            rewind(stdin);
                            j = 0;
                            length = LENGTH;
                        }
                    }
                } while (!j);
                
                for (i = 0; i < numberOfPassenger; i++) {
                    if (strstr(pointerToPassenger[i].unionVar.dateOfDeparture, userString1) && !pointerToPassenger[i].isChoiceUnion) {
                        outputOneStructure(pointerToPassenger, i);
                        printf("\n");
                        flag = 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
            
            case 5:
                printf("Your longest flight.\n");
                printf("Search...\n");
                
                for (i = 0; i < numberOfPassenger; i++) {
                    if (pointerToPassenger[i].isChoiceUnion && pointerToPassenger[i].unionVar.numberOfMinutes > maxNumberOfMinutes) {
                        maxNumberOfMinutes = pointerToPassenger[i].unionVar.numberOfMinutes;
                        iMax = i;
                    }
                }
                
                outputOneStructure(pointerToPassenger, iMax);
                break;
            
            case 6:
                return;
            
            default:
                printf("Choose another option\n");
                break;
        }
    }
}

void printOption () {
    printf("1 - Last name passenger.\n");
    printf("2 - Number of flights.\n");
    printf("3 - Number of minutes.\n");
    printf("4 - Date of departure.\n");
    printf("5 - Search for the longest flight.(additional task)\n");
    printf("6 - Finish work.\n");
}

void conversionToUppercase(char array[20]) {
    int j = 0;
    
    while (array[j]) {
        if (array[j] >= 'a' && array[j] <= 'z') {
            array[j] -= 32;
        }
        j++;
    }
}

void inputUserString(char *pointer, int length) {
    rewind(stdin);
    char c = '\0';
    
    while ((c = getchar()) != '\n' && --length > 0) {
        *pointer++ = c;
    }
    *pointer = '\0';
}

void deleteStructure(struct Passenger *pointerToPassenger, int &numberOfPassenger) {
    int i, choice, flag = 0, theConfirmation, check, userVar, length, j = 0;
    char *userString1 = NULL, *tempString = NULL;
    
    while (1) {
        printf("\nHow do you want to remove the flight?\n1 - Select flight\n2 - Enter flight information\n3 - Finish work.\n");
        
        choice = inputChoice();
        switch (choice) {
            case 1:
                for (i = 0 ; i < numberOfPassenger; i++) {
                    outputOneStructure(pointerToPassenger, i);
                }
                
                printf("\nSelect the flight number you want to delete.\n");
                
                do {
                    check = scanf("%d", &choice);
                    
                    if (check < 1 || ((choice - 1) < 0 || (choice - 1) >= numberOfPassenger)) {
                        printf("The number of this trip is not available.\n");
                        rewind(stdin);
                        continue;
                    }
                } while (check < 1 || ((choice - 1) < 0 || (choice - 1) >= numberOfPassenger ));
                choice -= 1;
                
                printf("\nAre you sure you want to delete?\n");
                theConfirmation = confirmation();
                
                if (theConfirmation == 2) {
                    break;
                }
                
                deleteOneStructure(pointerToPassenger, numberOfPassenger, choice);
                
                for (i = 0 ; i < numberOfPassenger; i++) {
                    outputOneStructure(pointerToPassenger, i);
                }
                
                
                break;
            
            case 2:
                printf("\nSelect the parameter that will be used to search for deletion.\n");
                printf("1 - Last name passenger.\n");
                printf("2 - Number of flights.\n");
                printf("3 - Number of minutes.\n");
                printf("4 - Date of departure.\n");
                printf("5 - Finish work.\n");
                
                do {
                    check = scanf("%d", &choice);
                    
                    if (check < 1 || choice < 1 || choice > 5) {
                        printf("Choose another option.\n");
                    }
                } while (check < 1 || choice < 1 || choice > 5);
                
                switch (choice) {
                    case 1:
                        printf("\nEnter last name passenger.\n");
                        printf("Search...\n");
                        
                        userString1 = (char*)malloc(LENGTH);
                        tempString = (char*)malloc(LENGTH);
                        inputUserString(userString1, LENGTH);
                        conversionToUppercase(userString1);
                        
                        
                        printf("\nAre you sure you want to delete?\n");
                        theConfirmation = confirmation();
                        
                        if (theConfirmation == 2) {
                            break;
                        }
                        
                        for (i = 0; i < numberOfPassenger; i++) {
                            strcpy(tempString, pointerToPassenger[i].lastname);
                            conversionToUppercase(tempString);
                            if (strstr(tempString, userString1)) {
                                deleteOneStructure(pointerToPassenger, numberOfPassenger, i);
                                flag = 1;
                            }
                        }
                        
                        free(userString1);
                        free(tempString);
                        
                        if (!flag) {
                            printf("Nothing found.\n");
                        }
                        
                        flag = 0;
                        break;
                    
                    case 2:
                        printf("\nEnter number of flights.\n");
                        printf("Search...\n");
                        userVar = inputChoice();
                        
                        printf("\nAre you sure you want to delete?\n");
                        theConfirmation = confirmation();
                        
                        if (theConfirmation == 2) {
                            break;
                        }
                        
                        for (i = 0; i < numberOfPassenger; i++) {
                            if (pointerToPassenger[i].numberOfFlights == userVar) {
                                deleteOneStructure(pointerToPassenger, numberOfPassenger, i);
                                printf("\n");
                                flag = 1;
                            }
                        }
                        
                        if (!flag) {
                            printf("Nothing found.\n");
                        }
                        
                        flag = 0;
                        break;
                        
                    case 3:
                        printf("\nEnter number of minutes.\n");
                        printf("Search...\n");
                        userVar = inputChoice();
                        
                        printf("\nAre you sure you want to delete?\n");
                        theConfirmation = confirmation();
                        
                        if (theConfirmation == 2) {
                            break;
                        }
                        
                        for (i = 0; i < numberOfPassenger; i++) {
                            if (pointerToPassenger[i].unionVar.numberOfMinutes == userVar && pointerToPassenger[i].isChoiceUnion) {
                                deleteOneStructure(pointerToPassenger, numberOfPassenger, i);
                                printf("\n");
                                flag = 1;
                            }
                        }
                        
                        if (!flag) {
                            printf("Nothing found.\n");
                        }
                        
                        flag = 0;
                        break;
                    
                    case 4:
                        printf("\nEnter date of departure.\n");
                        printf("Search...\n");
                        length = LENGTH;
                        char c;
                        userString1 = (char*)malloc(LENGTH);
                        
                        do {
                            rewind(stdin);
                            while ((c = getchar()) != '\n' && --length > 0) {
                                userString1[j++] = c;
                                if (c == '\n' || !isdigit(c)) {
                                    printf("You are using prohibited items. Try to enter again.\n");
                                    rewind(stdin);
                                    j = 0;
                                    length = LENGTH;
                                }
                            }
                        } while (!j);
                        
                        printf("\nAre you sure you want to delete?\n");
                        theConfirmation = confirmation();
                        
                        if (theConfirmation == 2) {
                            break;
                        }
                        
                        for (i = 0; i < numberOfPassenger; i++) {
                            if (strstr(pointerToPassenger[i].unionVar.dateOfDeparture, userString1) && !pointerToPassenger[i].isChoiceUnion) {
                                deleteOneStructure(pointerToPassenger, numberOfPassenger, i);
                                printf("\n");
                                flag = 1;
                            }
                        }
                        
                        if (!flag) {
                            printf("Nothing found.\n");
                        }
                        
                        flag = 0;
                        break;
                    
                    case 5:
                        return;
                    
                    default:
                        printf("Choose another option\n");
                        break;
                }
                
                break;
            
            case 3:
                return;
            
            default:
                printf("Choose another option\n");
                break;
                
        }
    }
}

void deleteOneStructure (struct Passenger *pointerToPassenger,int &numberOfPassenger ,int index) {
    if (index != numberOfPassenger - 1) {
        for (; index < numberOfPassenger; index++) {
            pointerToPassenger[index] = pointerToPassenger[index + 1];
        }
        numberOfPassenger--;
        pointerToPassenger = (struct Passenger*)realloc(pointerToPassenger, numberOfPassenger * sizeof(struct Passenger));
    }
    if (index == numberOfPassenger - 1) {
        numberOfPassenger--;
        pointerToPassenger = (struct Passenger*)realloc(pointerToPassenger, numberOfPassenger * sizeof(struct Passenger));
    }
}

int confirmation () {
    int choice = 0, check = 0;
    printf("1 - yes.\n2 - no.\n");
    
    do {
        check = scanf("%d", &choice);
        
        if (check < 1 || choice < 1 || choice > 2) {
            printf("Choose another item. Try to enter again.\n");
            rewind(stdin);
            continue;
        }
    }while(check < 1 || choice < 1 || choice > 2);
    
    return choice;
}

void addInformation (struct Passenger* pointerToPassenger, int &numberOfPassenger, int &oldValue) {
    int choice;
    
    printf("\nEnter the number of new flights.\n");
    choice = inputChoice();
    numberOfPassenger += choice;
    
    pointerToPassenger = (struct Passenger*)realloc(pointerToPassenger, numberOfPassenger * sizeof(struct Passenger));
    
    printf("\nEnter new information.\n");
    for (; oldValue < numberOfPassenger; oldValue++) {
        inputInformation(pointerToPassenger, oldValue);
    }
}
