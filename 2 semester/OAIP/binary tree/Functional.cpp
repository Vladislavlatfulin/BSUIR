#include "Functional.hpp"

struct Tree *addNode (struct Tree *treeRoot, char russianWord[20], char englishWord[20]) {
    int conditional;
    if (!treeRoot) {
        treeRoot = (struct Tree*)calloc(1, sizeof(struct Tree));
        strcpy(treeRoot -> words.englishWord, englishWord);
        strcpy(treeRoot -> words.russianWord, russianWord);
        treeRoot -> rightSubtree = treeRoot -> leftSubtree = nullptr;
    }
    else if ((conditional = strcmp(englishWord, treeRoot -> words.englishWord)) < 0) {
        treeRoot -> leftSubtree = addNode(treeRoot -> leftSubtree, russianWord, englishWord);
    }
    else if ((conditional = strcmp(englishWord, treeRoot -> words.englishWord)) > 0) {
        treeRoot -> rightSubtree = addNode(treeRoot -> rightSubtree, russianWord, englishWord);
    }
    else {
        puts("Such a word is already in the dictionary!");
    }
    return treeRoot;
}

int menu () {
    int tempMenu = 0, flag = 0, check;
    
    printf("Enter number for change.\n");
    printf("1 - Adding information.\n");
    printf("2 - Output information.\n");
    printf("3 - Deletion of information\n");
    printf("4 - Search information.\n");
    printf("5 - To finish work.\n");
    
    while (!flag) {
        check = scanf("%d", &tempMenu);
        
        if (dataChecking(check, tempMenu)) {
            rewind(stdin);
            printf("There is no such number. Try to enter again.\n");
            continue;
        }
        
        flag += 1;
    }
    return tempMenu;
}

bool dataChecking (int check, int data) {
    return ((data < 1 || check < 1)? true: false);
}

void recursiveOutput(struct Tree *treeRoot) {
    if (treeRoot) {
        printf("English word: %s\n", treeRoot -> words.englishWord);
        printf("Russian word: %s\n\n", treeRoot -> words.russianWord);
        
        if (treeRoot -> leftSubtree) {
            recursiveOutput(treeRoot -> leftSubtree);
        }
        
        if (treeRoot -> rightSubtree) {
            recursiveOutput(treeRoot -> rightSubtree);
            
        }
    }
}

void outputTree (struct Tree *treeRoot) {
    int choice, check;
    printf("\nChoose method of output.\n");
    printf("1 - Recursive\n");
    printf("2 - Non-recursive\n");
    printf("3 - Exit\n");
    
    do {
        check = scanf("%d", &choice);
        if (choice < 1 || choice > 3 || check < 1) {
            rewind(stdin);
            printf("There is no such number. Try to enter again.\n");
            continue;
        }
    }while(choice < 1 || choice > 3 || check < 1);
    switch (choice) {
        case 1:
            recursiveOutput(treeRoot);
            break;
        case 2:
            nonRecurcive(treeRoot);
            break;
        case 3:
            return;
    }
}

void nonRecurcive(struct Tree *treeRoot) {
    struct Stack *stackElement, *treeElement = nullptr;
    if (!treeRoot) {
        printf("Create a tree.\n");
        return;
        
    }
    bool traffic = true; // признак движения влево по ветви дерева
    
    stackElement = (Stack *)calloc(1, sizeof(Stack));
    stackElement -> tree = treeRoot; // в стек заносится указатель на корень дерева для прохода по поддеревьям
    stackElement -> next = treeElement; // указатель на следующий элемент
    
    
    printf("English word: %s\n", treeRoot -> words.englishWord);
    printf("Russian word: %s\n\n", treeRoot -> words.russianWord);
    
    while (stackElement || treeRoot -> rightSubtree) {
        do { // цикл пока не лист дерева(лист - указатель, у которого нет потомков)
            
            if(traffic && treeRoot -> leftSubtree) { // переход на узел слево
                treeRoot = treeRoot -> leftSubtree;
            }
            
            else if(treeRoot -> rightSubtree) { // переход на узел справо
                treeRoot = treeRoot -> rightSubtree;
                
            }
            traffic = true;
            
            if(treeRoot -> leftSubtree && treeRoot -> rightSubtree) {
                treeElement = stackElement; // в буфер заносим вершину стека
                stackElement = (Stack *)calloc(1, sizeof(Stack));
                stackElement -> tree = treeRoot; // указатель на найденый узел дерева
                stackElement -> next = treeElement;  // указатель из вершины стека на предыдущий 
            }
            
            printf("English word: %s\n", treeRoot -> words.englishWord);
            printf("Russian word: %s\n\n", treeRoot -> words.russianWord);
        } while(treeRoot -> leftSubtree || treeRoot -> rightSubtree);
        
        if (stackElement) {
            treeRoot = stackElement -> tree;
            treeElement = stackElement -> next;
            free(stackElement);
        }
        
        stackElement = treeElement;
        
        if (treeRoot -> leftSubtree && treeRoot ->rightSubtree) {
            traffic = false;
        }
        
        else {
            break;
        }
    }
}

void printOneNode(struct Tree *oneNode) {
    if (!oneNode) {
        printf("Create a tree.\n");
        return;
    }
    printf("English word: %s\n", oneNode -> words.englishWord);
    printf("Russian word: %s\n\n", oneNode -> words.russianWord);
    return;
}

struct Tree *search (struct Tree *oneNode, char userWord[]) {
    if (oneNode) {
        int conditional = strcmp(userWord, oneNode -> words.englishWord);
        
        if ( conditional == 0 ) {
            return oneNode;
        }
        
        if (conditional < 0) {
            return search(oneNode -> leftSubtree, userWord);
        }
        
        if (conditional > 0) {
            return search(oneNode -> rightSubtree, userWord);
        }
    }
    return NULL;
}

void deleteNode(struct Tree **treeNode, char userWord[]) {
    if ((*treeNode) != NULL) {
        
        if ((strcmp((*treeNode) -> words.englishWord, userWord)) == 0) {
            struct Tree *tempPointer = (*treeNode);
            
            if ((*treeNode) -> leftSubtree == NULL && (*treeNode) -> rightSubtree == NULL) {
                (*treeNode) = NULL;
            }
            
            else if ((*treeNode) -> leftSubtree == NULL) {
                (*treeNode) = tempPointer -> rightSubtree;
            }
            
            else if ((*treeNode) -> rightSubtree == NULL) {
                (*treeNode) = tempPointer -> leftSubtree;
            }
            
            else {
                (*treeNode) = tempPointer -> rightSubtree;
                struct Tree **reservePointer;
                reservePointer = treeNode;
                while (*reservePointer != NULL)
                    reservePointer = &((*reservePointer) -> leftSubtree);
                (*reservePointer) = tempPointer -> leftSubtree;
            }
            
            free(tempPointer);
            deleteNode(treeNode, userWord);
        }
        
        else {
            deleteNode(&((*treeNode) -> leftSubtree), userWord);
            deleteNode(&((*treeNode) -> rightSubtree), userWord);
        }
    }
}

void deleteTree (struct Tree **treeRoot) {
    if ((*treeRoot) == NULL) {
        return;
    }
    
    if((*treeRoot) -> leftSubtree)
        deleteTree(&((*treeRoot) -> leftSubtree));
    else if((*treeRoot) -> rightSubtree)
        deleteTree(&((*treeRoot) -> rightSubtree));
    free(*treeRoot);
    *treeRoot = NULL;
}
