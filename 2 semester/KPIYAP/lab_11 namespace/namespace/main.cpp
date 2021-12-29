#include "Memorial.h"
#include <functional>
#include "Library.hpp"

using namespace memorial;

// пользовательский ввод
// исключения
// массив объектов memorial
// сортировка по выбору < >
// поиск по диапазону
// если строка, то только по первой букве

void outpurMemorialArray(Memorial *user, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " memorial" << endl;
        user[i].Display();
        cout << endl << endl;
    }
}



void sortAuthorName (Memorial *user, int size, function<bool(string, string)> typeSort) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            
            if(typeSort(user[i].GetAuthorName(), user[j].GetAuthorName())) {
                Memorial temp(user[i]);
                user[i] = user[j];
                user[j] = temp;
                temp.authorObg = nullptr;
                temp.coorObg = nullptr;
                temp.matObj = nullptr;
            }
        }
    }
}


void sortMaterialPrice (Memorial *user, int size, function<bool(int, int)> typeSort) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            
            if(typeSort(user[i].matObj ->GetPrice(), user[j].matObj ->GetPrice())) {
                Memorial temp(user[i]);
                user[i] = user[j];
                user[j] = temp;
                temp.authorObg = nullptr;
                temp.coorObg = nullptr;
                temp.matObj = nullptr;
            }
        }
    }
}

void sortSquare (Memorial *user, int size, function<bool(float, float)> typeSort) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if(typeSort(user[i].archObj -> GetSquare(), user[j].archObj ->GetSquare())) {
                Memorial temp(user[i]);
                user[i] = user[j];
                user[j] = temp;
                temp.authorObg = nullptr;
                temp.coorObg = nullptr;
                temp.matObj = nullptr;
            }
        }
    }
}

void sortOpeningDate (Memorial *user, int size, function<bool(string, string)> typeSort) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if(typeSort(user[i].desObg -> GetOpeningDate(), user[j].desObg -> GetOpeningDate())) {
                Memorial temp(user[i]);
                user[i] = user[j];
                user[j] = temp;
                temp.authorObg = nullptr;
                temp.coorObg = nullptr;
                temp.matObj = nullptr;
            }
        }
    }
}




