
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdbool.h>

typedef struct Message {
    char string[255];
    bool isEmpty;
} message_t;

struct Circle {
    message_t message[10];
    int added;
    int deleted;
    int head;
    int tail;
    int counter;
};
