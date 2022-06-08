#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define STRING_SIZE 13
pthread_mutex_t mutex;

void* threadFunc(void* str) {
    pthread_mutex_lock(&mutex);
    char* string = (char*) str;
    
    for(int i = 0; i < STRING_SIZE; i++) {
        putc(string[i], stdout);
        sleep(1);
    }
    
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    char* string1 = "Hello world\n";
    char* string2 = "Goodbye all\n";
    
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread1, NULL, threadFunc, string1);
    pthread_create(&thread2, NULL, threadFunc, string2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}
