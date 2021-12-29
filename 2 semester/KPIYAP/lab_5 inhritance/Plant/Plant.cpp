#include "Plant.hpp"

Plant:: Plant(int factoryPrice) {
    std::cout << "Plant constructor called" << std::endl;
    SetFactoryPrice(factoryPrice);
}

Plant:: ~Plant () {
    std::cout << "Plant destructor called" << std::endl;
}

int Plant:: GetFactoryPrice() {
    return factoryPrice;
}

void Plant:: SetFactoryPrice(int factoryPrice) {
    this -> factoryPrice = factoryPrice;
}

void Plant:: Display() {
    std::cout << "factory price: " << factoryPrice << std::endl;
}

