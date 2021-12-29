#include "ProductionDetails.hpp"

ProductionDetails:: ProductionDetails (int factoryPrice, int detailPrice, int numberEmployeesPerPart):Plant(factoryPrice) {
    std::cout << "ProductionDetails constructor called " << std::endl;
    SetDetailPrice(detailPrice);
    SetNumberEmployeesPerPart(numberEmployeesPerPart);
}

ProductionDetails:: ~ProductionDetails() {
    std::cout << "ProductionDetails destructor called " << std::endl;
}

int ProductionDetails:: GetDetailPrice() {
    return detailPrice;
}

int ProductionDetails:: GetNumberEmployeesPerPart() {
    return numberEmployeesPerPart;
}

void ProductionDetails:: SetDetailPrice(int detailPrice) {
    this -> detailPrice = detailPrice;
}

void ProductionDetails:: SetNumberEmployeesPerPart(int numberEmployeesPerPart) {
    this -> numberEmployeesPerPart = numberEmployeesPerPart;
}

void ProductionDetails:: Display() {
    std::cout << "detail price: " << detailPrice << std::endl;
    std::cout << "number of employees per part" << numberEmployeesPerPart << std::endl;
}
