#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define STRING_SIZE 13
pthread_mutex_t mutex;

void* threadFunc(void* str) {
    char* string = (char*) str;
    char* temp;
    while(1) {
        pthread_mutex_lock(&mutex);

        temp = string;
        while (*temp) {
            putc(*temp++, stdout);
            usleep(100000);
        }
        pthread_mutex_unlock(&mutex);
        usleep(100000);

    }
   

    
    return NULL;
}

int main() {
    pthread_t threads[2];
    char * strings[] = {"Hello world\n", "Goodbye all\n"};
    
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, threadFunc, strings[i]);
    }
    
    char c;
    
    while ((c = getchar()) != EOF) {
        switch (c) {
            case 'q':
                for (int i = 0; i < 2; i++) {
                    pthread_cancel(threads[i]);
                }
                exit(0);
                
            
        }
    }
    
    return 0;
}
