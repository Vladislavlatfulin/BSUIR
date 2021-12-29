#include "Library.hpp"

int enteringANumber () {
    char *userPercentage = new char [10];
    int IntPercentage = 0;
    rewind(stdin);
    for (int i = 0; i < 10; i++) {
        char c = std::cin.get();
        
        if (i == 0  && c == '\n') {  throw "Exception! Enter a number"; }
        if ((c < '0' || c > '9')  && c != '\n') { throw "Exception! Enter a number"; }
        
        if (c == '\n') {
            userPercentage[i] = '\0';
            IntPercentage = atoi(userPercentage);
            break;
        }
        userPercentage[i] = c;
    }
    return IntPercentage;
    
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

int menu() {
    int tempMenu;
    std::cout << std::endl <<"Enter number for change." << std::endl;
    std::cout <<"1 - Enter your set." << std::endl;
    std::cout <<"2 - Show your set." << std::endl;
    std::cout <<"3 - Deletion element in your set." << std::endl;
    std::cout <<"4 - Change your set." << std::endl;
    std::cout <<"5 - Sort your set." << std::endl;
    std::cout <<"6 - Finish work." << std::endl;

    
    std::cin >> tempMenu;
    
    return tempMenu;
}
