#include "CarAssembly.hpp"

CarAssembly:: CarAssembly(int yearOfrelease, std::string typesOfModels, int factoryPrice, int amountForDetails, int detailPrice ):Plant(factoryPrice, amountForDetails, detailPrice) {
    std::cout << "Car constructor called " << std::endl;
    SetYearOfRelease(yearOfrelease);
    SetTypesOfModels(typesOfModels);
}

CarAssembly:: ~CarAssembly() {
    std::cout << "Car destructor called " << std::endl;
}

void CarAssembly:: Display() {
    std::cout << "Types of models: " << GetTypesOfModels() << std::endl;
    std::cout << "Year of release: " << GetYearOfRelease() << std::endl;
    std::cout << "Factory price: " << GetFactoryPrice() << std::endl;
    std::cout << "Amount for details: " << GetAmountForDetails() << std::endl;
    std::cout << "Detail price: " << GetDetailPrice() << std::endl;
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

int CarAssembly:: amountDetails() {
    return (GetAmountForDetails() / GetDetailPrice()) * 10;
}
