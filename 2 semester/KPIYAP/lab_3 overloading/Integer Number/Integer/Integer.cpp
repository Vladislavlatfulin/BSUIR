#include "Integer.hpp"

void Integer:: SetNumber(int number) {
    this -> number = number;
}

int Integer:: GetNumber() {
    return number;
}

Integer:: Integer() {
    SetNumber(0);
}

Integer:: Integer(int number) {
    SetNumber(number);
}

Integer& operator -- (Integer &value) {
    value.number--;
    return value;
}

Integer operator -- (Integer &value, int) {
    Integer temp(value.number);
    value.number--;
    return temp;
}

std::ostream& operator<< (std::ostream &out, const Integer &value) {
    out <<  value.number;
    return out;
}

Integer& Integer :: operator = (const Integer &userNumber) {
    number = userNumber.number;
    return *this;
}

int Integer:: operator ()(int i) {
    return this -> number += i;
}

Integer& Integer:: operator ++ () {
    ++this -> number;
    return *this;
}

Integer Integer:: operator ++ (int) {
    Integer temp(number);
    
    this -> number += 1;
    return temp;
    
}

Integer Integer:: operator - (const Integer &value) {
    Integer temp;
    temp.number = this -> number - value.number;
    return temp;
}

bool Integer:: operator > (const Integer &value) {
    return (this -> number > value.number);
}

bool Integer:: operator < (const Integer &value) {
    return (this -> number < value.number);
}



int operator + (const Integer &value, const int intNumber) {
    return value.number + intNumber;
}

Integer:: operator int () {
    return number;
}

Integer:: operator UserType () {
    UserType user (static_cast<int>(number + 100), static_cast<int>(number - 100));
    return user;
}

bool operator == (const Integer &value, int number) {
    return (value.number == number);
}

Integer Integer:: operator*(Integer firstValue) {
    return this -> number * firstValue.number;
}


