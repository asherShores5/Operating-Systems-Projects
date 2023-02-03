//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Authors: Asher Shores & Philip Varkey
//Assignment: Assignment 2: Monitors and Semaphores
//Instructor: CST-315, Operating Systems Lecture & Lab
//Date: February 13, 2022,
//This is my own work
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

//Creates the total number of systems in the program
#define THREAD_NUM 2

//Semaphores used to determine the system's state
sem_t semEmpty;
sem_t semFull;

pthread_mutex_t mutexBuffer;

//buffer initialization with a size of 100
int buffer[100];
int count = 0;

void* producer(void* args) {
    while (1) {
        // Produces a random number
        int x = rand() % 100;
        //sleeps for 1 second
        sleep(1);

        // Adds the value to the buffer
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        buffer[count] = x;
        count++;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
        // tells the user that the system has Produced
        printf("Created %d\n", x);
        sleep(1);
    }
}

void* consumer(void* args) {
    while (1) {
        int y;

        // Remove a value from the buffer
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        y = buffer[count - 1];
        count--;
        pthread_mutex_unlock(&mutexBuffer);
        //shows that the system can now add to the buffer using semEmpty
        sem_post(&semEmpty);

        // tells the user that the system has consumed
        printf("Got %d\n", y);
        sleep(1);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    pthread_t th[THREAD_NUM];
    //creates the mutex that is found in pthreads
    pthread_mutex_init(&mutexBuffer, NULL);
    //initializes the semaphores
    sem_init(&semEmpty, 0, 10);
    sem_init(&semFull, 0, 0);
    int i;
    //for loop to iterate over the number of threads
    for (i = 0; i < THREAD_NUM; i++) {
        if (i > 0) {
            if (pthread_create(&th[i], NULL, &producer, NULL) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&th[i], NULL, &consumer, NULL) != 0) {
                perror("Failed to create thread");
            }
        }
    }
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    //removes the semaphores and exits the program
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);
    return 0;
}
