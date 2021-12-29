#include "functional.hpp"
#define FILESIZE 20
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

int push (struct Queue **head, struct Queue **tail) {
    int count = 0;
    struct Queue *temp;
    int sizeLastname, check, choice;
    char c;
    do {
        if (!(temp = (struct Queue*)calloc(1, sizeof(struct Queue)))) {
            printf("Out of memory on your device.\n");
            return 0;
        }
        
        printf("\nEnter number of flight.\n");
        temp -> information.numberOfFlight = inputChoice();
        
        
        do {
            printf("\nEnter size lastname.\n");
            temp -> information.lastname = NULL;
            sizeLastname = inputChoice();
            if (!(temp -> information.lastname = (char*) malloc(sizeLastname * sizeof(char)))) {
                printf("Out of memory on your device.\n");
                continue;
            }
            
        }while (!(temp -> information.lastname));
        printf("\nEnter lastname.\n");
        correctInput(temp -> information.lastname, sizeLastname);
        
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
            temp -> information.choiceUnion = true;
        }
        else {
            temp -> information.choiceUnion = false;
        }
        
        if (temp -> information.choiceUnion) {
            printf("\nEnter number of minutes.\n");
            temp -> information.unionVar.numberOfMinutes = inputChoice();
        }
        else {
            printf("\nEnter date of departure flight.\n");
            
            int j = 0;
            int length = 20;
            do {
                rewind(stdin);
                while ((c = getchar()) != '\n' && --length > 0) {
                    temp -> information.unionVar.dataOfDeparture[j++] = c;
                    if (c == '\n' || !isdigit(c)) {
                        printf("You are using prohibited items. Try to enter again.\n");
                        rewind(stdin);
                        j = 0;
                        length = 20;
                    }
                }
            } while (j == 0);
            
            temp -> information.unionVar.dataOfDeparture[j++] = '\n';
            temp -> information.unionVar.dataOfDeparture[j] = '\0';
            
        }
        
        if (!*head) {
            *head = *tail = temp;
        }
        else {
            (*tail) -> next = temp;
            *tail = temp;
        }
        count++;
        printf("Continue? (y - yes, n - no)\n");
        rewind(stdin);
        c = getchar();
    }while (c == 'y');
    return count;
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

