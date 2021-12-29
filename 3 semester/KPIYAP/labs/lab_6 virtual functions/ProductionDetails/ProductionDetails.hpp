#ifndef ProductionDetails_hpp
#define ProductionDetails_hpp

#include "Plant.hpp"

class ProductionDetails: public Plant {
private:
    int numberEmployeesPerPart;

public:
    ProductionDetails(int, int, int, int);
    virtual ~ProductionDetails() override;
    int GetNumberEmployeesPerPart();
    void SetNumberEmployeesPerPart(int);
    void Display() override;
    int amountDetails() override;
};

#endif /* ProductionDetails_hpp */
