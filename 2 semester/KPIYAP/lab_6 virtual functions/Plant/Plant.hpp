#ifndef Plant_hpp
#define Plant_hpp

#include <iostream>

class Plant {
private:
    int factoryPrice;
    int amountForDetails;
    int detailPrice;
public:
    Plant(int, int, int);
    virtual ~Plant();
    virtual void Display() = 0;
    virtual int amountDetails() = 0;
    int GetFactoryPrice();
    void SetFactoryPrice(int);
    int GetDetailPrice();
    void SetDetailPrice(int);
    void SetAmountForDetails(int);
    int GetAmountForDetails();
};

#endif 
