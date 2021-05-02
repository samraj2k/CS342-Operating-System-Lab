// Name: Sameer Raj
// Roll number: 1801CS42
// Task 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
const int MX = 51;
void* printGroot(void *data) {
    int *cur = (int*)data;
    printf("Hello from groot %ld - I was created in iteration %d\n", pthread_self(), *cur); 
    return NULL;
}
int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Error: Invalid arguments\n");
        exit(0);
    }
    int N = atoi(argv[1]);              // Input and error check
    if(!(N >= 1 && N <= 50)) {
        printf("Error: Only valid input between: 1 to 50 allowed.\n");
        exit(0);
    }  
    pthread_t tAll[MX];             // This array will store thread identifier.
    int iter[MX], i = 1, j = 1;
    for(i = 1; i <= N; i++) {
        iter[i] = i;
        void *ptr = &iter[i];
        pthread_create(&tAll[i], NULL, printGroot, ptr);    // Create the thread
        printf("I am groot %ld. Created new groot(%ld) in iteration %d\n", pthread_self(), tAll[i], i);
        if(i % 5 == 0) {
            sleep(1);                       // Sleep after 5 iterations
        }
    }
    for(j = 1; j <= N; j++) {
        pthread_join(tAll[j], NULL);    // Join the thread with main one, so main doesnt exit before completion of threads.
    }
    return 0;
}
