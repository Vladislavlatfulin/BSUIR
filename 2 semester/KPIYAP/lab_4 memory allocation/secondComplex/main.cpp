#include "complexArray.hpp"
#include <time.h>

// отсортировать главный массив по возрастанию

int main() {
    srand(time(nullptr));
    
//    std::cout << "dynamic object selection" << std::endl;
//    complexArray *firstExe = new complexArray(2, 2, 2);
//    std::cout << std::endl << "dynamic selection by copying" << std::endl;
//    complexArray *secondExe = new complexArray(*firstExe);
//
//    std::cout << std:: endl << "before sorting:" << std::endl;
//    std::cout << "first exe: " << std::endl;
//    firstExe -> Display();
//    std::cout << std::endl <<"second exe: " << std::endl;
//    secondExe -> Display();
//
//    std::cout << std:: endl << "after sorting:" << std::endl;
//    secondExe -> sort();
//    std::cout << "first exe: " << std::endl;
//    firstExe -> Display();
//    std::cout << std::endl <<"second exe: " << std::endl;
//    secondExe -> Display();
//    delete firstExe;
//    delete secondExe;
//
    complexArray *array = new complexArray[3];
    
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i <<" Array element " <<  std::endl;
        std::cout << "Average value: " <<array[i].AverageValueReal() << std::endl;
        array[i].Display();
        std::cout << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if(array[i].AverageValueReal() > array[j].AverageValueReal()) {
                complexArray temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    
    
    
    std::cout << std::endl << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i <<" Array element " <<  std::endl;
        std::cout << "Average value: " <<array[i].AverageValueReal() << std::endl;
        array[i].Display();
        std::cout << std::endl;
    }
    
    //        std::cout << "array[0]" << std::endl;
    //        array[0].Display();
    //        std::cout << "array[1]" << std::endl;
    //        array[1].Display();
    //        std::cout << std::endl << "array[0][0][1][1]:" << std::endl;
    //        std::cout << array[0].GetArray()[0][1][1] << std::endl;
    //        std::cout << std::endl << "array[1][1][0][1]:" << std::endl;
    //        std::cout << array[1].GetArray()[1][0][1] << std::endl;
    
    delete [] array;
    
    return 0;
}



