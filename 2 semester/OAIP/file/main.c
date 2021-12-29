#include "library.h"
#define SIZE_OF_FILENAME 20

int main () {
    FILE *binFile = NULL, *textFile = NULL;
    int choice, check, typeFile;
    char *fileName = (char*)malloc((SIZE_OF_FILENAME - 5) * sizeof(char));
    bool isInputInformation = false;
    
    while (1) {
        printf("\nChoose type file to work with\n");
        printf("1 - Text file\n");
        printf("2 - Binary file\n");
        printf("3 - Finish work\n");
        
        do {
            check = scanf("%d", &typeFile);
            if (check < 1 || typeFile < 1 || typeFile > 3) {
                printf("Choice other option\n");
                rewind(stdin);
                continue;
            }
        }while(check < 1 || typeFile < 1 || typeFile > 3);
        
        switch (typeFile) {
            case 1:
                printf("\nEnter name text file (.txt)\n");
                inputFileName(fileName, SIZE_OF_FILENAME - 5);
                strcat(fileName, ".txt");
                
                while (1) {
                    printf("\nWhat do you want to do with the file?\n");
                    printf("1 - Enter information.\n");
                    printf("2 - Output informatoin.\n");
                    printf("3 - Count the number of words of a given length.\n");
                    printf("4 - Replace words with spaces.\n");
                    printf("5 - Finish work.\n");
                    
                    do {
                        check = scanf("%d", &choice);
                        if (check < 1 || choice < 1 || choice > 5) {
                            printf("Choice other option\n");
                            rewind(stdin);
                            continue;
                        }
                    }while(check < 1 || choice < 1 || choice > 5);
                    
                    switch (choice)
                    {
                        case 1:
                            if (isInputInformation == true) {
                                printf("Information already entered.\n");
                                break;
                                
                            }
                            
                            inputInformationIntoFile(textFile, typeFile, fileName);
                            isInputInformation = true;
                            break;
                        case 2:
                            
                            if (isInputInformation == false) {
                                printf("Enter information.\n");
                                break;
                            }
                            
                            outputInformationFile(textFile, typeFile, fileName);
                            break;
                        case 3:
                            
                            if (isInputInformation == false) {
                                printf("Enter information.\n");
                                break;
                            }
                            
                            wordCount(textFile, fileName);
                            break;
                        case 4:
                            
                            if (isInputInformation == false) {
                                printf("Enter information.\n");
                                break;
                            }
                            
                            deleteWord(textFile, fileName);
                            outputInformationFile(textFile, typeFile, fileName);
                            break;
                        
                        case 5:
                            free(fileName);
                            return 0;
                        default:
                            printf("Enter other option\n");
                            break;
                    }
                }
                break;
                
            case 2:
                
                printf("\nEnter name binary file (.bin)\n");
                inputFileName(fileName, SIZE_OF_FILENAME - 5);
                strcat(fileName, ".bin");
                
                while(1) {
                    printf("\nWhat do you want to do with the file?\n");
                    printf("1 - Enter information.\n");
                    printf("2 - Output informatoin.\n");
                    printf("3 - Сalculate the amount.\n");
                    printf("4 - linearly transform.\n");
                    printf("5 - Finish work.\n");
                    
                    do {
                        check = scanf("%d", &choice);
                        if (check < 1 || choice < 1 || choice > 5) {
                            printf("Choice other option\n");
                            rewind(stdin);
                            continue;
                        }
                    }while(check < 1 || choice < 1 || choice > 5);
                    
                    switch (choice) {
                        case 1:
                            
                            if (isInputInformation == true) {
                                printf("Information already entered.\n");
                                break;
                            }
                            
                            inputInformationIntoFile(binFile, typeFile, fileName);
                            isInputInformation = true;
                            break;
                            
                        case 2:
                            if (isInputInformation == false) {
                                printf("Enter information.\n");
                                break;
                            }
                            
                            outputInformationFile(binFile, typeFile, fileName);
                            break;
                            
                        case 3:
                            if (isInputInformation == false) {
                                printf("Enter information.\n");
                                break;
                            }
                            
                            loadCapacityOfCargo(binFile, fileName);
                            break;
                            
                        case 4:
                            if (isInputInformation == false) {
                                printf("Enter information.\n");
                                break;
                            }
                            
                            linearTransformation(binFile, fileName);
                            break;
                            
                        case 5:
                            free(fileName);
                            return 0;
                        default:
                            printf("Enter other option\n");
                            break;
                    }
                }
                
                break;
            case 3:
                return 0;
                
            default:
                printf("Enter other option\n");
                break;
        }
    }
    return 0;
}


