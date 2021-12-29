

template<class T, int maxSize>
int Collection<T, maxSize>::getMaxArraySize() {
    return maxSize;
}

template<class T, int maxSize>
void Collection<T, maxSize>::DeleteAll() {
    for (auto &item: array) {
        item = 0;
    }
}

template<class T, int maxSize>
T &Collection<T, maxSize>::operator[](int index) {
    return array[index];
}

template<class T, int maxSize>
const T &Collection<T, maxSize>::operator[](int index) const {
    assert(0 <= index && index < maxSize);
    return array[index];
}

template<class T, int maxSize>
void Collection<T, maxSize>::print() const {
    for (auto &item: array) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}