int main(int argc, const char * argv[]) {
    
    int number;
    std::cout << "Enter size array: ";
    number = enteringANumber();
    
    Memorial *userArray = new Memorial[number];
    
    for (int i = 0; i < number; i++) {
        std::string firstTemp, secondTemp;
        std::cout << "Enter a " << i + 1 << " author name" << std::endl;
        std::cin >> firstTemp;
        std::cout << "Enter a " << i + 1<< " author surname" << std::endl;
        std::cin >> secondTemp;
        memorial::Author *author = new memorial::Author(firstTemp, secondTemp);
        std::cout << "Enter " << i + 1<< " coordinate" << std::endl;
        memorial::Coordinate *coordinate = new memorial::Coordinate(enteringANumber(), enteringANumber());
        std::cout << "Enter " << i + 1<< " title material" << std::endl;
        std::cin >> firstTemp;
        std::cout << "Enter " << i + 1<< " price material" << std::endl;
        memorial::Material *material = new memorial::Material(firstTemp, enteringANumber());
        
        std::cout << "Enter a " << i + 1 << "  whom is the menorial" << std::endl;
        std::cin >> firstTemp;
        std::cout << "Enter a " << i + 1 << " in honor of what" << std::endl;
        std::cin >> secondTemp;
        std::cout << "Enter a " << i + 1 << " height and square" << std::endl;
        userArray[i].SetInformation(material, coordinate, author, enteringANumber(), enteringANumber(), firstTemp, secondTemp);
    }
    
    for (int i = 0; i < number; i++) {
        cout << i + 1 << " memorial" << endl;
        userArray[i].Display();
        cout << endl << endl;
        
    }
    int leftIntBorder, rightIntBorder;
    char leftCharBorder, rightCharBorder;
    int typeSort;
    while (true) {
        switch (menu()) {
            case 1:
                switch (sort()) {
                    case 1:
                        printTypeSort();
                        std::cin >> typeSort;
                        if (typeSort == 1) { sortAuthorName(userArray, number, [](string a,string b){return a > b;}); }
                        else if (typeSort == 2) { sortAuthorName(userArray, number, [](string a,string b){return a < b;}); }
                        outpurMemorialArray(userArray, number);
                        break;
                        
                    case 2:
                        printTypeSort();
                        std::cin >> typeSort;
                        if (typeSort == 1) { sortMaterialPrice(userArray, number, [](int a,int b){return a > b;}); }
                        else if (typeSort == 2) { sortMaterialPrice(userArray, number, [](int a,int b){return a < b;}); }
                        outpurMemorialArray(userArray, number);
                        break;
                        
                    case 3:
                        printTypeSort();
                        std::cin >> typeSort;
                        if (typeSort == 1) { sortSquare(userArray, number, [](float a,float b){return a > b;}); }
                        else if (typeSort == 2) { sortSquare(userArray, number, [](float a,float b){return a < b;}); }
                        outpurMemorialArray(userArray, number);
                        break;
                    case 4:
                        printTypeSort();
                        std::cin >> typeSort;
                        if (typeSort == 1) { sortOpeningDate(userArray, number, [](string a,string b){return a > b;}); }
                        else if (typeSort == 2) { sortOpeningDate(userArray, number, [](string a,string b){return a < b;}); }
                        outpurMemorialArray(userArray, number);
                        break;
                    case 5:
                        break;
                    default:
                        break;
                }
                
                break;
            case 2:
                switch (rangeOutputMenu()) {
                    case 1:
                        std::cout << "Enter left border" << std::endl;
                        cin >> leftCharBorder;
                        std::cout << "Enter right border" << std::endl;
                        cin >> rightCharBorder;
                        
                        for (int i = 0; i < number; i++) {
                           
                            if (leftCharBorder <= userArray[i].authorObg ->GetName()[0] && userArray[i].authorObg ->GetName()[0] <= rightCharBorder) {
                                userArray[i].Display();
                                std::cout << std::endl << std::endl;
                            }
                        }
                        break;
                    case 2:
                        std::cout << "Enter left border" << std::endl;
                        cin >> leftCharBorder;
                        std::cout << "Enter right border" << std::endl;
                        cin >> rightCharBorder;
                        for (int i = 0; i < number; i++) {
                           
                            if (leftCharBorder <= userArray[i].authorObg ->GetSurname()[0] && userArray[i].authorObg ->GetSurname()[0] <= rightCharBorder) {
                                userArray[i].Display();
                                std::cout << std::endl << std::endl;
                            }
                        }
                        break;
                    case 3:
                        std::cout << "Enter left border" << std::endl;
                        leftIntBorder = enteringANumber();
                        std::cout << "Enter right border" << std::endl;
                        rightIntBorder = enteringANumber();
                        for (int i = 0; i < number; i++) {
                            if (leftIntBorder <= userArray[i].desObg -> GetExpendedResources() && userArray[i].desObg -> GetExpendedResources() <= rightIntBorder) {
                                userArray[i].Display();
                                std::cout << std::endl << std::endl;
                            }
                        }
                        break;
                    case 4:
                        std::cout << "Enter left border" << std::endl;
                        leftIntBorder = enteringANumber();
                        std::cout << "Enter right border" << std::endl;
                        rightIntBorder = enteringANumber();
                        for (int i = 0; i < number; i++) {
                            if (leftIntBorder <= userArray[i].archObj -> GetHeight() && userArray[i].archObj -> GetHeight() <= rightIntBorder) {
                                userArray[i].Display();
                                std::cout << std::endl << std::endl;
                            }
                        }
                        break;
                    case 5:
                        break;
                    default:
                        break;
                }
                
                break;
            case 3:
                delete [] userArray;
                return 0;
                
            default:
                break;
        }
    }
    return 0;
}


