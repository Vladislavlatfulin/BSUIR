#include "SetException/SetException.hpp"
#include <exception>

// меню (ввести число, просмотр, редактирование, сортировка(Шелла), удаление)

int main(int argc, const char * argv[]) {
    Set<int, 6> userSet;
    while (1) {
        switch (menu()) {
            case 1:
                if (userSet.isFull()) { break; }
                
                std::cout << "Enter your set " << std::endl;
                
                for (int i = 0; i < 6; i++) {
                    try {
                        std::cout << "Enter set[" << i << "]" << std::endl;
                        userSet.Add(enteringANumber());
                    } catch (exception &ex ) {
                        i--;
                        std::cout << ex.what() << std::endl;
                    }
                }
                
                break;
            case 2:
                try {
                    std::cout << std::endl;
                    print(userSet);
                } catch (const char* ex) {
                    std::cout << ex << std::endl;
                }
                
                break;
            case 3:
                try {
                   
                    std::cout << userSet.Remove();
                    std::cout << " <- deleted item: ";
                } catch (exception &ex) {
                    std::cout << ex.what() << std::endl;
                }
                break;
            case 4:
                try {
                    std::cout << "which element by index do you want to change?" << std::endl;
                    print(userSet);
                    userSet.Editing();
                } catch (const char* ex) {
                    std::cout << ex << std::endl;
                }
                break;
            case 5:
                try {
                    userSet.ShellSort();
                } catch (exception &ex) {
                    std::cout << ex.what() << std::endl;
                }
                break;
            case 6:
                return 0;
            default:
                break;
        }
    }
}

