#ifndef complexNumber_hpp
#define complexNumber_hpp

#include <iostream>

class complexNumber {
private:
    int real;
    int imaginary;
public:
    complexNumber();
    
    int GetReal ();
    int GetImaginary();
    void SetReal(int);
    void SetImaginary(int);
    complexNumber operator +(const complexNumber&);
   
    friend std::ostream &operator<<(std::ostream &out, const complexNumber &value);
};


#endif
