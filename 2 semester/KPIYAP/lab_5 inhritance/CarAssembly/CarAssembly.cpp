#include "CarAssembly.hpp"

CarAssembly:: CarAssembly(int yearOfrelease, std::string typesOfModels, int salary, int factoryPrice):Plant(factoryPrice) ,TransportAssembly(salary, factoryPrice) {
    std::cout << "Car constructor called " << std::endl;
    SetYearOfRelease(yearOfrelease);
    SetTypesOfModels(typesOfModels);
}


CarAssembly:: ~CarAssembly() {
    std::cout << "Car destructor called " << std::endl;
}

void CarAssembly:: Display() {
    std::cout << "year of release: " << yearOfRelease << std::endl;
    std::cout << "types of models: " << typesOfModels << std::endl;
}

void CarAssembly:: SetYearOfRelease(int yearOfRelease) {
    this -> yearOfRelease = yearOfRelease;
}

int CarAssembly:: GetYearOfRelease() {
    return yearOfRelease;
}

void CarAssembly:: SetTypesOfModels(std::string typesOfModels) {
    this -> typesOfModels = typesOfModels;
}

std::string CarAssembly:: GetTypesOfModels() {
    return typesOfModels;
}
