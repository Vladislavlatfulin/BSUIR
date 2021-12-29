#include "BMW.hpp"
#include "Library.hpp"
#include "ProductionDetails.hpp"    
int main() {
    auto array = new Plant*[3];
    array[0] = new CarAssembly(2021, "M4", 20000, 8000, 500);
    std::cout<< std::endl;
    array[1] = new ProductionDetails(150, 34500, 5800, 350);
    std::cout<< std::endl;
    array[2] = new BMW(2019, "M8", 50000, 80000, 1200, BMW::drivingMode::Cruise);
    
    for (int i = 0; i < 3; i++) {
        std::cout << std::endl << std::endl;
        array[i] -> Display();
        std::cout << "Virtual calculation function: " << array[i] -> amountDetails() << std::endl;
        std::cout << std::endl;
        delete array[i];
    }
    
    delete [] array;
    
    return 0;
}
