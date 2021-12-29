#ifndef ProductionDetails_hpp
#define ProductionDetails_hpp

#include "Plant.hpp"

class ProductionDetails: public virtual Plant {
private:
    int detailPrice;
    int numberEmployeesPerPart;

public:
    ProductionDetails(int, int, int);
    virtual ~ProductionDetails() override;
    int GetNumberEmployeesPerPart();
    int GetDetailPrice();
    void SetNumberEmployeesPerPart(int);
    void SetDetailPrice(int);
    void Display() override;
};

#endif /* ProductionDetails_hpp */
