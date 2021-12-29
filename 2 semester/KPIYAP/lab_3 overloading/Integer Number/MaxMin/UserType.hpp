#ifndef UserType_hpp
#define UserType_hpp

#include <iostream>
#include <math.h>
using namespace std;

class UserType {
private:
    int max;
    int min;
public:
    explicit  UserType (int max, int min);
    friend std::ostream& operator<< (std::ostream &out, const UserType &value);
};

#endif
