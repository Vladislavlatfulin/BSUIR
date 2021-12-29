#include "functions.hpp"

int main() {
    int countNode = 0, check, numberOfNodeDelete;
    struct Passenger* topOfStack = NULL, *deleteNodes;
    
    while (1) {
        switch (menu()) {
            case 1:
                countNode = push(&topOfStack);
                break;
                
            case 2:
                output(topOfStack, countNode);
                break;
                
            case 3:
                deleteNodes = topOfStack;
                for (int j = 0; j < countNode && deleteNodes; deleteNodes = deleteNodes -> pointer, j++) {
                    outputOneStructure(deleteNodes, j);
                }
                
                printf("Enter delete node number.\n");
                do {
                    check = scanf("%d", &numberOfNodeDelete);
                    if (check < 1 || numberOfNodeDelete <= 0 || numberOfNodeDelete > countNode) {
                        rewind(stdin);
                        printf("There is no such number. Try to enter again.\n");
                        continue;
                    }
                }while (check < 1 || numberOfNodeDelete <= 0 || numberOfNodeDelete > countNode);
                
                deleteNode(&topOfStack, countNode, numberOfNodeDelete);
                break;
                
            case 4:
                search(topOfStack, countNode);
                break;
                
            case 5:
                saveInFile(topOfStack);
                break;
                
            case 6:
                countNode = loadFromFile(&topOfStack);
                break;
                
            case 7:
                while (topOfStack) {
                    deleteNode(&topOfStack, countNode, 1);
                }
                return 0;
                break;
                
            default:
                printf("Choose another option.\n");
                break;
        }
    }
    return 0;
}

