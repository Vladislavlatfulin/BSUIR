#ifndef BMW_hpp
#define BMW_hpp

#include "ProductionMotors.hpp"
#include "CarAssembly.hpp"

class BMW: public CarAssembly, public ProductionMotors {
public:
    enum drivingMode {
        Sport,
        Cruise,
        Sity
    };
    
    void Display() override;
    BMW(std::string, int, int, int, int, int, float, drivingMode);
    ~BMW() override;
    
    void SetDrivingMode(drivingMode);
    drivingMode GetDrivingMode();
    std::string convertingIntoString();
    
private:
    drivingMode mode;
};

#endif 
