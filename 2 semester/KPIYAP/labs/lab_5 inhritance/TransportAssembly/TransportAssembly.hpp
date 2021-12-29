
#ifndef TransportAssembly_hpp
#define TransportAssembly_hpp

#include "Plant.hpp"

class TransportAssembly: public virtual Plant {
private:
    int salary;
public:
    TransportAssembly(int, int);
    ~TransportAssembly() override;
    void Display() override;
    int GetSalary();
    void SetSalary(int);
    
};

#endif
