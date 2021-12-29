#ifndef complexArray_hpp
#define complexArray_hpp

#include "complexNumber.hpp"

class complexArray {
private:
    int height;
    int width;
    int lenght;
    complexNumber ***userArray;
public:
    complexArray ();
    complexArray(int, int, int);
    complexArray(const complexArray &value);
    ~complexArray();
    
    void Display();
    void allocMemory();
    void SetHeight (int);
    int GetHeight();
    void SetWidth(int);
    int GetWidth();
    void SetLenght(int);
    int GetLenght();
    void FillingArray();
    void sort();
    void sortArray(complexArray**, int lenght);
    complexNumber ***GetArray();
    void SetArray(complexNumber ***);
    int GetRealWithIndex(int, int, int);
    
    void *operator new(size_t);
    void *operator new[](size_t);
    void operator delete(void*);
    void operator delete[](void*);
    complexArray& operator = (complexArray &value);
    
    float AverageValueReal();
    
};
#endif 
