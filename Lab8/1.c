// Name: Sameer Raj
// Roll number: 1801CS42
// Task 1
// Assignment 8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

pthread_mutex_t lock;   // mutex lock variable

void* f(void *data) {
    int threadID = *((int *) data);
    while(true) {
        if(pthread_mutex_trylock(&lock) == 0){                  // Lock acquired by some thread
            printf("Lock acquired by pthread%d\n", threadID + 1);
            printf("pthread%d is accessing function f()\n", threadID + 1);
            printf("Lock released by pthread%d\n", threadID + 1);
            pthread_mutex_unlock(&lock);                        // Release lock
            break;    
        }
        else {                  // Lock in use by some other thread
            int otherThreadID = threadID ^ 1;
            printf("pthread%d cannot access function f() lock acquired by pthread%d\n", threadID + 1, otherThreadID + 1); 
        } 
    }
    return NULL;        // Return NULL
}

int main() {
    pthread_t TID[2];      // Thread unique identifier
    if (pthread_mutex_init(&lock, NULL) != 0) {     // Inititate lock
        printf("Error: Mutex lock initiation failed, exiting!\n");
        return 0;
    }
    int index[2], i;                   //Thread index
    for(i = 0; i < 2; i++) {
        index[i] = i;
    	int err = pthread_create(&TID[i], NULL, f, (void *)(index + i));  // Create thread
        if(err != 0) {              // Error in pthread_create()
            printf("Error: pthread_create failed, exiting!\n");
        }
    }
    for(i = 0; i < 2; i++) {
    	pthread_join(TID[i], NULL);	// Join the threads
    }       
    pthread_mutex_destroy(&lock);    // Destroy lock!
    return 0;
}

