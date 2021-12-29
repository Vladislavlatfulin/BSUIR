#ifndef BMW_hpp
#define BMW_hpp

#include "CarAssembly.hpp"

class BMW: public CarAssembly {
public:
    enum drivingMode {
        Sport,
        Cruise,
        Sity
    };
    
    void Display() override;
    BMW(int, std::string, int, int, int, drivingMode);
    ~BMW() override;
    
    void SetDrivingMode(drivingMode);
    drivingMode GetDrivingMode();
    std::string convertingIntoString();
    int amountDetails() override;
    
private:
    drivingMode mode;
};

#endif 
