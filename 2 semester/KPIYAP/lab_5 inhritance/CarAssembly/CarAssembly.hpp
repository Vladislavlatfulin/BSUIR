#ifndef CarAssembly_hpp
#define CarAssembly_hpp

#include "TransportAssembly.hpp"

class CarAssembly: public TransportAssembly {
private:
    int yearOfRelease;
    std::string typesOfModels;
public:
    CarAssembly(int, std::string, int, int);
    ~CarAssembly();
    void Display() override;
    int GetYearOfRelease();
    std::string GetTypesOfModels();
    void SetTypesOfModels(std::string);
    void SetYearOfRelease(int);
};

#endif /* CarAssembly_hpp */
