#include "Plant.hpp"

Plant:: Plant(int factoryPrice, int amountForDetails, int detailPrice) {
    std::cout << "Plant constructor called" << std::endl;
    SetFactoryPrice(factoryPrice);
    SetAmountForDetails(amountForDetails);
    SetDetailPrice(detailPrice);
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

void Plant:: SetAmountForDetails(int amountForDetails) {
    this -> amountForDetails = amountForDetails;
}

int Plant:: GetAmountForDetails() {
    return amountForDetails;
}

int Plant:: GetDetailPrice() {
    return detailPrice;
}

void Plant:: SetDetailPrice(int detailPrice) {
    this -> detailPrice = detailPrice;
}





