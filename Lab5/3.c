// Name: Sameer Raj
// Roll number: 1801CS42
// Task 3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
void* cuberoot(void *data) {
    double *calCBRT = malloc(sizeof(double) * 1000);        // Declare the double array using malloc
    for(int i = 0; i < 1000; i++) {
        double lo = 0.0, hi = 10.0;             // Binary search to calculate the cube root of the values 
        while(hi - lo > 1e-9) {
            double mid = (lo + hi) / 2;
            if((double)mid * mid * mid >= (double)i) {
                hi = mid;
            }
            else lo = mid;

        }
        calCBRT[i] = lo;
    }
    return (void *) calCBRT;        // Return double array
}
int main() {
    pthread_t TID;      // Thread unique identifier
    void *ptr;          // Pointer to store return array
    pthread_create(&TID, NULL, cuberoot, NULL);     // Create thread
    printf("Computation underprocess. Please wait...\n");
    pthread_join(TID, &ptr);                // Join the threads and take return pointer in ptr
    for(int i = 0; i < 1000; i++) {
        printf("The cube root of %d is: %lf\n", i, ((double *)ptr)[i]);     // Print the cube root
    }
    return 0;
}

