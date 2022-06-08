#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "circle.h"

char* IntToChar(int num) {
    char *line = (char*)malloc(sizeof(char));
    int size = 0;
    int rev_x = 0;

    if(num < 0) {
        line[0] = '-';
        line = (char*)realloc(line, 2*sizeof(char));
        size++;
        rev_x++;
    }

    while(num != 0) {
        char temp = num % 10 + 48;
        num /= 10;
        line[size] = temp;
        size++;
        line = (char*)realloc(line,(size + 2) * sizeof(char));
    }
    line[size] = '\0';
    size--;

    for(;rev_x < size; rev_x++, size--){
        char temp = line[rev_x];
        line[rev_x] = line[size];
        line[size] = temp;
    }

    return line;
}

int main() {
    sem_unlink("semproducer");
    sem_unlink("semconsumer");
    sem_unlink("semmutex");

    sem_t *semProducer = sem_open("semproducer",O_CREAT, 0644, 0);
    sem_t *semConsumer = sem_open("semconsumer",O_CREAT, 0644, 0);
    sem_t *semMutex = sem_open("semmutex",O_CREAT, 0644, 1);

    if(semProducer == SEM_FAILED || semConsumer == SEM_FAILED || semMutex == SEM_FAILED) {
        perror("sem open failed");
        exit(errno);
    }

    int *producerPids = (int*)malloc(sizeof(int));
    int *consumerPids = (int*)malloc(sizeof(int));
    int concumerCount = 0, producerCount = 0, circleCount = 0;
    int *bufPids = NULL;
    int choice;
    pid_t pid;

    struct Circle *circle = NULL;

    while(1) {
        choice = getchar();
        switch (choice) {
            case 'p':
                if(circle == NULL) {
                    printf("circle is empty\n");
                    break;
                }
                pid = fork();

                if(pid == -1) {
                    printf("Fork: Error - %d\n", errno);
                    exit(errno);
                }
                
                if(pid != 0) {
                    producerCount++;
                    bufPids = realloc(producerPids, producerCount * sizeof(int));
                    producerPids = bufPids;
                    producerPids[producerCount - 1] = pid;
                    printf("%d - Producer was created\n", producerPids[producerCount - 1]);
                    sem_post(semProducer);
                } else {
                    char *send = IntToChar(circle->current);
                    execl("./producer", send, NULL);
                }
                break;
            case 'c':
                if(circle == NULL) {
                    printf("circle is empty\n");
                    break;
                }
                pid = fork();

                if(pid == -1) {
                    printf("Fork: Error - %d\n", errno);
                    exit(errno);
                }
                
                if(pid != 0) {
                    concumerCount++;
                    bufPids = realloc(consumerPids, concumerCount * sizeof(int));
                    consumerPids = bufPids;
                    consumerPids[concumerCount - 1] = pid;
                    printf("%d - Consumer was created\n", consumerPids[concumerCount - 1]);
                    sem_post(semConsumer);
                } else {
                    char *send = IntToChar(circle->current);
                    execl("./consumer", send, NULL);
                }
                break;
            case 'P':
                if(producerCount != 0) {
                    kill(producerPids[producerCount - 1], SIGKILL);
                    producerCount--;
                    sem_wait(semProducer);
                    printf("Producer deleted\n");
                } else {
                    printf("No producers\n");
                }
                break;
            case 'C':
                if(concumerCount != 0) {
                    kill(consumerPids[concumerCount - 1], SIGKILL);
                    concumerCount--;
                    sem_wait(semConsumer);
                    printf("Consumer deleted\n");
                } else {
                    printf("No consumers\n");
                }
                break;
            case 'm':
                sem_wait(semMutex);
                addToCircle(&circle);
                circleCount++;
                sem_post(semMutex);
                printf("Circle element created\n");
                break;
            case 'q':
                for(int i = 0; i < producerCount; i++)
                    kill(producerPids[i], SIGKILL);
                for(int i = 0; i < concumerCount; i++)
                    kill(consumerPids[i], SIGKILL);
                
                sem_close(semProducer);
                sem_close(semConsumer);
                sem_close(semMutex);
                sem_unlink("semproducer");
                sem_unlink("semconsumer");
                sem_unlink("semmutex");

                if(circle == NULL)
                    return 0;
                
                int result = 1;
                int nextShmid = circle->current;

                while(result >= 0 && circleCount != 0) {
                    int shmid = nextShmid;

                    if(circleCount > 1)
                        nextShmid = circle->right;
                    
                    result = shmdt(circle);

                    if(result == -1) {
                        perror("Shmdt error\n");
                    }

                    result = shmctl(shmid, IPC_RMID, NULL);

                    if(result == -1) {
                        perror("Shmctl error\n");
                    }

                    circleCount--;

                    if(circleCount > 0)
                        circle = shmat(nextShmid, NULL, 0);

                }

                return 0;
        }
    }
}

