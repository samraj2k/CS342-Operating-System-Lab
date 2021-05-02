// Name: Sameer Raj
// Roll number: 1801CS42
// Task 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<pthread.h>
int globalCnt = 0;
void* increment(void *data) {
    static int staticCnt = 0;
    staticCnt++;        // increment static variables
    globalCnt++;        // Increment global variables
    printf("Iteration: %d In thread: %ld the global varibale is: %d, and static variable is: %d.\n", *((int *)data), pthread_self(), globalCnt, staticCnt);
    return (void*) &staticCnt;
}
int main() {
    pthread_t tAll[100000];     // Threads unique identifier
    void *retVal;   
    int i = 0, iter[100000];
    for(i = 0; i < 100000; i++) {
        iter[i] = i + 1;
        pthread_create(&tAll[i], NULL, increment, (void *) &iter[i]);       // Create thread
    }
    for(i = 0; i < 100000; i++) {
        pthread_join(tAll[i], &retVal);            // Join the threads
    }
    printf("The final value of static variable is: %d and global variable is: %d.\n", *((int*) retVal), globalCnt);
    return 0;
}

