// Name: Sameer Raj
// Roll number: 1801CS42
// Task 3
// Assignment 8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include<semaphore.h>
#include<string.h>
#define N 5     // Total philosopers
// Allocation matrix: process P[i][j] = 1 is: process i currently allocated 1 instances of Resources type j in the system.
// Request matrix: Recourse requsted for execution
sem_t forks[N];             // Semaphore for forks
sem_t mutex;               // semaphore to sync
sem_t breakProg;            // semaphore to check when all threads completed and break the program
int times = 1;
int cnt = 5;                
int allocationMatrix[N][N], requestMatrix[N][N];        // As per ques
int left(int element) {             // returns left fork of philosopher
    return element;
}
int right(int element) {            // returns right fork of philosopher
    return (element + 1) % N;
}
void print(int philID, char *c) {                      // Prints the allocation and request matrix
    int i, j;
    if(philID >= 0)
        printf("Allocation matrix when philosopher %d %s: \n", philID, c);
    else printf("Allocation matrix when %s:\n", c);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", allocationMatrix[i][j]);
        } printf("\n");
    }
    if(philID >= 0)
        printf("Request matrix when philosopher %d %s: \n", philID, c);
    else printf("Request matrix when %s:\n", c);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", requestMatrix[i][j]);
        } printf("\n");
    }
    return;
}
void checkDeadlock() {              // This function check for deadlock and if deadlock is present it drop left fork of random philosopher
    bool isDeadlock = true;
    int i, j;
    for(i = 0; i < N; i++) {
        if(allocationMatrix[i][left(i)] == 0) {     // If every philosopher is holding left fork then deadlock is present
            isDeadlock = false;
            break;
        }
    }
    if(!isDeadlock)     // If no deadlock do nothing
        return;
    char cd[50] = "after preemting to remove deadlock";
    sem_wait(&mutex);
    printf("Parent detects deadlock, going to initiate recovery\n");
    char c[50] = "deadlock found";
    print(-1, c);
    int philToDrop = rand() % 5;        // Else select a random philosopher
    sem_post(&forks[left(philToDrop)]);    // Drop the left fork

    printf("Parent preempts Philosopher %d\n", philToDrop);
    allocationMatrix[philToDrop][left(philToDrop)] = 0; // Change in allocation matrix
    
    print(-1, cd);
    sem_post(&mutex);
    return;
}
void pickFork(int philID, int forkToPick, int st) {
    char c[50];
    if(st == 0) strcpy(c, "waiting for left fork");
    else strcpy(c, "waiting for right fork");
    
    sem_wait(&mutex);       //  To prevent request and allocation matrix getting changed
    if(!st) printf("Philosopher %d waiting for left fork\n", philID);
    else printf("Philosopher %d waiting for right fork\n", philID);
    requestMatrix[philID][forkToPick] = 1;
    sem_post(&mutex);       // Release mutex
      
    sem_wait(&forks[forkToPick]);           // Pick the fork, wait until fork is ready to be picked
    if(st == 0) strcpy(c, "picked left fork");
    else strcpy(c, "picked right fork");

    sem_wait(&mutex);
    requestMatrix[philID][forkToPick] = 0;  // Chanage allocation and request matrix
    allocationMatrix[philID][forkToPick] = 1;
    if(!st) printf("Philosopher %d grabs fork %d (left)\n", philID, left(philID));
    else printf("Philosopher %d grabs fork %d (right)\n", philID, right(philID));
    print(philID, c);
    sem_post(&mutex);

}

void releaseFork(int philID) {
    char c[] = "released both forks";
    sem_wait(&mutex);
    sem_post(&forks[left(philID)]);     // Drop the fork
    sem_post(&forks[right(philID)]);
    allocationMatrix[philID][left(philID)] = 0;
    allocationMatrix[philID][right(philID)] = 0;
    printf("Philosopher %d ends eating and releases forks %d (left) and %d (right)\n", philID, left(philID), right(philID));
    print(philID, c);
    sem_post(&mutex);
}
void* diningPhilosophers(void *data) {

    int philID = *((int *) data), i = 0;
    for(i = 0 ; i < times; i++) {       // Run 20 times for simulation
        printf("Philosopher %d starts thinking\n", philID);
        sleep(rand() % 3);
        
        pickFork(philID, left(philID), 0);     // pick left fork
                  
        sleep(rand() % 3);    // wait for some time
           
        pickFork(philID, right(philID), 1);        // pick right fork              
        
        if(allocationMatrix[philID][left(philID)] == 0) {       // This happens when deadlock, it drop left fork, and if right is present and try taking left one
            pickFork(philID, left(philID), 0); 
        }    // check if left is dropped due to deadlock
            
        printf("Philosopher %d starts eating.\n", philID);
        // philosopher eating..............
        sleep(rand() % 3);
        // philosopher eating..............
        releaseFork(philID);       // philosopers finishes eating, releaseForks the forks
        
    }
    sem_wait(&breakProg);
    cnt--;      // one philosoper exits
    sem_post(&breakProg); 
    return NULL;        // Return NULL
}

int main(int argc, char const *argv[]) {
    if(argc == 2) {
        times = atoi(argv[1]);
    }
    srand(time(NULL));
    pthread_t TID[N];      // Thread unique identifier
    int i;
    for(i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);      // Initialize semaphores for each fork
    sem_init(&mutex, 0, 1);    // Initialize semaphore for priting
    sem_init(&breakProg, 0, 1); 
    int index[N];                   //Thread index
    for(i = 0; i < N; i++) {
        index[i] = i;
    	int err = pthread_create(&TID[i], NULL, diningPhilosophers, (void *)(index + i));  // Create thread for each philosopher
        if(err != 0) {              // Error in pthread_create()
            printf("Error: pthread_create failed, exiting!\n");
        }
    }
    while(cnt > 0) {
        checkDeadlock();        // check for deadlock
    }
    for(int i = 0; i < N; i++) {
    	pthread_join(TID[i], NULL);	// Join the threads
    }       
    return 0;
}

