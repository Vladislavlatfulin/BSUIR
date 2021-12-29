#ifndef Functional_hpp
#define Functional_hpp

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


struct Dictionary {
    char russianWord[20];
    char englishWord[20];
};

struct Tree {
    struct Dictionary words;
    struct Tree *leftSubtree;
    struct Tree *rightSubtree;
};

struct Stack {
    struct Tree *tree;
    struct Stack *next;
};

int menu(void);
bool dataChecking(int, int);
struct Tree *addNode (struct Tree*, char [20], char [20]);
void outputTree (struct Tree *);
void recursiveOutput(struct Tree *);
void nonRecurcive(struct Tree *);
void printOneNode(struct Tree *);
struct Tree* search(struct Tree *, char [20]);
void deleteNode(struct Tree **, char[20]);
void deleteTree (struct Tree **);
#endif
