#include "functions.hpp"
#define FILESIZE 20


int push(struct Passenger **topOfStack) {
    static int countNode;
    struct Passenger *temp = *topOfStack;
    int sizeLastname, check, choice;
    char c;
    
    do {
        if (!(*topOfStack = (struct Passenger*)calloc(1, sizeof(struct Passenger)))) {
            printf("Out of memory on your device.\n");
            return 0;
        }
        
        printf("\nEnter number of flight.\n");
        (*topOfStack) -> numberOfFlight = inputChoice();
        
        do {
            printf("\nEnter size lastname.\n");
            (*topOfStack) -> lastname = NULL;
            sizeLastname = inputChoice();
            if (!((*topOfStack) -> lastname = (char*)malloc(sizeLastname * sizeof(char)))) {
                printf("Out of memory on your device.\n");
                continue;
            }
        }while (!((*topOfStack) -> lastname));
        printf("\nEnter lastname.\n");
        correctInput(((*topOfStack) -> lastname), sizeLastname);
        
        printf("\nSelect one information you want to enter.\n1 - Number of minutes on the way.\n2 - Date of departure.\n");
        do {
            check = scanf("%d", &choice);
            
            if (check < 1 || choice < 1 || choice > 2) {
                rewind(stdin);
                printf("\nChoose another item.\n");
                continue;
            }
        }while (check < 1 || choice < 1 || choice > 2);
        
        if (choice == 1) {
            (*topOfStack) -> choiceUnion = true;
        }
        
        if (choice == 2) {
            (*topOfStack) -> choiceUnion = false;
        }
        
        if ((*topOfStack) -> choiceUnion == true) {
            printf("\nEnter number of minutes.\n");
            (*topOfStack) -> unionVar.numberOfMinutes = inputChoice();
        }
        
        else if ((*topOfStack) -> choiceUnion == false) {
            printf("\nEnter date of departure flight.\n");
            int j = 0;
            int length = 20;
            do {
                rewind(stdin);
                while ((c = getchar()) != '\n' && --length > 0) {
                    (*topOfStack) -> unionVar.dataOfDeparture[j++] = c;
                    if (c == '\n' || !isdigit(c)) {
                        printf("You are using prohibited items. Try to enter again.\n");
                        rewind(stdin);
                        j = 0;
                        length = 20;
                    }
                }
            } while (j == 0);
            
            (*topOfStack) -> unionVar.dataOfDeparture[j++] = '\n';
            (*topOfStack) -> unionVar.dataOfDeparture[j] = '\0';
        }
        
        (*topOfStack) -> pointer = temp;
        temp = (*topOfStack);
        countNode++;
        
        printf("Continue? (y - yes, n - no)\n");
        rewind(stdin);
        c = getchar();
    }while(c == 'y');
    
    return countNode;
}

