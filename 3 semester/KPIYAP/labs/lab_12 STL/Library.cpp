//
//  Library.cpp
//  STL
//
//  Created by Vladislav Latfulin on 29.11.21.
//

#include "Library.hpp"

int enteringANumber () {
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
            if (IntPercentage < 0 || IntPercentage > 10000) {
                i = -1;
                std::cout << "enter a number from 0 to 10000" << std::endl;
                rewind(stdin);
                continue;
            }
            break;
        }
        userPercentage[i] = c;
    }
    
    return IntPercentage;
    
}