void output (struct Queue* head, struct Queue* tail ,int numberOfNode) {
    int choice, check;
    
    if( head == NULL) {
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
                outputOneStructure(head, choice);
                
                break;
                
            case 2:
                printf("-----------------------------------------------------------------------------------------\n");
                printf("| № | number of flights | last name           | number of minutes | check out date      |\n");
                choice = 0;
                while (1) {
                    outputOneStructure(head, choice);
                    if (head == tail) {
                        break;
                    }
                    choice++;
                    head = head -> next;
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

void outputOneStructure (struct Queue* head, int index) {
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| %d |", index + 1);
    printf(" %-6d            | ", head -> information.numberOfFlight);
    printNormalString(head -> information.lastname);
    
    if (head -> information.choiceUnion) {
        printf(" %-6d           | ------------------- |\n", head -> information.unionVar.numberOfMinutes);
    }
    
    if (!head -> information.choiceUnion) {
        printf("----------------- | ");
        printNormalString(head -> information.unionVar.dataOfDeparture);
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

void search(struct Queue *head, int numberOfNode) {
    int choice, flag = 0, length, j = 0, userVar;
    char *userString1 = NULL, *tempString = NULL;
    struct Queue *temp = head;
    
    if (!head) {
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
                
                
                for (choice = 0, temp = head; temp ; temp = temp -> next, choice++) {
                    strcpy(tempString, temp -> information.lastname);
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
                
                for (choice = 0, temp = head; temp; temp = temp -> next, choice++) {
                    if (temp -> information.numberOfFlight == userVar) {
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
                
                for (choice = 0, temp = head; temp; temp = temp = temp -> next, choice++) {
                    if (temp -> information.unionVar.numberOfMinutes == userVar && temp -> information.choiceUnion) {
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
                
                for (choice = 0, temp = head; temp; temp = temp -> next, choice++) {
                    if (strstr(temp -> information.unionVar.dataOfDeparture, userString1) && !temp -> information.choiceUnion) {
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

int numberOfFullNode(struct Queue *head, struct Queue *tail) {
    struct Queue *temp = head;
    int number = 1;
    
    while (1) {
        temp = temp -> next;
        number++;
        if (temp == tail) {
            break;
        }
    }
    return number;
}


void deleteNode(struct Queue **head, struct Queue** tail,int numberOfNode, int numberOfNodeDelete) {
    int i;
    
    struct Queue *deleteNode = *head, *temp = *head;
    
    if (*head == NULL) {
        printf("First enter information.\n");
        return;
    }
    
    
    
    for (i = 1; i < numberOfNodeDelete && deleteNode != nullptr; i++) {
        deleteNode = deleteNode -> next;
    }
    
    if (deleteNode == *head) {
        *head = (*head) -> next;
        free(deleteNode);
        return;
    }

    if (deleteNode == *tail) {
        while (temp -> next != deleteNode) {
            temp = temp -> next;
        }
        *tail = temp;
        (*tail) -> next = deleteNode -> next;
        free(deleteNode);
        return;
    }
    else if (deleteNode != *head && deleteNode != *tail) {
        while (temp -> next != deleteNode) {
            temp = temp -> next;
        }
        temp -> next = deleteNode -> next;
        free(deleteNode);
        return;
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

void saveInFile (struct Queue *head, struct Queue *tail) {
    char fileName[FILESIZE], c = ' ';
    int check, typeFile, i = 0;
    struct Queue *temp = head;
    FILE *file;
    
    if (!head) {
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
                temp = head;
                printf("\nEnter name of .txt File.\n");
                inputFileName(fileName, FILESIZE - 5);
                strcat(fileName, ".txt");
                
                if (!(file = fopen(fileName, "w"))) {
                    printf("File not found\n.");
                    return;
                }
                
                while (1) {
                    fprintf(file, "%d", temp -> information.numberOfFlight);
                    fprintf(file, "%c", ' ');
                    
                    if (temp -> information.choiceUnion) {
                        fprintf(file, "%d", 1);
                        fprintf(file, "%c", ' ');
                        fprintf(file, "%d", temp -> information.unionVar.numberOfMinutes);
                    }
                    
                    else {
                        fprintf(file, "%d", 0);
                        fprintf(file, "%c", ' ');
                        i = 0;
                        while (temp -> information.unionVar.dataOfDeparture[i] != '\n') {
                            fprintf(file, "%c", temp -> information.unionVar.dataOfDeparture[i]);
                            i++;
                        }
                    }
                    
                    fprintf(file, "%c", ' ');
                    i = 0;
                    
                    while (temp -> information.lastname[i]) {
                        i++;
                    }
                    
                    i++;
                    fprintf(file, "%d", i);
                    fprintf(file, "%c", ' ');
                    
                    
                    for (int j = 0;j < i; j++) {
                        fprintf(file, "%c", temp -> information.lastname[j]);
                    }
                    if (temp == tail) {
                        break;
                    }
                    temp = temp -> next;
                }
                
                fclose(file);
                break;
            
            case 2:
                temp = head;
                printf("Enter name of .bin File.\n");
                inputFileName(fileName, FILESIZE - 5);
                strcat(fileName, ".bin");
                
                if (!(file = fopen(fileName, "w + b"))) {
                    printf("File not found\n.");
                    return;
                }
                
                while (1) {
                    fwrite(&(temp -> information.numberOfFlight), sizeof(int), 1, file);
                    fwrite(&c, sizeof(char), 1, file);
                    
                    if (temp -> information.choiceUnion) {
                        i = 1;
                        fwrite(&i, sizeof(int), 1, file);
                        fwrite(&c, sizeof(char), 1, file);
                        fwrite(&(temp -> information.unionVar.numberOfMinutes), sizeof(int), 1, file);
                        fwrite(&c, sizeof(char), 1, file);
                    }
                    
                    else {
                        i = 0;
                        fwrite(&i, sizeof(int), 1, file);
                        fwrite(&c, sizeof(char), 1, file);
                        
                        while (temp -> information.unionVar.dataOfDeparture[i] != '\n') {
                            fwrite(&(temp -> information.unionVar.dataOfDeparture[i]), sizeof(char), 1, file);
                            i++;
                        }
                        fwrite(&c, sizeof(char), 1, file);
                    }
                    
                    i = 0;
                    while (temp -> information.lastname[i]) {
                        i++;
                    }
                    
                    i++;
                    fwrite(&i, sizeof(int), 1, file);
                    fwrite(&c, sizeof(char), 1, file);
                    
                    for (int j = 0;j < i; j++) {
                        fwrite(&(temp -> information.lastname[j]), sizeof(char), 1, file);
                    }
                    if (temp == tail) {
                        break;
                    }
                    temp = temp -> next;
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

int loadFromFile (struct Queue** head, struct Queue** tail) {
    
    char fileName[FILESIZE];
    char stringTemp[20], space = '\0', c = '\0';
    int intTemp, typeFile, check, i = 0, count = 0, j = 0;
    FILE *file;
    
//    if (*head) {
//        printf("Information is already there.\n");
//        return 0;
//    }
    
    struct Queue *temp = NULL;
    
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
            
            while (1) {
                if (!(temp = (struct Queue*)calloc(1, sizeof(struct Queue)))) {
                    printf("Out of memory on your device.\n");
                    return 0;
                }

                fscanf(file, "%d", &intTemp);

                if (feof(file)) {
                    break;
                }

                temp -> information.numberOfFlight = intTemp;
                fscanf(file, "%c", &space);
                fscanf(file, "%d", &intTemp);

                if (intTemp) {
                    fscanf(file, "%c", &space);
                    fscanf(file, "%d", &intTemp);
                    temp -> information.unionVar.numberOfMinutes = intTemp;
                    temp -> information.choiceUnion = true;
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

                    strcpy(temp -> information.unionVar.dataOfDeparture , stringTemp);
                    temp -> information.choiceUnion = false;
                }

                fscanf(file, "%d", &j);
                fscanf(file, "%c", &space);

                temp -> information.lastname = (char*) malloc(i * sizeof(char));

                for (int k = 0; k < j; k++) {
                    fscanf(file, "%c", &c);
                    temp -> information.lastname[k] = c;
                }

                count++;
                if (!*head) {
                    *head = *tail = temp;
                }
                else {
                    (*tail) -> next = temp;
                    *tail = temp;
                }
            }
            
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
            
            
            while (1) {
                if (!(temp = (struct Queue*)calloc(1, sizeof(struct Passenger)))) {
                    printf("Out of memory on your device.\n");
                    return 0;
                }
                fread(&intTemp, sizeof(int), 1, file);
                
                if (feof(file)) {
                    break;
                }
                
                temp -> information.numberOfFlight = intTemp;
                fread(&space, sizeof(char), 1, file);
               
                fread(&intTemp, sizeof(int), 1, file);
                
                if (intTemp) {
                    fread(&space, sizeof(char), 1, file);
                    fread(&intTemp, sizeof(int), 1, file);
                    temp -> information.unionVar.numberOfMinutes = intTemp;
                    temp -> information.choiceUnion = true;
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
                    
                    strcpy(temp -> information.unionVar.dataOfDeparture , stringTemp);
                    temp -> information.choiceUnion = false;
                }
                
                fread(&intTemp, sizeof(int), 1, file);
                
                
                temp -> information.lastname = (char*) malloc(intTemp * sizeof(char));
                fread(&space, sizeof(char), 1, file);
                
                for (int k = 0; k < intTemp; k++) {
                    fread(&c, sizeof(char), 1, file);
                    temp -> information.lastname[k] = c;
                }

                count++;
                
                if (!*head) {
                    *head = *tail = temp;
                }
                else {
                    (*tail) -> next = temp;
                    *tail = temp;
                }
                
            }
            
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
