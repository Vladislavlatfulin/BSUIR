#ifndef CarAssembly_hpp
#define CarAssembly_hpp

#include "Plant.hpp"

class CarAssembly: public Plant {
private:
    int yearOfRelease;
    std::string typesOfModels;
public:
    CarAssembly(int, std::string, int, int, int);
    ~CarAssembly();
    void Display() override;
    int GetYearOfRelease();
    std::string GetTypesOfModels();
    void SetTypesOfModels(std::string);
    void SetYearOfRelease(int);
    int amountDetails() override;
};

#endif
