#ifndef MyCollection_hpp
#define MyCollection_hpp

#include <cassert>

#include <iostream>
using namespace std;

template<class T, int maxSize = 10>
class Collection {
public:
    int getMaxArraySize();
    Collection() = default;
    virtual void DeleteAll();
    const T &operator[](int index) const;
    T &operator[](int index);
    virtual void print() const final;
    
protected:
    T array[maxSize]{};

};

#include "MyCollection.inl"

#endif 
