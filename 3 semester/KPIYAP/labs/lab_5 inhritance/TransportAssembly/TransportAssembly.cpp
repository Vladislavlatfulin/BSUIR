#include "TransportAssembly.hpp"

TransportAssembly:: TransportAssembly (int salary, int factoryPrice): Plant(factoryPrice) {
    std::cout << "TransportAssembly constructor called " << std::endl;
    SetSalary(salary);
}

TransportAssembly:: ~TransportAssembly () {
    std::cout << "Transport assembly constructor called" << std::endl;
}

int TransportAssembly:: GetSalary() {
    return salary;
}

void TransportAssembly:: SetSalary(int salary) {
    this -> salary = salary;
}

void TransportAssembly:: Display() {
    std::cout << "Salary: " << salary << std::endl;
}


