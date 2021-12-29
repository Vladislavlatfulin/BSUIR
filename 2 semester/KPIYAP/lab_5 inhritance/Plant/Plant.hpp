#ifndef Plant_hpp
#define Plant_hpp

#include <iostream>

class Plant {
protected:
    int factoryPrice;
public:
    Plant(int);
    virtual ~Plant();
    virtual void Display();
    int GetFactoryPrice();
    void SetFactoryPrice(int);
};

#endif 
