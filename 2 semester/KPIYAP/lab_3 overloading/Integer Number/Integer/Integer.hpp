#ifndef Integer_hpp
#define Integer_hpp


#include "UserType.hpp"

class Integer {

private:
    int number;

public:
    int GetNumber ();
    void SetNumber (int);
    Integer();
    Integer(int number);
    
    Integer& operator = (const Integer &userNumber);
    
    int operator ()(int i);
    
    Integer & operator ++ ();
    
    Integer operator ++ (int);
    
    Integer operator - (const Integer &value);
    
    bool operator > (const Integer &value);
    
    bool operator < (const Integer &value);
    Integer operator * (const Integer);
    
    friend Integer& operator -- (Integer &value);
    friend Integer operator -- (Integer &value, int);
    friend int operator + (const Integer &value, const int);
    friend bool operator == (const Integer & value, int number);
    friend std::ostream& operator<< (std::ostream &out, const Integer &value);
    explicit operator int();
    explicit operator UserType();
};



#endif
