#ifndef ProductionMotors_hpp
#define ProductionMotors_hpp

#include "ProductionDetails.hpp"

class ProductionMotors: public ProductionDetails {
private:
    float engineCapacity;
public:
    ProductionMotors(float, int, int, int);
    ~ProductionMotors() override;
    void SetEngineCapacity(float);
    float GetEngineCapacity();
    void Display() override;
};

#endif
