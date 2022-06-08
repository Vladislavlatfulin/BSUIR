#pragma once

#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct Circle {
    char message[255];
    unsigned int added;
    unsigned int deleted;
    int left;
    int right;
    int current;
    key_t key;
    unsigned long long checksum;
};

void addToCircle(struct Circle **toAdd);
