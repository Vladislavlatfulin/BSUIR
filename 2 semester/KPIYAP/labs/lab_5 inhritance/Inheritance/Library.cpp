#include "Library.hpp"

void enteringANumber (int *number) {
    char *userPercentage = new char [10];
    int IntPercentage = 0;
    rewind(stdin);
    for (int i = 0; i < 10; i++) {
        char c = std::cin.get();
        
        if (i == 0  && c == '\n') {
            std::cout << "You need to enter a number!" << std::endl << "Enter the number again" << std::endl;
            i = -1;
            rewind(stdin);
            continue;
        }
        
        if ((c < '0' || c > '9')  && c != '\n') {
            std::cout << "You need to enter a number!" << std::endl << "Enter the number again" << std::endl;
            i = -1;
            rewind(stdin);
            continue;
        }
        
        if (c == '\n') {
            userPercentage[i] = '\0';
            IntPercentage = atoi(userPercentage);
            if (IntPercentage < 10 || IntPercentage > 10000) {
                i = -1;
                std::cout << "enter a number from 10 to 10000" << std::endl;
                rewind(stdin);
                continue;
            }
            break;
        }
        userPercentage[i] = c;
    }
    
    *number = IntPercentage;
    
}


void enteringTheYear (int *number) {
    char *userPercentage = new char [10];
    int IntPercentage = 0;
    rewind(stdin);
    for (int i = 0; i < 10; i++) {
        char c = std::cin.get();
        
        if (i == 0  && c == '\n') {
            std::cout << "You need to enter a number!" << std::endl << "Enter the number again" << std::endl;
            i = -1;
            rewind(stdin);
            continue;
        }
        
        if ((c < '0' || c > '9')  && c != '\n') {
            std::cout << "You need to enter a number!" << std::endl << "Enter the number again" << std::endl;
            i = -1;
            rewind(stdin);
            continue;
        }
        
        if (c == '\n') {
            userPercentage[i] = '\0';
            IntPercentage = atoi(userPercentage);
            if (IntPercentage < 1929 || IntPercentage > 2021) {
                i = -1;
                std::cout << "enter a number from 1929 to 2021" << std::endl;
                rewind(stdin);
                continue;
            }
            break;
        }
        userPercentage[i] = c;
    }
    
    *number = IntPercentage;
    
}
// ввод дабл
void enteringADouble (double *number) {
    char *userPercentage = new char [10];
    double IntPercentage = 0;
    rewind(stdin);
    for (int i = 0; i < 10; i++) {
        char c = std::cin.get();
        
        if (i == 0  && c == '\n') {
            std::cout << "You need to enter a number!" << std::endl << "Enter the number again" << std::endl;
            i = -1;
            rewind(stdin);
            continue;
        }
        
        if ((c < '0' || c > '9') && c != '.'  && c != '\n') {
            std::cout << "You need to enter a number!" << std::endl << "Enter the number again" << std::endl;
            i = -1;
            rewind(stdin);
            continue;
        }
        
        if (c == '\n') {
            userPercentage[i] = '\0';
            IntPercentage = atof(userPercentage);
            if (IntPercentage < 0.8 || IntPercentage > 4.0) {
                i = -1;
                std::cout << "enter a number from 0.8 to 4.0" << std::endl;
                rewind(stdin);
                continue;
            }
            break;
        }
        userPercentage[i] = c;
    }
    
    *number = IntPercentage;
    
}


void enterData (int *factoryPrice, int *salary, int* yearOfRelease, int* detailPrice, int* numberOfEmployeesPerPart, double *engineCapacity) {
    std::cout << "Enter factory price" << std::endl;
    enteringANumber(factoryPrice);
    std::cout << std::endl << "Enter salary" << std::endl;
    enteringANumber(salary);
    std::cout << std::endl << "Enter year of release" << std::endl;
    enteringTheYear(yearOfRelease);
    std::cout << std::endl << "Enter detail Price" << std::endl;
    enteringANumber(detailPrice);
    std::cout << std::endl << "Enter number of employees per part" << std::endl;
    enteringANumber(numberOfEmployeesPerPart);
    std::cout << std::endl << "Enter engine capacity" << std::endl;
    enteringADouble(engineCapacity);
}
