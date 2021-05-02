// Name: Sameer Raj
// Roll number: 1801CS42
// Task 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t PID = fork(); // Create child process by fork command
    if(PID) {       // If the process is parent
        printf("The PID of parent process is: %d\n", getpid()); // Print parent process ID
        sleep(2);   // Sleep for sometime for letting child to complete
        printf("Sleep over, killing zombie process: %d\n", PID);
    } 
    else {          // child process
        printf("The PID of child process is: %d\n", getpid());  // Print child process ID
        printf("Exiting from child process to create zombie process\n");
        exit(0);        // exiting child process
    }
    return 0;
}
