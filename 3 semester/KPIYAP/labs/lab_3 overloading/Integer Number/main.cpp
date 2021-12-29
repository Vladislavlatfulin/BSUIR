#include "Integer.hpp"
//
//a * b++ | a * ++b
//встроенный тип из double в Integer

int main(int argc, const char * argv[]) {
    Integer firstNumber(4);
    Integer secondNumber;
    
    
    
    cout << "Before the operation =" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl << endl;
    secondNumber = firstNumber;
    cout << "After the operation =" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl ;
    cout << endl << "------------------------------------" << endl << endl;
    
    cout << "Before the operation ()" << endl;
    cout << "First number: " << firstNumber << endl << endl;
    firstNumber(6);
    cout << "After the operation =" << endl;
    cout << "First number: " << firstNumber << endl;
    cout << endl << "------------------------------------" << endl << endl;
    
    cout << "Before the operation ++(prefix)" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl << endl;
    secondNumber = ++firstNumber;
    cout << "After the operation ++(prefix)" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl << endl;
    
    cout << "Before the operation ++(postfix)" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl << endl;
    secondNumber = firstNumber++;
    cout << "After the operation ++(postfix)" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl;
    cout << endl << "------------------------------------" << endl << endl;
    
    cout << "The operation -(the same type)" << endl;
    cout << "FirstNumber: " << firstNumber << " SecondNumber: " << secondNumber << endl << "After operation -: " << firstNumber - secondNumber << endl;
    cout << endl << "------------------------------------" << endl << endl;

    cout << "The operations >, <" << endl;
    cout << "FirstNumber: " << firstNumber << " SecondNumber: " << secondNumber << endl;
    bool result = firstNumber > secondNumber;
    cout << "Operation >: " << result << endl;
    result = firstNumber < secondNumber;
    cout << "Operation <: " << result << endl;
    cout << endl << "------------------------------------" << endl << endl;

    cout << "Friend function" << endl;
    
    cout << "Before the operation --(prefix)" << endl;
    firstNumber.SetNumber(100);
    secondNumber.SetNumber(50);
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl << endl;
    secondNumber = --firstNumber;
    cout << "After the operation ++(prefix)" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl << endl;
    
    cout << "Before the operation --(postfix)" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl << endl;
    secondNumber = firstNumber--;
    cout << "After the operation --(postfix)" << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << secondNumber << endl;
    cout << endl << "------------------------------------" << endl << endl;
    
    int sumNumber = 10;
    cout << "The operation +(different types)" << endl << "First Number: " << firstNumber << endl <<"Second Number: " << sumNumber << endl <<"Operation +: " << firstNumber + sumNumber << endl;
    cout << endl << "------------------------------------" << endl << endl;
    
    result = firstNumber == sumNumber;
    cout << "The operation ==(different types)" << endl << "First Number: " << firstNumber << endl <<"Second Number: " << sumNumber << endl <<"Operation ==: " << result << endl;
    cout << endl << "------------------------------------" << endl << endl;
    
    
    cout << "Conversion functions(built-in type). Conversion type: int" << endl << "Before conversion " << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << sumNumber << endl;
    sumNumber = static_cast<int>(firstNumber);
    cout << endl << "After conversion " << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << sumNumber << endl;
    cout << endl << "------------------------------------" << endl << endl;

    cout << "Conversion functions(built-in type). Conversion type: USerType" << endl << "Before conversion " << endl;
    UserType user(10, 10);
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << user << endl;
    user = static_cast<UserType>(firstNumber);
    cout << "After conversion " << endl;
    cout << "FirstNumber: " << firstNumber << endl << "SecondNumber: " << user << endl;
    
    cout << endl << "------------------------------------" << endl << endl;
    firstNumber.SetNumber(10);
    secondNumber.SetNumber(20);
    cout << "first number * second number++: " << firstNumber * secondNumber++ << endl;
    cout << "first number * second ++number: " << firstNumber * ++secondNumber << endl;
    
    double doubleNumber = 0.0;
    cout << endl <<"Enter double number: ";
    cin >> doubleNumber;
    cout << "Before the operation Integer(integer number): "<< firstNumber << endl;
    cout << "Before the operation Integer(double number): "<< doubleNumber << endl;
    firstNumber = static_cast<Integer>(doubleNumber);
    cout << endl <<"After the operation Integer(integer number): "<< firstNumber << endl;
    cout << "After the operation Integer(double number): "<< doubleNumber << endl;
    
    return 0;
}
