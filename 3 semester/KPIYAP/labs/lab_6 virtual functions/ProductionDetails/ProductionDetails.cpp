#include "ProductionDetails.hpp"

ProductionDetails:: ProductionDetails (int numberEmployeesPerPart, int factoryPrice, int amountForDetails, int detailPrice):Plant(factoryPrice, amountForDetails, detailPrice) {
    std::cout << "ProductionDetails constructor called " << std::endl;
    SetNumberEmployeesPerPart(numberEmployeesPerPart);
}

ProductionDetails:: ~ProductionDetails() {
    std::cout << "ProductionDetails destructor called " << std::endl;
}

int ProductionDetails:: GetNumberEmployeesPerPart() {
    return numberEmployeesPerPart;
}

void ProductionDetails:: SetNumberEmployeesPerPart(int numberEmployeesPerPart) {
    this -> numberEmployeesPerPart = numberEmployeesPerPart;
}

void ProductionDetails:: Display() {
    std::cout << "Factory price: " << GetFactoryPrice() << std::endl;
    std::cout << "Amount for details: " << GetAmountForDetails() << std::endl;
    std::cout << "Detail price: " << GetDetailPrice() << std::endl;
    std::cout << "Number of employees per part: " << numberEmployeesPerPart << std::endl;
}

int ProductionDetails:: amountDetails() {
    return GetAmountForDetails() / (GetDetailPrice() * 3);
}

