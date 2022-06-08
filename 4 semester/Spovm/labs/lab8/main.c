
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <pthread.h>

#include "circle.h"

struct Circle circle;

sem_t semProducer;
sem_t semConsumer;
pthread_mutex_t mutex;

void* producerFunction(void *a) {
    (void*)a;
    while(1) {
        sem_wait(&semProducer);
        pthread_mutex_lock(&mutex);

       if (circle.counter != 0) {
            if(circle.message[circle.head].isEmpty) {
            int size = rand() % 253;
            for(int i = 0; i < size; i++) {
                int letter = rand() % 26;
                circle.message[circle.head].string[i] = letter + 96;
            }
            circle.message[circle.head].string[size] = '\0';
            circle.added++;
            circle.counter--;
            circle.message[circle.head].isEmpty = false;
            printf("Producer generated message\n");

            if(circle.head == 9) {
                circle.head = 0;
            } else {
                circle.head++;
            }
        }
       }
       else {
           printf("the circle is full\n");
       }

        pthread_mutex_unlock(&mutex);
        sem_post(&semProducer);

        usleep(1000000);
    }
}

void* consumerFunction(void *a) {
    (void*)a;
    while(1) {
        sem_wait(&semConsumer);
        pthread_mutex_lock(&mutex);
        if (circle.counter != 10) {
            if(!circle.message[circle.tail].isEmpty) {
            printf("Consumer read message: %s\n", circle.message[circle.tail].string);

            for(int i = 0; i < 254; i++)
                circle.message[circle.tail].string[i] = '\0';

            circle.deleted++;
            circle.counter++;
            circle.message[circle.tail].isEmpty = true;

            if(circle.tail == 9) {
                circle.tail = 0;
            } else {
                circle.tail++;
            }
            }
        }

       else {
            printf("there are not unread messages\n");
       }

        pthread_mutex_unlock(&mutex);
        sem_post(&semConsumer);

        usleep(1000000);
    }
}

int main() {
    sem_init(&semProducer, 0, 1);
    sem_init(&semConsumer, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    int consumerCount = 0, producerCount = 0;

    for(int i = 0; i < 10; i++) {
        circle.message[i].isEmpty = true;
    }

    circle.added = 0;
    circle.deleted = 0;
    circle.head = 0;
    circle.tail = 0;
    circle.counter = 10;

    pthread_t producers[10];
    pthread_t consumers[10];

    int choice;
    while(1) {
        choice = getchar();

        switch (choice) {
        case 'p':
            if(pthread_create(&producers[producerCount], NULL, producerFunction, NULL) != 0) {
                printf("Pthread_create: Error - %d\n", errno);
                exit(errno);
            }
            producerCount++;
            break;
        case 'c':
            if(pthread_create(&consumers[consumerCount], NULL, consumerFunction, NULL) != 0) {
                printf("Pthread_create: Error - %d\n", errno);
                exit(errno);
            }
            consumerCount++;
            break;
        case 'P':
            if(producerCount > 0) {
                sem_wait(&semProducer);
                pthread_mutex_lock(&mutex);
                pthread_cancel(producers[producerCount - 1]);
                producerCount--;
                pthread_mutex_unlock(&mutex);
                sem_post(&semProducer);
                printf("Producer deleted\n");
            } else {
                printf("No producers\n");
            }
            break;
        case 'C':
            if(consumerCount > 0) {
                sem_wait(&semConsumer);
                pthread_mutex_lock(&mutex);
                pthread_cancel(consumers[consumerCount - 1]);
                consumerCount--;
                pthread_mutex_unlock(&mutex);
                sem_post(&semConsumer);
                printf("Consumer deleted\n");
            } else {
                printf("No consumers\n");
            }
            break;
        case 'q':
            pthread_mutex_destroy(&mutex);
            sem_destroy(&semProducer);
            sem_destroy(&semConsumer);
            return 0;
        }
    }
    return 0;
}
