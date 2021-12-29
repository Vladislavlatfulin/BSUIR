
#ifndef Set_hpp
#define Set_hpp

#include "../MyCollection/MyCollection.hpp"
#include "Library.hpp"

template<class T, int maxSize = 100>
class Set: public Collection<T, maxSize> {
public:
    int getMaxSetSize();

private:
    int topIndex{-1};

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
    void EnterSet();
    template<int maxArgSize>
    std::string isSubset(Set<T, maxArgSize> &value);
    template<int maxArgSize>
    bool checkEntry(T number, Set<T, maxArgSize> &value);
public:
    template<int maxArgSize>
    bool operator==(const Set<T, maxArgSize> &stack) const;
    
    template<int maxArgSize>
    bool operator!=(const Set<T, maxArgSize> &stack) const;
    template<int maxArgSize>
    Set<T, (maxSize > maxArgSize) ? maxSize : maxArgSize> operator+(const Set<T, maxArgSize> &stack) const;
};

#include "Set.inl"

#endif 