int menu () {
    int tempMenu = 0, flag = 0, check;
    
    printf("Enter number for change.\n");
    printf("1 - Adding information.\n");
    printf("2 - Output information.\n");
    printf("3 - Deletion of information\n");
    printf("4 - Search information.\n");
    printf("5 - Save information in file.\n");
    printf("6 - Load from file.\n");
    printf("7 - To finish work.\n");
    
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

void output (struct Passenger* nodeStack, int numberOfNode) {
    int choice, check;
    
    if( nodeStack == NULL) {
        printf("First enter information.\n");
        return;
    }
    
    while (1) {
        printf("\nDisplay:\n1 - Choose passenger\n2 - All passenger\n3 - Exit\n\nYour choice: ");
        choice = inputChoice();
        
        switch (choice) {
            case 1:
                printf("Select number.\n (from 1 to %d)", numberOfNode);
                
                do {
                    check = scanf("%d", &choice);
                    
                    if (check < 1 || choice < 0 || choice >= numberOfNode) {
                        rewind(stdin);
                        printf("Choose another item.\n");
                        continue;
                    }
                }while (check < 1 || choice < 0 || choice > numberOfNode);
                choice -= 1;
                
                printf("-----------------------------------------------------------------------------------------\n");
                printf("| № | number of flights | last name           | number of minutes | check out date      |\n");
                outputOneStructure(nodeStack, choice);
                
                break;
                
            case 2:
                printf("-----------------------------------------------------------------------------------------\n");
                printf("| № | number of flights | last name           | number of minutes | check out date      |\n");
                
                for (choice = 0; nodeStack; nodeStack = nodeStack -> pointer, choice++) {
                    outputOneStructure(nodeStack, choice);
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

void outputOneStructure (struct Passenger* nodeStack, int index) {
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| %d |", index + 1);
    printf(" %-6d            | ", nodeStack -> numberOfFlight);
    printNormalString(nodeStack -> lastname);
    
    if (nodeStack -> choiceUnion) {
        printf(" %-6d           | ------------------- |\n", nodeStack -> unionVar.numberOfMinutes);
    }
    
    if (!nodeStack -> choiceUnion) {
        printf("----------------- | ");
        printNormalString(nodeStack ->unionVar.dataOfDeparture);
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


void search(struct Passenger *nodeStack, int numberOfNode) {
    int choice, flag = 0, length, j = 0, userVar;
    char *userString1 = NULL, *tempString = NULL;
    struct Passenger *temp = nodeStack;
    
    if (!nodeStack) {
        printf("First enter information.\n");
        return;
    }
    
    do {
        printf("\nSelect the parameter by which the search will go.\n");
        printf("1 - Last name passenger.\n");
        printf("2 - Number of flights.\n");
        printf("3 - Number of minutes.\n");
        printf("4 - Date of departure.\n");
        printf("5 - Finish work.\n");
        
        choice = inputChoice();
        switch (choice) {
            case 1:
                printf("\nEnter last name passenger.\n");
                printf("Search...\n");
                
                userString1 = (char*)malloc(20);
                tempString = (char*)malloc(20);
                inputUserString(userString1, 20);
                
                conversionToUppercase(userString1);
                
                for (choice = 0, temp = nodeStack; temp && choice < numberOfNode; temp = temp -> pointer, choice++) {
                    strcpy(tempString, temp -> lastname);
                    conversionToUppercase(tempString);
                    
                    if (strstr(tempString, userString1)) {
                        outputOneStructure(temp, choice);
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
                
                for (choice = 0, temp = nodeStack; temp && choice < numberOfNode; temp = temp -> pointer, choice++) {
                    if (temp -> numberOfFlight == userVar) {
                        outputOneStructure(temp, choice);
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
                
                for (choice = 0, temp = nodeStack; temp && choice < numberOfNode; temp = temp -> pointer, choice++) {
                    if (temp -> unionVar.numberOfMinutes == userVar && temp -> choiceUnion) {
                        outputOneStructure(temp, choice);
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
                
                length = 20;
                userString1 = (char*)malloc(20);
                
                do {
                    rewind(stdin);
                    while ((c = getchar()) != '\n' && --length > 0) {
                        userString1[j++] = c;
                        if (c == '\n' || !isdigit(c)) {
                            printf("You are using prohibited items. Try to enter again.\n");
                            rewind(stdin);
                            j = 0;
                            length = 20;
                        }
                    }
                } while (!j);
                
                for (choice = 0, temp = nodeStack; temp && choice < numberOfNode; temp = temp -> pointer, choice++) {
                    if (strstr(temp -> unionVar.dataOfDeparture, userString1) && !temp -> choiceUnion) {
                        outputOneStructure(temp, choice);
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
                printf("Choose another option.\n");
                break;
        }
    }while (1);
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


void deleteNode(struct Passenger **topOfStack, int numberOfNode, int numberOfNodeDelete) {
    int i;
    struct Passenger *deleteNode = *topOfStack, *temp = *topOfStack;
    
    if (*topOfStack == NULL) {
        printf("First enter information.\n");
        return;
    }
    
    deleteNode = *topOfStack;
    for (i = 1; i < numberOfNodeDelete && deleteNode != nullptr; i++) {
        deleteNode = deleteNode -> pointer;
    }
    
    if (deleteNode == *topOfStack) {
        *topOfStack = (*topOfStack) -> pointer;
        free(deleteNode);
    }
    else {
        while (temp -> pointer != deleteNode) {
            temp = temp -> pointer;
        }
        temp -> pointer = deleteNode -> pointer;
        free(deleteNode);
    }
}

void inputFileName (char* pointer, int length) {
    char c;
    int i = 0, tempLength = length;
    
    while (pointer[i]) {
        pointer[i++] = '\0';
    }
    i = 0;
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

void saveInFile (struct Passenger *topOfStack) {
    char fileName[FILESIZE], c = ' ';
    int check, typeFile, i = 0;
    struct Passenger *temp = topOfStack;
    FILE *file;
    
    if (!topOfStack) {
        printf("First enter information.\n");
        return;
    }
    
    while (1) {
        printf("\nChoose File to save List in\n");
        printf("1 - Text file.\n");
        printf("2 - Binary file.\n");
        printf("3 - Finish work.\n");
        
        do {
            check = scanf("%d", &typeFile);
            if (check < 1 || typeFile < 1 || typeFile > 3) {
                rewind(stdin);
                printf("There is no such number. Try to enter again.\n");
                continue;
            }
        }while (check < 1 || typeFile < 1 || typeFile > 3);
        
        switch (typeFile) {
            case 1:
                temp = topOfStack;
                printf("\nEnter name of .txt File.\n");
                inputFileName(fileName, FILESIZE - 5);
                strcat(fileName, ".txt");
                
                if (!(file = fopen(fileName, "w"))) {
                    printf("File not found\n.");
                    return;
                }
                
                while (temp) {
                    fprintf(file, "%d", temp -> numberOfFlight);
                    fprintf(file, "%c", ' ');
                    
                    if (temp -> choiceUnion) {
                        fprintf(file, "%d", 1);
                        fprintf(file, "%c", ' ');
                        fprintf(file, "%d", temp -> unionVar.numberOfMinutes);
                    }
                    
                    else {
                        fprintf(file, "%d", 0);
                        fprintf(file, "%c", ' ');
                        i = 0;
                        while (temp -> unionVar.dataOfDeparture[i] != '\n') {
                            fprintf(file, "%c", temp -> unionVar.dataOfDeparture[i]);
                            i++;
                        }
                    }
                    
                    fprintf(file, "%c", ' ');
                    i = 0;
                    
                    while (temp -> lastname[i]) {
                        i++;
                    }
                    
                    i++;
                    fprintf(file, "%d", i);
                    fprintf(file, "%c", ' ');
                    
                    
                    for (int j = 0;j < i; j++) {
                        fprintf(file, "%c", temp -> lastname[j]);
                    }
                    temp = temp -> pointer;
                }
                
                fclose(file);
                break;
            
            case 2:
                temp = topOfStack;
                printf("Enter name of .bin File.\n");
                inputFileName(fileName, FILESIZE - 5);
                strcat(fileName, ".bin");
                
                if (!(file = fopen(fileName, "w + b"))) {
                    printf("File not found\n.");
                    return;
                }
                
                while (temp) {
                    fwrite(&(temp ->numberOfFlight), sizeof(int), 1, file);
                    fwrite(&c, sizeof(char), 1, file);
                    
                    if (temp -> choiceUnion) {
                        i = 1;
                        fwrite(&i, sizeof(int), 1, file);
                        fwrite(&c, sizeof(char), 1, file);
                        fwrite(&(temp -> unionVar.numberOfMinutes), sizeof(int), 1, file);
                        fwrite(&c, sizeof(char), 1, file);
                    }
                    
                    else {
                        i = 0;
                        fwrite(&i, sizeof(int), 1, file);
                        fwrite(&c, sizeof(char), 1, file);
                        
                        while (temp -> unionVar.dataOfDeparture[i] != '\n') {
                            fwrite(&(temp -> unionVar.dataOfDeparture[i]), sizeof(char), 1, file);
                            i++;
                        }
                        fwrite(&c, sizeof(char), 1, file);
                    }
                    
                    i = 0;
                    while (temp -> lastname[i]) {
                        i++;
                    }
                    
                    i++;
                    fwrite(&i, sizeof(int), 1, file);
                    fwrite(&c, sizeof(char), 1, file);
                    
                    for (int j = 0;j < i; j++) {
                        fwrite(&(temp ->lastname[j]), sizeof(char), 1, file);
                    }

                    temp = temp -> pointer;
                }
                
                fclose(file);
                break;
           
            case 3:
                return;
            
            default:
                printf("Choose another option.\n");
                break;
        }
    }
}

int loadFromFile (struct Passenger** topOfStack) {
    
    char fileName[FILESIZE];
    char stringTemp[20], space = '\0', c = '\0';
    int intTemp, typeFile, check, i = 0, count = 0, j = 0;
    FILE *file;
    
    if (*topOfStack) {
        printf("Information is already there.\n");
        return 0;
    }
    
    struct Passenger *temp = NULL, *secondStack = NULL, *pointer = NULL;
    
    printf("Select a file to upload\n");
    printf("1 - Text file.\n");
    printf("2 - Binary file.\n");
    printf("3 - Finish work.\n");
    
    do {
        check = scanf("%d", &typeFile);
        if (check < 1 || typeFile < 1 || typeFile > 3) {
            rewind(stdin);
            printf("There is no such number. Try to enter again.\n");
            continue;
        }
    }while (check < 1 || typeFile < 1 || typeFile > 3);
    
    switch (typeFile)
    {
        case 1:
            printf("Enter name of .txt File.\n");
            inputFileName(fileName, FILESIZE - 5);
            strcat(fileName, ".txt");
            
            if (!(file = fopen(fileName, "r"))) {
                printf("File not found\n.");
                return 0;
            }
            
            temp = (*topOfStack);
            while (1) {
                if (!(*topOfStack = (struct Passenger*)calloc(1, sizeof(struct Passenger)))) {
                    printf("Out of memory on your device.\n");
                    return 0;
                }
                
                fscanf(file, "%d", &intTemp);
                
                if (feof(file)) {
                    break;
                }
                
                (*topOfStack) -> numberOfFlight = intTemp;
                fscanf(file, "%c", &space);
                fscanf(file, "%d", &intTemp);
                
                if (intTemp) {
                    fscanf(file, "%c", &space);
                    fscanf(file, "%d", &intTemp);
                    (*topOfStack) -> unionVar.numberOfMinutes = intTemp;
                    (*topOfStack) -> choiceUnion = true;
                    fscanf(file, "%c", &space);
                }
                
                else {
                    fscanf(file, "%c", &space);
                    i = 0;
                    
                    while (1) {
                        fscanf(file, "%c", &c);
                        if (c == ' ') {
                            stringTemp[i++] = '\n';
                            stringTemp[i] = '\0';
                            break;
                        }
                        stringTemp[i] = c;
                        i++;
                    }
                    
                    strcpy((*topOfStack) -> unionVar.dataOfDeparture , stringTemp);
                    (*topOfStack) -> choiceUnion = false;
                }
                
                fscanf(file, "%d", &j);
                fscanf(file, "%c", &space);
                
                (*topOfStack) -> lastname = (char*) malloc(i * sizeof(char));
                
                for (int k = 0; k < j; k++) {
                    fscanf(file, "%c", &c);
                    ((*topOfStack) -> lastname[k] = c);
                }
                
                count++;
                (*topOfStack) -> pointer = temp;
                temp = (*topOfStack);
            }
            
            while (temp) {
                secondStack = temp -> pointer;
                temp -> pointer = pointer;
                pointer = temp;
                temp = secondStack;
            }
            *topOfStack = pointer;
            
            fclose(file);
            break;
        
        case 2:
            printf("Enter name of .bin File.\n");
            inputFileName(fileName, FILESIZE - 5);
            strcat(fileName, ".bin");
            
            if (!(file = fopen(fileName, "r + b"))) {
                printf("File not found\n.");
                return 0;
            }
            
            temp = (*topOfStack);
            
            while (1) {
                if (!(*topOfStack = (struct Passenger*)calloc(1, sizeof(struct Passenger)))) {
                    printf("Out of memory on your device.\n");
                    return 0;
                }
                fread(&intTemp, sizeof(int), 1, file);
                
                if (feof(file)) {
                    break;
                }
                
                (*topOfStack) -> numberOfFlight = intTemp;
                fread(&space, sizeof(char), 1, file);
               
                fread(&intTemp, sizeof(int), 1, file);
                
                if (intTemp) {
                    fread(&space, sizeof(char), 1, file);
                    fread(&intTemp, sizeof(int), 1, file);
                    (*topOfStack) -> unionVar.numberOfMinutes = intTemp;
                    (*topOfStack) -> choiceUnion = true;
                    fread(&space, sizeof(char), 1, file);
                }
                
                else {
                    i = 0;
                    fread(&space, sizeof(char), 1, file);
                    
                    while (1) {
                        fread(&c, sizeof(char), 1, file);
                        
                        if (c == ' ') {
                            stringTemp[i++] = '\n';
                            stringTemp[i] = '\0';
                            break;
                        }
                        stringTemp[i] = c;
                        i++;
                    }
                    
                    strcpy((*topOfStack) -> unionVar.dataOfDeparture , stringTemp);
                    (*topOfStack) -> choiceUnion = false;
                }
                
                fread(&intTemp, sizeof(int), 1, file);
                
                
                (*topOfStack) -> lastname = (char*) malloc(intTemp * sizeof(char));
                fread(&space, sizeof(char), 1, file);
                
                for (int k = 0; k < intTemp; k++) {
                    fread(&c, sizeof(char), 1, file);
                    ((*topOfStack) -> lastname[k] = c);
                }

                count++;
                
                (*topOfStack) -> pointer = temp;
                temp = *topOfStack;
                
            }
            
            while (temp) {
                secondStack = temp -> pointer;
                temp -> pointer = pointer;
                pointer = temp;
                temp = secondStack;
            }
            *topOfStack = pointer;
            
            fclose(file);
            break;
       
        case 3:
            return count;
        
        default:
            printf("Choose another option.\n");
            break;
    }
    return count;
}
