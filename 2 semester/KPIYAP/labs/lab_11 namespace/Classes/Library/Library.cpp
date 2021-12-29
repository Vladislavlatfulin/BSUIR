
#include "Library.hpp"

int enteringANumber () {
    char *userPercentage = new char [10];
    int IntPercentage = 0;
    rewind(stdin);

    do {
        try {
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
        } catch (const char * ex) {
            std::cout << ex << std::endl;
            rewind(stdin);
        }
    }while (!IntPercentage);
    
    return IntPercentage;

}


int menu() {
    std::cout << "what are we doing?" << std::endl;
    std::cout << "1 - sort" << std::endl;
    std::cout << "2 - output in range" << std::endl;
    std::cout << "3 - finish work" << std::endl;
    int number;
    std::cin >> number;
    return number;
}

int sort() {
    std::cout << "by which property we will sort?" << std::endl;
    std::cout << "1 - by author name" << std::endl;
    std::cout << "2 - by material price" << std::endl;
    std::cout << "3 - by square architectural object" << std::endl;
    std::cout << "4 - by opening Date" << std::endl;
    std::cout << "5 - finish work" << std::endl;
    int number;
    std::cin >> number;
    return number;
}

void printTypeSort () {
    std::cout << "Enter typeSort" << std::endl;
    std::cout << "1 - to increase (>)" << std::endl;
    std::cout << "2 - by diminishing (<)"  << std::endl;
}

int rangeOutputMenu() {
    std::cout << "by which property we will range output?" << std::endl;
    std::cout << "1 - by author name" << std::endl;
    std::cout << "2 - by author surname" << std::endl;
    std::cout << "3 - by expended Resources" << std::endl;
    std::cout << "4 - by height architectural object" << std::endl;
    std::cout << "5 - finish work" << std::endl;
 
    int number;
    std::cin >> number;
    return number;
}
