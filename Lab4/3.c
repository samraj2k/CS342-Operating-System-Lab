// Name: Sameer Raj
// Roll number: 1801CS42
// Task 3
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
const int N = 100;
int main(int argc, char *argv[]) {
    if(argc != 2) {     // Invalid input if 1 arument i.e. number is not provided
        printf("Error: Invalid Input\n");
        return 0;
    }
    int pip[2];         // Setup pipe for parent child process communication
    int retPipe = pipe(pip);    // Setup pipe
    if(retPipe == -1) {     // If there is error return
        printf("Error: Unable to create pipe\n");
        return 1;
    }
    pid_t PID = fork();     // Fork to create child process 
    wait(NULL);             // Wait for that child to complete
    if(PID) {               // Parent process - after child is complete
        printf("The %d fibonacci number are:\n", atoi(argv[1]));    // Print the fibonacci numbers
        long long int fib[N];           // This array will contain the fibonacci number that child has calculated
        read(pip[0], fib, sizeof(fib)); // Read from pipe
        int n = atoi(argv[1]);      
        int i = 1;
        for(i = 1; i <= n; i++)         // Print
            printf("%lld ", fib[i]);
        printf("\n");
        close(pip[1]);                  // Close pipe
        printf("The primes fibonacci are:\n");  // Check for prime and print the prime, position
        for(i = 1; i <= n; i++) {
            if(fib[i] == 1)
                continue;
            long long int j = 2;
            int isPrime = 1;
            for(j = 2; j * j <= fib[i]; j++) {
                if(fib[i] % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime) {
                printf("The fibonacci number: %lld at position %d is prime.\n", fib[i], i);
            }
        }
    }
    else {                      // Child process
        int n = atoi(argv[1]);      
        long long int fib[N];   // THis array will store the computed fibonacci 
        fib[0] = 0;
        fib[1] = 1;
        int i = 2;
        for(i = 2; i <= n; i++)     // Calculate the fibonacci number till the given value
            fib[i] = fib[i - 1] + fib[i - 2];
        write(pip[1], fib, sizeof fib); // Write in the pipe
    }
    return 0;   // End of program
}

