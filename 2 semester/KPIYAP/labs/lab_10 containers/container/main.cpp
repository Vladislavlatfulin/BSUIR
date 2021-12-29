#include "List.hpp"
int main(int argc, const char * argv[]) {
    // ввод с клавиатуры
    // сортировка по информации
    // перемещение
    
    
    List<int> intList;
    int count;
    std::cout << "Enter count node: ";
    std::cin >> count;
    
    
    for (int i = 0; i < count; i++) {
        std::cout << "Enter data: ";
        intList.push_back(enteringANumber());
    }
    
    std::cout << std::endl << "Before sort" << std::endl;
    intList.Display();
    intList.sortAcrossContent();
    std::cout << std::endl << std::endl;
    std::cout << "After sort" << std::endl;
    intList.Display();
    intList.Displacement();
    std::cout << std::endl << std::endl;

    intList.Display();
    return 0;
    
}


