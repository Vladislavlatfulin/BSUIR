
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct Message {
    char message[100];
    int counter;
} message_t;

sem_t *sem;
message_t* msg;

void* listener(void* a) {
    int bufCounter = 0;
    while(1) {
        sem_wait(sem);
        if(msg->counter != bufCounter) {
            printf("%s\n", msg->message);
            bufCounter = msg->counter;
        }
        sem_post(sem);
    }
}

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("File path not mentioned\n");
        exit(errno);
    }

    sem_unlink("/chatik");
    sem = sem_open("/chatik", O_CREAT | O_RDWR, 0777, 1);
    if(sem == SEM_FAILED) {
        printf("semaphore could not opened\n");
        exit(errno);
    }

    char string[100];

    const char *filepath = argv[1];
    int fd = open(filepath, O_RDWR);
    if(fd < 0) {
        printf("%s\n could not opened\n", filepath);
        exit(errno);
    }

    msg = mmap(0, sizeof(message_t), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if(msg == MAP_FAILED) {
        printf("Mapping Failed\n");
        exit(errno);
    }
    msg->counter = 0;
    close(fd);

    pthread_t thread;
    pthread_create(&thread, NULL, listener, NULL);

    while(1) {
        fgets(string, 100, stdin);

        if(strcmp(string, "q\n") == 0)
            break;

        sem_wait(sem);
        strcpy(msg->message, string);
        msg->counter++;
        sem_post(sem);
    }

    sem_unlink("/chatik");

    return 0;
}
