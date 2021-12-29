#include "UserType.hpp"


UserType:: UserType(int max, int min) {
    this -> max = max;
    this -> min = min;
}

std::ostream& operator<< (std::ostream &out, const UserType &value) {
    out << "User max: " << value.max << " User min: " << value.min << endl;
    return out;
}
