#include "ProductionMotors.hpp"

ProductionMotors:: ProductionMotors(float engineCapacity, int factoryPrice, int detailPrice, int numberEmployeesPerPart): Plant(factoryPrice), ProductionDetails(factoryPrice, detailPrice, numberEmployeesPerPart) {
    std::cout << "ProductionMotors constructor called " << std::endl;
    SetEngineCapacity(engineCapacity);
}

ProductionMotors:: ~ProductionMotors() {
    std::cout << "ProductionMotors destructor called " << std::endl;
}

void ProductionMotors:: SetEngineCapacity(float engineCapacity) {
    this -> engineCapacity = engineCapacity;
}

float ProductionMotors:: GetEngineCapacity() {
    return engineCapacity;
}

void ProductionMotors:: Display() {
    std::cout << "Engine Capacity: " << engineCapacity << std::endl;
}
