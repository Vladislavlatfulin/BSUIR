#include "Functional.hpp"

int main () {
    struct Tree *treeRoot = nullptr;
    char russianWord[20], englishWord[20], c;
    char userWord[20];
    
    while (1) {
        switch (menu()) {
            case 1:
                do {
                    printf("Enter russian word.\n");
                    rewind(stdin);
                    fgets(russianWord, 20, stdin);
                    printf("Enter english word.\n");
                    rewind(stdin);
                    fgets(englishWord, 20, stdin);
                    treeRoot = addNode(treeRoot, russianWord, englishWord);
                    printf("Continue? (y - yes, n - no)\n");
                    rewind(stdin);
                    c = getchar();
                    printf("\n");
                }while(c == 'y');
                
                break;
            case 2:
                if (!treeRoot) {
                    printf("Create a tree.\n");
                    break;
                }
                outputTree(treeRoot);
                break;
            case 3:
                if (!treeRoot) {
                    printf("Create a tree.\n");
                    break;
                }
                
                rewind(stdin);
                printf("Enter your word.\n");
                fgets(userWord, 20, stdin);
                deleteNode(&treeRoot, userWord);
                
                break;
            case 4:
                if (!treeRoot) {
                    printf("Create a tree.\n");
                    break;
                }
                
                rewind(stdin);
                printf("Enter your word.\n");
                fgets(userWord, 20, stdin);
                printOneNode(search(treeRoot, userWord));
                break;
            case 5:
                deleteTree(&treeRoot);
                return 0;
            default:
                printf("Choose another function");
                break;
        }
    }
    
    return 0;
}
