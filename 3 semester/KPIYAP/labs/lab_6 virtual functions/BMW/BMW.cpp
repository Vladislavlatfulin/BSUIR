#include "BMW.hpp"
BMW:: BMW(int yearOfrelease, std::string typesOfModels, int factoryPrice, int amountForDetails, int detailPrice, drivingMode mode): CarAssembly(yearOfrelease, typesOfModels, factoryPrice, amountForDetails, detailPrice) {
    this -> mode = mode;
    std::cout << "BMW constructor called " << std::endl;
}

BMW:: ~BMW () {
    std::cout << "BMW destructor called " << std::endl;
}

void BMW:: Display() {
    std::cout << "Factory price: " << GetFactoryPrice() << std::endl;
    std::cout << "Year of release: " << GetYearOfRelease() << std::endl;
    std::cout << "Types of models: " << GetTypesOfModels() << std::endl;
    std::cout << "Detail price: " << GetDetailPrice() << std::endl;
    std::cout << "Amount for details: " << GetAmountForDetails() << std::endl;
    std::cout << "Driving Mode: " << convertingIntoString() << std::endl;
}

void BMW:: SetDrivingMode(drivingMode mode) {
    this -> mode = mode;
}

BMW::drivingMode BMW:: GetDrivingMode() {
    return mode;
}

std::string BMW:: convertingIntoString() {
    std::string temp;
    
    switch (mode) {
        case BMW::drivingMode::Sport:
            temp = "Sport";
            break;
        case BMW::drivingMode::Sity:
            temp = "Sity";
            break;
        case BMW::drivingMode::Cruise:
            temp = "Cruise";
            break;
        default:
            break;
    }
    return temp;
}

int BMW:: amountDetails() {
    return GetAmountForDetails() / GetDetailPrice();
}
