#include "BMW.hpp"
#include "Library.hpp"

int main()
{
    std::string typesOfModels;
    std::cout << "Enter types of model" << std::endl;
    std::cin >> typesOfModels;
    int factoryPrice, numberOfEmployeesPerPart, detailPrice, yearOfRelease, salary;
    double engineCapacity;
    enterData(&factoryPrice, &salary, &yearOfRelease, &detailPrice, &numberOfEmployeesPerPart, &engineCapacity);
    
    BMW M4(typesOfModels, factoryPrice, salary, yearOfRelease, detailPrice, numberOfEmployeesPerPart, engineCapacity, BMW::drivingMode::Cruise);
    M4.Display();
    
    return 0;
}
