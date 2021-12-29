#include "Functions.hpp"
#define MINUTES 60

int menu (void) {
    int tempMenu = 0, flag = 0, check;
    
    printf("\nEnter number for change.\n");
    printf("1 - Enter your data.\n");
    printf("2 - Output your data.\n");
    printf("3 - Change your data.\n");
    printf("4 - Search selected field.\n");
    printf("5 - Sort your data.\n");
    printf("6 - Delete selected field.\n");
    printf("7 - Search...\n");
    printf("8 - To finish work.\n");
    
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

void outputInformation (struct RailwayStation OneStructure) {
    printf(" 1 - your days on the trip: %d\n", OneStructure.days);
    printf(" 2 - your train number: %d\n", OneStructure.trainNumber);
    printf(" 3 - your destination: %s", OneStructure.destination);
    printf(" 4 - your arrive time: %d:%d\n", OneStructure.arrivalTime.hours, OneStructure.arrivalTime.minutes);
    printf(" 5 - your parking time: %d:%d\n", OneStructure.parkingTime.hours, OneStructure.parkingTime.minutes);
    printf("\n");
}

void chengeInformation (struct RailwayStation *OneStructure, int numberOfStructure) {
    int choice, check, i = 0, fieldSelection, theConfirmation;
    
    if (!OneStructure) {
        printf("You have not entered information.\n");
        return;
    }
    
    do {
        printf("How do you to chenge?\n1 - Partially.\n2 - Fully.\n3 - To finish work.\n");
        
        choice = inputChoice();

        switch (choice) {
            case 1:
                
                for (i = 0; i < numberOfStructure; i++) {
                    printf("%d trip information.\n", i + 1);
                    outputInformation(OneStructure[i]);
                    
                }
                
                printf("On which trip do you want to make the change?\n");
                
                choice = inputIndex(numberOfStructure);
                
                printf("what information do you want to change?\n");
                outputInformation(OneStructure[choice]);
                printf(" 6 - Finish work.\n");
                
                fieldSelection = inputParametr();
                
                printf("Are you sure you want to change?\n");
                theConfirmation = confirmation();
                
                if (theConfirmation == 2) {
                    break;
                }
                
                switch (fieldSelection) {
                    case 1:
                        inputTripDays(OneStructure, choice);
                        break;
                        
                    case 2:
                        inputTrainNumber(OneStructure, choice);
                        break;
                        
                    case 3:
                        inputDestination(OneStructure, choice);
                        break;
                        
                    case 4:
                        inputArrivalTime(OneStructure, choice);
                        break;
                        
                    case 5:
                        inputParkingTime(OneStructure, choice);
                        break;
                        
                    case 6:
                        break;
                        
                    default:
                        printf("Choose another option.\n");
                        break;
                }
                break;
            case 2:
                
                for (i = 0; i < numberOfStructure; i++) {
                    printf("%d trip information\n", i + 1);
                    outputInformation(OneStructure[i]);
                }
                
                printf("On which trip do you want to make the change?\n");
                
                do {
                    check = scanf("%d", &choice);
                    
                    if (check < 1 || ((choice - 1) < 0 || (choice - 1) >= numberOfStructure )) {
                        printf("The number of this trip is not available.\n");
                        rewind(stdin);
                        continue;
                    }
                } while (check < 1 || ((choice - 1) < 0 || (choice - 1) >= numberOfStructure ));
                
                choice -= 1;
                
                printf("Are you sure you want to change?\n");
                theConfirmation = confirmation();
                
                if (theConfirmation == 2) {
                    break;
                }
                
                inputTripDays(OneStructure, choice);
                inputTrainNumber(OneStructure, choice);
                inputDestination(OneStructure, choice);
                inputArrivalTime(OneStructure, choice);
                inputParkingTime(OneStructure, choice);
                break;
            
            case 3:
                return;
            
            default:
                printf("Choose another option.\n");
                break;
        }
    } while (1);
}

void inputTripDays (struct RailwayStation *oneStructure, int i) {
    printf("Enter days %d trip.\n", i + 1);
    oneStructure[i].days = inputChoice();
}

void inputTrainNumber (struct RailwayStation *oneStructure, int i) {
    printf("Enter %d train number.\n", i + 1);
    oneStructure[i].trainNumber = inputChoice();
}

void inputDestination (struct RailwayStation *oneStructure, int i) {
    int length = 50;
    int j;
    char c;
    do {
        j = 0;
        printf("Enter destination %d trip.\n", i + 1);
        length = 50;
        rewind(stdin);
        while ((c = getchar()) != '\n' && --length > 0) {
            oneStructure[i].destination[j++] = c;
        }
        for (j = 0; oneStructure[i].destination[j]; j++) {
            if ( ((oneStructure[i].destination[j]) < 'a' || (oneStructure[i].destination[j]) > 'z') && ((oneStructure[i].destination[j]) < 'A' || (oneStructure[i].destination[j]) > 'Z')) {
                printf("You are using prohibited items. Try to enter again.\n");
                rewind(stdin);
                for (j = 0; oneStructure[i].destination[j]; j++) {
                    oneStructure[i].destination[j] = '\0';
                }
                break;
            }
        }
    } while(((oneStructure[i].destination[0])  == '\0') || ((oneStructure[i].destination[j]) >= '0' && (oneStructure[i].destination[j]) <= '9'));
    oneStructure[i].destination[j++] = '\n';
    oneStructure[i].destination[j] = '\0';
}
void inputArrivalTime (struct RailwayStation *oneStructure, int i) {
    printf("Enter what time you will arrive(hours) %d trip.\n", i + 1);
    oneStructure[i].arrivalTime.hours = inputHours();
    
    printf("Enter what time you will arrive(minutes) %d trip.\n", i + 1);
    oneStructure[i].arrivalTime.minutes = inputMinutes();
}

void inputParkingTime (struct RailwayStation *oneStructure, int i) {
    printf("Enter parking time(hours) %d trip.\n", i + 1);
    oneStructure[i].parkingTime.hours = inputHours();
    
    printf("Enter parking time(minutes) %d trip.\n", i + 1);
    oneStructure[i].parkingTime.minutes = inputMinutes();
}


void searchSelectedField (struct RailwayStation *pointerToStructures, int numberOfStructure) {
    int i, flag = 0, choice = 0;
    int tempMinutes, tempHours, userVariable;
    char userString2[50], userString[50], tempString[50];
    
    if (!pointerToStructures) {
        printf("You have not entered information.\n");
        return;
    }
    
    while (1) {
        printf("\nSelect the parameter by which the search will go.\n");
        printOption();
        choice = inputChoice();
        
        switch (choice) {
            case 1:
                printf("Search for days...\n");
                printf("Enter days.\n");
                userVariable = inputChoice();
                
                for (i = 0; i < numberOfStructure; i++) {
                    if (pointerToStructures[i].days == userVariable) {
                        outputInformation(pointerToStructures[i]);
                        printf("\n");
                        flag += 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
                
            case 2:
                printf("Search for train number...\n");
                printf("Enter train number.\n");
                userVariable = inputChoice();
                
                for (i = 0; i < numberOfStructure; i++) {
                    if (pointerToStructures[i].trainNumber == userVariable) {
                        outputInformation(pointerToStructures[i]);
                        printf("\n");
                        flag += 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
            
            case 3:
                printf("Search destination...\n");
                printf("Enter destination.\n");
                rewind(stdin);
                userString[0] = '\n';
                
                while (userString[0] == '\n') {
                    fgets(userString, 50, stdin);
                    if (userString[0] == '\n') {
                        printf("Enter destination again.\n");
                        rewind(stdin);
                        continue;
                    }
                }
                
                strcpy(userString2, userString);
                conversionToUppercase(userString2);
                
                for (i = 0; i < numberOfStructure; i++) {
                    strcpy(tempString, pointerToStructures[i].destination);
                    conversionToUppercase(tempString);
                    
                    if (!strcmp(userString2, tempString)) {
                        outputInformation(pointerToStructures[i]);
                        printf("\n");
                        flag += 1;
                    }
                    tempString[0] = '\0';
                }
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
                
            case 4:
                printf("Search arrival time...\n");
                printf("Enter what time you will arrive(hours) trip.\n");
                tempHours = inputHours();
                
                printf("Enter what time you will arrive(minutes) trip.\n");
                tempMinutes = inputMinutes();
                
                for (i = 0; i < numberOfStructure; i++) {
                    if (pointerToStructures[i].arrivalTime.hours == tempHours && pointerToStructures[i].arrivalTime.minutes == tempMinutes) {
                        outputInformation(pointerToStructures[i]);
                        printf("\n");
                        flag += 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
            
            case 5:
                printf("Search parking time.\n");
                printf("Enter what time you will arrive(hours) trip.\n");
                tempHours = inputHours();
                
                printf("Enter what time you will arrive(minutes) trip.\n");
                tempMinutes = inputMinutes();
                
                for (i = 0; i < numberOfStructure; i++) {
                    if (pointerToStructures[i].parkingTime.hours == tempHours && pointerToStructures[i].parkingTime.minutes == tempMinutes) {
                        outputInformation(pointerToStructures[i]);
                        printf("\n");
                        flag += 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found.\n");
                }
                
                flag = 0;
                break;
            
            case 6:
                return;
            
            default:
                printf("Choose another option\n");
                break;
        }
    }
}

void sortPointer (struct RailwayStation *pointerToStructure, int numberOfStructure) {
    if (!pointerToStructure) {
        printf("You have not entered information.\n");
        return;
    }
    
    struct RailwayStation temp;
    int choice, check, typeSorting = 0;
    int i, j;
    
    while (1) {
        printf("\nSelect the parameter to sort by.\n");
        printOption();
        choice = inputParametr();
        rewind(stdin);
        if (choice < 6) {
            printf("\nHow do you want to sort?\n 1 - Ascending.\n 2 - Descending.\n");
            
            do {
                check = scanf("%d", &typeSorting);
                
                if (check < 1 || typeSorting < 1 || typeSorting > 2) {
                    printf("Choose another option.\n");
                    rewind(stdin);
                    continue;
                }
            } while(check < 1 || typeSorting < 1 || typeSorting > 2);
        }
        
        switch (choice) {
            case 1:
                for (i = 0; i < numberOfStructure; i++) {
                    for (j = numberOfStructure - 1; j > i; j--) {
                        if ((pointerToStructure[j - 1].days > pointerToStructure[j].days && typeSorting == 1) || (pointerToStructure[j - 1].days < pointerToStructure[j].days && typeSorting == 2)) {
                            
                            temp = pointerToStructure[j];
                            pointerToStructure[j] = pointerToStructure[j - 1];
                            pointerToStructure[j - 1] = temp;
                        }
                    }
                }
                
                for (i = 0; i < numberOfStructure; i++) {
                    outputInformation(pointerToStructure[i]);
                    printf("\n");
                }
                break;
            
            case 2:
                for (i = 0; i < numberOfStructure; i++) {
                    for (j = numberOfStructure - 1; j > i; j--) {
                        if ((pointerToStructure[j - 1].trainNumber > pointerToStructure[j].trainNumber && typeSorting == 1) || (pointerToStructure[j - 1].trainNumber < pointerToStructure[j].trainNumber && typeSorting == 2)) {
                            
                            temp = pointerToStructure[j];
                            pointerToStructure[j] = pointerToStructure[j - 1];
                            pointerToStructure[j - 1] = temp;
                        }
                    }
                }
                
                for (i = 0; i < numberOfStructure; i++) {
                    outputInformation(pointerToStructure[i]);
                    printf("\n");
                }
                break;
            
            case 3:
                for (i = 0; i < numberOfStructure; i++) {
                    for (j = numberOfStructure - 1; j > i; j--) {
                        if ((strcmp(pointerToStructure[j].destination, pointerToStructure[j - 1].destination) < 0 && typeSorting == 1) || (strcmp(pointerToStructure[j].destination, pointerToStructure[j - 1].destination) > 0 && typeSorting == 2)) {
                            
                            temp = pointerToStructure[j];
                            pointerToStructure[j] = pointerToStructure[j - 1];
                            pointerToStructure[j - 1] = temp;
                        }
                    }
                }
                
                for (i = 0; i < numberOfStructure; i++) {
                    outputInformation(pointerToStructure[i]);
                    printf("\n");
                }
                break;
            
            case 4:
                for (i = 0; i < numberOfStructure; i++) {
                    for (j = numberOfStructure - 1; j > i; j--) {
                        if (((pointerToStructure[j].arrivalTime.hours * MINUTES + pointerToStructure[j].arrivalTime.minutes) < (pointerToStructure[j - 1].arrivalTime.hours * MINUTES + pointerToStructure[j - 1].arrivalTime.minutes) && typeSorting == 1) || ((pointerToStructure[j].arrivalTime.hours * MINUTES + pointerToStructure[j].arrivalTime.minutes) > (pointerToStructure[j - 1].arrivalTime.hours * MINUTES + pointerToStructure[j - 1].arrivalTime.minutes) && typeSorting == 2)) {
                            
                            temp = pointerToStructure[j];
                            pointerToStructure[j] = pointerToStructure[j - 1];
                            pointerToStructure[j - 1] = temp;
                        }
                    }
                }
                
                for (i = 0; i < numberOfStructure; i++) {
                    outputInformation(pointerToStructure[i]);
                    printf("\n");
                }
                break;
            
            case 5:
                for (i = 0; i < numberOfStructure; i++) {
                    for (j = numberOfStructure - 1; j > i; j--) {
                        if (((pointerToStructure[j].parkingTime.hours * MINUTES + pointerToStructure[j].parkingTime.minutes) < (pointerToStructure[j - 1].parkingTime.hours * MINUTES + pointerToStructure[j - 1].parkingTime.minutes) && typeSorting == 1) || ((pointerToStructure[j].parkingTime.hours * MINUTES + pointerToStructure[j].parkingTime.minutes) > (pointerToStructure[j - 1].parkingTime.hours * MINUTES + pointerToStructure[j - 1].parkingTime.minutes) && typeSorting == 2)) {
                            
                            temp = pointerToStructure[j];
                            pointerToStructure[j] = pointerToStructure[j - 1];
                            pointerToStructure[j - 1] = temp;
                            
                        }
                    }
                }
                
                for (i = 0; i < numberOfStructure; i++) {
                    outputInformation(pointerToStructure[i]);
                    printf("\n");
                }
                break;
            
            case 6:
                return;
            
            default:
                printf("Choose another option\n");
                break;
        }
    }
}

void deleteStructure(struct RailwayStation* pointerToStructures, int &numberOfStructure) {
    int i, check, choice, theConfirmation;
    int tempMinutes, tempHours, userVariable;
    char userString2[50], userString[50], tempString[50];
    
    while (1) {
        if (pointerToStructures == NULL) {
            printf("You have not entered information.\n");
            return;
        }
        
        printf("How do you want to remove the structure?\n 1 - Select trip\n 2 - Enter trip information\n 3 - Finish work.\n");
        
        choice = inputChoice();
        switch (choice) {
            case 1:
                for (i = 0; i < numberOfStructure; i++) {
                    printf("%d trip information.\n", i + 1);
                    outputInformation(pointerToStructures[i]);
                }
                
                printf("Which trip do you want to delete?\n");
                
                do {
                    check = scanf("%d", &choice);
                    
                    if (check < 1 || ((choice - 1) < 0 || (choice - 1) >= numberOfStructure)) {
                        printf("The number of this trip is not available.\n");
                        rewind(stdin);
                        continue;
                    }
                } while (check < 1 || ((choice - 1) < 0 || (choice - 1) >= numberOfStructure ));
                choice -= 1;
                
                printf("Are you sure you want to delete?\n");
                theConfirmation = confirmation();
                
                if (theConfirmation == 2) {
                    break;
                }
                
                deleteOneStructure(pointerToStructures, numberOfStructure, choice);
                
                if (numberOfStructure == 0) {
                    pointerToStructures = NULL;
                }
                
                break;
            case 2:
                printf("Select the parameter that will be used to search for deletion.\n");
                printOption();
                
                choice = inputParametr();
                
                printf("Are you sure you want to delete?\n");
                theConfirmation = confirmation();
                
                if (theConfirmation == 2) {
                    break;
                }
                
                switch (choice) {
                    case 1:
                        printf("Enter days.\n");
                        userVariable = inputChoice();
                        
                        for (i = 0; i < numberOfStructure; i++) {
                            if (pointerToStructures[i].days == userVariable) {
                                deleteOneStructure(pointerToStructures, numberOfStructure, i);
                            }
                        }
                        
                        if (numberOfStructure == 0) {
                            pointerToStructures = NULL;
                        }
                        
                        break;
                    case 2:
                        printf("Enter train number.\n");
                        userVariable = inputChoice();
                        
                        for (i = 0; i < numberOfStructure; i++) {
                            if (pointerToStructures[i].trainNumber == userVariable) {
                                deleteOneStructure(pointerToStructures, numberOfStructure, i);
                            }
                        }
                        
                        if (numberOfStructure == 0) {
                            pointerToStructures = NULL;
                        }
                        
                        break;
                    
                    case 3:
                        printf("Enter destination.\n");
                        rewind(stdin);
                        userString[0] = '\n';
                        
                        while (userString[0] == '\n') {
                            fgets(userString, 50, stdin);
                            if (userString[0] == '\n') {
                                printf("Enter destination again.\n");
                                rewind(stdin);
                                continue;
                            }
                        }
                        
                        strcpy(userString2, userString);
                        conversionToUppercase(userString2);
                        
                        for (i = 0; i < numberOfStructure; i++) {
                            strcpy(tempString, pointerToStructures[i].destination);
                            conversionToUppercase(tempString);
                            if (!strcmp(userString2, tempString)) {
                                deleteOneStructure(pointerToStructures, numberOfStructure, i);
                            }
                            tempString[0] = '\0';
                        }
                        
                        if (numberOfStructure == 0) {
                            pointerToStructures = NULL;
                        }
                        
                        break;
                    
                    case 4:
                        printf("Enter arrival time(hours).\n");
                        rewind(stdin);
                        tempHours = inputHours();
                        
                        printf("Enter arrival time(minutes).\n");
                        rewind(stdin);
                        tempMinutes = inputMinutes();
                        
                        for (i = 0; i < numberOfStructure; i++) {
                            if (pointerToStructures[i].arrivalTime.hours == tempHours && pointerToStructures[i].arrivalTime.minutes == tempMinutes) {
                                deleteOneStructure(pointerToStructures, numberOfStructure, i);
                            }
                        }
                        
                        if (numberOfStructure == 0) {
                            pointerToStructures = NULL;
                        }
                        
                        break;
                    
                    case 5:
                        printf("Enter parkimg time(hours).\n");
                        rewind(stdin);
                        tempHours = inputHours();
                        
                        printf("Enter parking time(minutes).\n");
                        rewind(stdin);
                        tempMinutes = inputMinutes();
                        
                        for (i = 0; i < numberOfStructure; i++) {
                            if (pointerToStructures[i].parkingTime.hours == tempHours && pointerToStructures[i].parkingTime.minutes == tempMinutes) {
                                deleteOneStructure(pointerToStructures, numberOfStructure, i);
                            }
                        }
                        
                        if (numberOfStructure == 0) {
                            pointerToStructures = NULL;
                        }
                        
                        break;
                   
                    case 6:
                        return;
                    
                    default:
                        printf("Choose another option.\n");
                        break;
                }
                break;
            
            case 3:
                return;
            
            default:
                printf("Choose another option.\n");
                break;
        }
    }
}


void conversionToUppercase(char array[50]) {
    int j = 0;
    while (array[j]) {
        if (array[j] >= 'a' && array[j] <= 'z') {
            array[j] -= 32;
        }
        j++;
    }
}


void printOption () {
    printf("1 - Days in trip.\n");
    printf("2 - Train number.\n");
    printf("3 - Destination.\n");
    printf("4 - Arrive time.\n");
    printf("5 - Parking time.\n");
    printf("6 - Finish work.\n");
}

void deleteOneStructure (struct RailwayStation *pointerToStructures, int &numberOfStructure, int i) {
    
    
    if (i != numberOfStructure - 1) {
        for (; i < numberOfStructure; i++) {
            pointerToStructures[i] = pointerToStructures[i + 1];
        }
        numberOfStructure--;
        pointerToStructures = (struct RailwayStation*)realloc(pointerToStructures, numberOfStructure * sizeof(struct RailwayStation));
    }
    
    if (i == numberOfStructure - 1) {
        numberOfStructure--;
        pointerToStructures = (struct RailwayStation*)realloc(pointerToStructures, numberOfStructure * sizeof(struct RailwayStation));
    }
    
    
}

void partialSearch (struct RailwayStation *pointerToStructure, int numberOfStructure) {
    
    if (!pointerToStructure) {
        printf("You have not entered information.\n");
        return;
    }
    
    int length = 50, flag = 0;
    int choice, i;
    int tempHours, tempMinutes;
    
    while (1) {
        printf("\nSelect the parameter by which the search will go.\n");
        printf(" 1 - destination.\n 2 - arrive time.\n 3 - parking time.\n 4 - End search\n");
        choice = inputChoice();
        switch (choice) {
            case 1:
                char *userString, *temp;
                printf("Enter part of the string.\n");
                userString = (char*)malloc(length);
                temp = (char*)malloc(length);
                inputUserString(userString, length);
                
                conversionToUppercase(userString);
                
                for (i = 0; i < numberOfStructure; i++) {
                    strcpy(temp, pointerToStructure[i].destination);
                    conversionToUppercase(temp);
                    if (strstr(temp, userString)) {
                        outputInformation(pointerToStructure[i]);
                        flag = 1;
                    }
                }
                
                free(userString);
                free(temp);
                
                if (!flag) {
                    printf("Nothing found!\n");
                }
                
                break;
                
            case 2:
                printf("Enter arrival time(hours).\n");
                rewind(stdin);
                tempHours = inputHours();
                
                printf("Enter arrival time(minutes).\n");
                rewind(stdin);
                tempMinutes = inputMinutes();
                
                for (i = 0; i < numberOfStructure; i++) {
                    if (tempHours == pointerToStructure[i].arrivalTime.hours || tempMinutes == pointerToStructure[i].arrivalTime.minutes) {
                        
                        outputInformation(pointerToStructure[i]);
                        flag = 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found!\n");
                }
                
                break;
                
            case 3:
                printf("Enter arrival time(hours).\n");
                rewind(stdin);
                tempHours = inputHours();
                
                printf("Enter arrival time(minutes).\n");
                rewind(stdin);
                tempMinutes = inputMinutes();
                
                for (i = 0; i < numberOfStructure; i++) {
                    if (tempHours == pointerToStructure[i].parkingTime.hours || tempMinutes == pointerToStructure[i].parkingTime.minutes) {
                        
                        outputInformation(pointerToStructure[i]);
                        flag = 1;
                    }
                }
                
                if (!flag) {
                    printf("Nothing found!\n");
                }
                
                break;
                
            case 4:
                return;
                
            default:
                printf("Choose another option.\n");
                break;
        }
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

int inputParametr () {
    int fieldSelection, check;
    rewind(stdin);
    
    do {
        check = scanf("%d", &fieldSelection);
        
        if (parametrCheck(check, fieldSelection)) {
            printf("There is no such number. Try to enter again.\n");
            rewind(stdin);
            continue;
        }
    }while (parametrCheck(check, fieldSelection));
    
    return fieldSelection;
}

int inputHours () {
    int tempHours, check;
    rewind(stdin);
    
    do {
        check = scanf("%d", &tempHours);
        
        if (timeCheckingHours(check, tempHours)) {
            printf("Oops, something went wrong. Try to enter again.\n");
            rewind(stdin);
            continue;
        }
    }while(timeCheckingHours(check, tempHours));
    
    return tempHours;
}

int inputMinutes () {
    int tempMinutes, check;
    rewind(stdin);
    
    do {
        check = scanf("%d", &tempMinutes);
        
        if (timeCheckingMinutes(check, tempMinutes)) {
            printf("Oops, something went wrong. Try to enter again.\n");
            rewind(stdin);
            continue;
        }
    } while (timeCheckingMinutes(check, tempMinutes));
    
    return tempMinutes;
}

int inputIndex (int numberOfStructure) {
    int check, choice;
    
    do {
        check = scanf("%d", &choice);
        
        if (check < 1 || ((choice - 1) < 0 || (choice - 1) >= numberOfStructure )) {
            printf("The number of this trip is not available. Try to enter again.\n");
            rewind(stdin);
            continue;
        }
    } while (check < 1 || ((choice - 1) < 0 || (choice - 1) >= numberOfStructure ));
    
    choice -= 1;
    return choice;
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
