#include "circle.h"

void addToCircle(struct Circle **toAdd) {
    struct Circle *circle;
    key_t key;

    if( (*toAdd) == NULL) {
        key = (key_t)rand()%100;
    } else {
        struct Circle *giveKey = shmat((*toAdd)->left, NULL, 0);
        key = giveKey->key + 1;
        shmdt(giveKey);
    }

    int shmid;

    shmid = shmget(key, sizeof(struct Circle), 0666 | IPC_CREAT);
    circle = shmat(shmid, NULL, 0);

    circle->added = 0;
    circle->deleted = 0;
    circle->message[0] = '\0';
    circle->key = key;
    circle->current = shmid;
    circle->checksum = 0;

    if( (*toAdd) == NULL) {
        (*toAdd) = circle;
        (*toAdd)->left = shmid;
        (*toAdd)->right = shmid;
    }else if( (*toAdd)->right == (*toAdd)->current) {
        circle->left = (*toAdd)->current;
        circle->right = (*toAdd)->current;
        (*toAdd)->left = shmid;
        (*toAdd)->right = shmid;
    }else {
        struct Circle *runner = shmat((*toAdd)->left, NULL, 0);
        circle->right = runner->right;
        circle->left = (*toAdd)->left;
        runner->right = shmid;
        (*toAdd)->left = shmid;
        shmdt(runner);
    }
}
