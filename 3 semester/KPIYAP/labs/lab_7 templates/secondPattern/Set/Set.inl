template<class T, int maxSize>
int Set<T, maxSize>::getMaxSetSize() {
    return maxSize;
}

template<class T, int maxSize>
void Set<T, maxSize>::DeleteAll() {
    topIndex = -1;
}

template<class T, int maxSize>
bool Set<T, maxSize>::Add(const T &value) {
    assert(!isFull());
    if (CheckingUniqueness(value)) {
        return false;
    }
    (*this)[++topIndex] = value;
    return true;
}

template<class T, int maxSize>
const T &Set<T, maxSize>::Remove() {
    assert(!isEmpty());
    return (*this)[topIndex--];
}

template<class T, int maxSize>
int Set<T, maxSize>::size() const {
    return topIndex + 1;
}

template<class T, int maxSize>
bool Set<T, maxSize>::isFull() {
    return size() == maxSize;
}

template<class T, int maxSize>
bool Set<T, maxSize>::isEmpty() {
    return size() == 0;
}

template<class T, int maxSize>
template<int maxArgSize>
bool Set<T, maxSize>::operator==(const Set<T, maxArgSize> &set) const {
    bool isEqual = true;
    
    if (size() == set.size()) {
        for (int i = 0; i < size(); ++i) {
            if ((*this)[i] != set[i]) {
                isEqual = false;
                break;
            }
        }
    } else {
        isEqual = false;
    }
    
    return isEqual;
}

template<class T, int maxSize>
template<int maxArgSize>
bool Set<T, maxSize>::operator!=(const Set<T, maxArgSize> &set) const {
    return !operator==(set);
}

template<class T, int maxSize>
template<int maxArgSize>
Set<T, (maxSize > maxArgSize) ? maxSize : maxArgSize>
Set<T, maxSize>::operator+(const Set<T, maxArgSize> &set) const {
    
    Set<T, (maxSize > maxArgSize) ? maxSize : maxArgSize> newSet;
    
    assert((*this).size() + set.size() <= newSet.getMaxSetSize());
    
    for (int i = 0; i < set.size(); ++i) {
        newSet.Add(set[i]);
    }
    for (int i = 0; i < (*this).size(); ++i) {
        newSet.Add((*this)[i]);
    }
    
    return newSet;
    
}

template<class T, int maxSize>
void print(Set<T, maxSize> &set) {
    if (set.isEmpty()) {
        std::cout << "Set is empty!";
    } else {
        for (int i = 0; i < set.size(); i++) {
            std::cout << set[i] << ' ';
        }
    }
    std::cout << std::endl;
}

template<int maxSize>
void print(Set<char *, maxSize> &set) {
    if (set.isEmpty()) {
        std::cout << "Set is empty!";
    } else {
        for (int i = 0; i < set.size(); i++) {
            std::cout << set[i] << std::endl;
        }
    }
    std::cout << std::endl;
}

template<class T, int MaxSize>
bool Set<T, MaxSize>:: CheckingUniqueness(T value) {
    for (int i = 0; i < this -> size(); i++) {
        if (value == (*this)[i]) {
            return true;
        }
    }
    return false;
}

template <class T, int MaxSize>
int Set<T, MaxSize>:: Find(T value) {
    for (int i = 0; i < this -> size(); i++) {
        if ((*this)[i] == value) {
            return i;
        }
    }
    return -1;
}


template <class T, int maxSize>
void Set<T, maxSize>:: EnterSet() {
    for (int i = 0; i < maxSize; i++) {
        std::cout << "Set " << i + 1 << " elemment = " ;
        if (!this -> Add(enteringANumber())) {
            std::cout << std::endl << "This element is already in the set!" << std::endl;
            i--;
        }
        std::cout << std::endl;
    }
}

template <class T, int maxSize>
template<int maxArgSize>
bool Set<T, maxSize>:: checkEntry(T number, Set<T, maxArgSize> &value) {
    for (int i = 0; i < maxArgSize; i++) {
        if (number == value[i]) {
            return true;
        }
    }
    return false;
}


template <class T, int maxSize>
template<int maxArgSize>
std::string Set<T, maxSize>:: isSubset(Set<T, maxArgSize> &value) {
    for (int i = 0; i < maxSize; i++) {
        if (this -> checkEntry((*this)[i], value)) {
            for (int k = 0, j = i + 1; (k < maxArgSize - 1 && j < maxSize); j++, k++) {
          
                if (checkEntry((*this)[j], value) == false) {
                    return "is not a subset of";
                }
            }
            return "is a subset of";
        }
    }
    return "";
}

