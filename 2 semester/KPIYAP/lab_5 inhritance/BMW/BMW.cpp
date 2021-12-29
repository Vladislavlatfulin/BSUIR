#include "BMW.hpp"

BMW:: BMW(std::string typesOfModels, int factoryPrice, int salary, int yearOfRelease, int detailPrice, int numberEmployeesPerPart, float engineCapacity, drivingMode mode):Plant(factoryPrice), ProductionMotors(engineCapacity, factoryPrice, detailPrice, numberEmployeesPerPart), CarAssembly(yearOfRelease, typesOfModels, salary, factoryPrice) {
    this -> mode = mode;
    std::cout << "BMW constructor called " << std::endl;
}

BMW:: ~BMW () {
    std::cout << "BMW destructor called " << std::endl;
}

void BMW:: Display() {
    std::cout << std::endl << std::endl << "Fields are inherited from classes:" << std::endl;
    std::cout << std::endl << "factory price: " << GetFactoryPrice() << std::endl;
    std::cout << "Salary: " << GetSalary() << std::endl;
    std::cout << "year of release: " << GetYearOfRelease() << std::endl;
    std::cout << "types of models: " << GetTypesOfModels() << std::endl;
    std::cout << "detail price: " << GetDetailPrice() << std::endl;
    std::cout << "number of employees per part: " << GetNumberEmployeesPerPart() << std::endl;
    std::cout << "Engine Capacity: " << GetEngineCapacity() << std::endl;
    std::cout << std::endl << "Custom fields:" << std::endl;
    std::cout << std::endl << "Driving Mode: " << convertingIntoString() << std::endl << std::endl << std::endl;
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


