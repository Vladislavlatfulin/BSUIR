#include "complexArray.hpp"

complexArray:: complexArray() {
    SetLenght(2);
    SetHeight(2);
    SetWidth(2);
    allocMemory();
   
}

complexArray:: complexArray(const complexArray & value) {
    SetLenght(value.lenght);
    SetHeight(value.height);
    SetWidth(value.width);
    
    allocMemory();
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                userArray[i][j][k] = value.userArray[i][j][k]; 
            }
        }
    }
}

complexArray:: ~complexArray() {
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < height; j++) {
            delete [] userArray[i][j];
        }
        delete [] userArray[i];
    }
    delete [] userArray;
}



complexArray:: complexArray (int lenght, int width, int height) {
    SetLenght(lenght);
    SetHeight(height);
    SetWidth(width);
    allocMemory();
}

void complexArray:: Display() {
    for (int i = 0; i < lenght; i++) {
        std::cout << "Level: " << i << std::endl;
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                std::cout << userArray[i][j][k] << "   ";
            }
            std::cout << std::endl;
        }
    }
}

void complexArray:: SetWidth(int width) {
    this -> width = width;
}

void complexArray:: SetHeight(int height) {
    this -> height = height;
}

void complexArray:: SetLenght(int lenght) {
    this -> lenght = lenght;
}

int complexArray:: GetWidth() {
    return width;
}

int complexArray:: GetHeight() {
    return height;
}

int complexArray:: GetLenght() {
    return lenght;
}

void complexArray:: allocMemory() {
    userArray = new complexNumber **[lenght];
    for (int i = 0; i < lenght; i++) {
        userArray[i] = new complexNumber *[height];
        for (int j = 0; j < height; j++) {
            userArray[i][j] = new complexNumber[width];
        }
    }
}

void* complexArray:: operator new(size_t size) {
    std::cout << "Operator new called" << std::endl;
    return :: operator new(size);;
}

void* complexArray:: operator new[](size_t size) {
    std::cout << "Operator new[] called" << std::endl;
    return :: operator new[](size);;
}

void complexArray:: operator delete[](void* pointer) {
    std:: cout << "Called operator delete[]" << std::endl;
    ::operator delete[](pointer);
}

void complexArray:: operator delete(void* pointer) {
    std:: cout << "Called operator delete" << std::endl;
    ::operator delete(pointer);
}

void complexArray:: sort() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < lenght; k++) {
                complexNumber *min = &userArray[i][j][k];
                
                int n = i, m = j, f = k + 1;
                while (n < height) {
                    while (m < width) {
                        while (f < lenght) {
                            if (userArray[n][m][f].GetReal() < min->GetReal()) {
                                min = &userArray[n][m][f];
                            }
                            
                            if (userArray[n][m][f].GetReal() == min -> GetReal() && userArray[n][m][f].GetImaginary() < min -> GetImaginary()) {
                                min = &userArray[n][m][f];
                            }
                            f++;
                        }
                        f = 0;
                        m++;
                    }
                    m = 0;
                    n++;
                }
                int tReal, tImaginary;
                tReal = userArray[i][j][k].GetReal();
                userArray[i][j][k].SetReal(min -> GetReal());
                min -> SetReal(tReal);
                tImaginary = userArray[i][j][k].GetImaginary();
                userArray[i][j][k].SetImaginary(min -> GetImaginary());
                min -> SetImaginary(tImaginary);
                
            }
        }
    }
}

 complexNumber*** complexArray:: GetArray() {
    return userArray;
}

float complexArray:: AverageValueReal() {
    complexNumber temp;
    temp.SetReal(0);
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < height; k++) {
                temp.SetReal(temp.GetReal() + userArray[i][j][k].GetReal());
            }
        }
    }
    float real = (float)temp.GetReal() / (lenght * width * height);
    
    return  real;
}

int complexArray:: GetRealWithIndex(int i, int j, int k) {
    return userArray[i][j][k].GetReal();
}

complexArray& complexArray:: operator=(complexArray& value) {
    
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < height; j++) {
            delete [] userArray[i][j];
        }
        delete [] userArray[i];
    }
    delete [] userArray;
    
    SetLenght(value.lenght);
    SetHeight(value.height);
    SetWidth(value.width);
    
    allocMemory();
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                userArray[i][j][k] = value.userArray[i][j][k];
            }
        }
    }
    
    return *this;
}
