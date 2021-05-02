// Name: Sameer Raj
// Roll number: 1801CS42
// Task 2
// Significance of orpan process:
/*Orphan process can be usedfor significant purposes. 
A process can be intentionally orphaned to keep it running for exmaple: running in the background or running it for long sessions which don’t need any manual intervention and going to take long time, then we can detach from user session.
The orphans process are running without parent in detached session.
Also in case of crash of parent process, the child process (orphan process) can be helpful in many ways. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t PID = fork(); // Create child process by fork command
    if(PID) {           // If the process is parent
        printf("The PID of parent process is: %d\n", getpid()); // Print parent process ID
    }
    else {
        printf("The PID of child process is: %d\n", getpid());  // Print child process ID
        sleep(10);       // Sleep for sometime for letting parent to complete
        // Print parent process ID after orphan
        printf("The PID of child parent process after making it orphan process is: %d\n", getppid());   
    }
    return 0;
}

