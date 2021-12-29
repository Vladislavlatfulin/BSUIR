
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
    if (this -> isFull()) {
        throw SetException("Set is Full!", 1);
    }
    if (CheckingUniqueness(value)) {
        throw SetException("the given element is already in the set!", 4);
    }
    (*this)[++topIndex] = value;
    return true;
}

template<class T, int maxSize>
const T &Set<T, maxSize>::Remove() {
    if (this -> isEmpty()) {
        throw SetException("Set is empty!", 2);
    }
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
    
    if ((*this).size() + set.size() > newSet.getMaxSetSize()) {
        throw SetException("Not enough memory to sum", 3);
    }
    
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
        throw "Set is empty!";
    } else {
        for (int i = 0; i < set.size(); i++) {
            std::cout << set[i] << "(" << i << ")" << ' ';
        }
    }
    std::cout << std::endl;
}

template<int maxSize>
void print(Set<char *, maxSize> &set) {
    if (set.isEmpty()) {
        throw "Set is empty!";
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
        if (value == (*this)[i]) { return true; }
    }
    return false;
}

template <class T, int MaxSize>
int Set<T, MaxSize>:: Find(T value) {
    for (int i = 0; i < this -> size(); i++) {
        if ((*this)[i] == value) { return i; }
    }
    return -1;
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

template<class T, int maxSize>
void Set<T, maxSize>:: ShellSort() {
    if (this -> isEmpty()) {throw SetException("Set is empty!", 2);}
    int i, j;
    T temp;
    int gap, flag;
    for (gap = this -> topIndex + 1; gap > 0; gap /= 2) {
        do {
            flag = 0;
            for (i = 0, j = gap; j < this -> topIndex + 1; i++, j++) {
                if ((*this)[i] > (*this)[j]) {
                    temp = (*this)[i];
                    (*this)[i] = (*this)[j];
                    (*this)[j] = temp;
                    flag = 1;
                }
            }
        } while(flag);
    }
}

template <class T, int maxSize>
void Set<T, maxSize>:: Editing() {
    int choice, number;
   
    do {
        std::cout << "Enter element index: " << std::endl;
        try {
            choice = this -> EnteringANumber();
        } catch (exception &ex) {
            std::cout << ex.what() << std::endl;
        }
    } while (choice > topIndex || choice < 0);
    
    do {
        std:: cout << "Enter new element:" << std::endl;
        try {
            number = this -> EnteringANumber();
        } catch (exception &ex) {
            std::cout << ex.what() << std::endl;
        }
    } while (!number);
    (*this)[choice] = number;
}


template <class T, int maxSize>
int Set<T, maxSize>:: EnteringANumber () {
    char userPercentage[10];
    int IntPercentage = 0;
    rewind(stdin);
    for (int i = 0; i < 10; i++) {
        char c = std::cin.get();
        
        if (i == 0  && c == '\n') {  throw SetException("Error", 99); }
        if ((c < '0' || c > '9')  && c != '\n') { throw SetException("Error!", 99); }
        
        if (c == '\n') {
            userPercentage[i] = '\0';
            IntPercentage = atoi(userPercentage);
            break;
        }
        userPercentage[i] = c;
    }
    
    return IntPercentage;
    
}
