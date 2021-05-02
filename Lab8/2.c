// Name: Sameer Raj
// Roll number: 1801CS42
// Task 2
// Assignment 8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

pthread_mutex_t lock;   // mutex lock variable
const int N = 10000;    // Max value
int sumPrimes = 0;	// Global variables to share between threads

void* sumOfPrimesLtoR(void *data) {
    int startVal = *((int *)data);
    int i = 0, j = 0;
    for(i = startVal; i <= N; i += 4) {
        bool isPrime = true;
        for(j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime && i != 1) {
            pthread_mutex_lock(&lock);      // Using mutex lock since += is not atomic operation
            sumPrimes += i;                 // Add
            pthread_mutex_unlock(&lock);    // Unlocking mutex lock by this thread operation
        }
    }
    return NULL;        // Return NULL
}

int main() {
    pthread_t TID[4];      // Thread unique identifier
    if (pthread_mutex_init(&lock, NULL) != 0) {     // Inititate lock
        printf("Error: Mutex lock initiation failed, exiting!\n");
        return 0;
    }
    int startVal[4], i;	          // Will store the start
    for(i = 0; i < 4; i++) {
        startVal[i] = i + 1;
    	int err = pthread_create(&TID[i], NULL, sumOfPrimesLtoR, (void *) (startVal + i));  // Create thread
        if(err != 0) {
            printf("Error: pthread_create failed, exiting!\n");
        }
    }
    for(i = 0; i < 4; i++) {
    	pthread_join(TID[i], NULL);	// Join the threads
    }       
    pthread_mutex_destroy(&lock);    // Destroy lock!
    printf("The sum of primes from 1 to 10000 is: %d\n", sumPrimes);     // Print the sum of primes
    return 0;
}

