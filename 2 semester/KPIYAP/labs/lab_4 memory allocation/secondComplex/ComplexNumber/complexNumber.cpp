#include "complexNumber.hpp"

complexNumber:: complexNumber () {
    real = rand() % 5;
    imaginary = rand() % 5;
}

std::ostream &operator<<(std::ostream &out, const complexNumber &value) {
    out << value.real << "+" << value.imaginary << "i";
   return out;
}

void complexNumber:: SetReal(int real) {
    this -> real = real;
}

void complexNumber:: SetImaginary(int imaginary) {
    this -> imaginary = imaginary;
}

int complexNumber:: GetReal() {
    return real;
}

int complexNumber:: GetImaginary() {
    return imaginary;
}

//complexNumber complexNumber:: operator+(complexNumber &value) {
//    complexNumber temp;
//    temp.
//}
