#ifndef SetException_hpp
#define SetException_hpp

#include "../MyCollection/MyCollection.hpp"
#include "Library.hpp"
template<class T, int maxSize = 10>
class Set:public Collection<T, maxSize> {
   
public:
    int getMaxSetSize();
private:
    int topIndex{-1};
    int EnteringANumber ();
public:
    Set() = default;
    void DeleteAll();
    
public:
    bool Add(const T &value);
    const T &Remove();
    int size() const;
    bool isFull();
    bool isEmpty();
    bool CheckingUniqueness(T);
    int Find(T);
    template<int maxArgSize>
    std::string isSubset(Set<T, maxArgSize> &value);
    template<int maxArgSize>
    bool checkEntry(T number, Set<T, maxArgSize> &value);
    void ShellSort();
    void Editing();
    
public:
    template<int maxArgSize>
    bool operator==(const Set<T, maxArgSize> &stack) const;
    
    template<int maxArgSize>
    bool operator!=(const Set<T, maxArgSize> &stack) const;
    template<int maxArgSize>
    Set<T, (maxSize > maxArgSize) ? maxSize : maxArgSize> operator+(const Set<T, maxArgSize> &stack) const;
};

class SetException: public exception {
private:
    std::string Message;
    int errorCode;
public:
    SetException(std::string Msg, int errorCode) {
        this -> Message = Msg;
        this -> errorCode = errorCode;
    }
    
    const char *what() const noexcept override {
        std::cout << "Error code: " << errorCode << std::endl;
        return Message.c_str();
    }
};

#include "SetException.inl"

#endif
