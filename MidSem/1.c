// Name: Sameer Raj
// Roll number: 1801CS42
// Task 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid, pid1;
    printf("The parent process is: %d.\n", getpid());
    pid = fork();
    if(pid == 0) {
        // first child
        // this child will be zombie process
        printf("The child process (zombie) is: %d and parent is: %d. The parent is sleeping so this process becomes zombie after exit.\n", getpid(), getppid());
        exit(0);
    }
    else {
        // This sleep so that the child process becomes zombie.
        sleep(3);
        printf("Parent sleep finised.\n");
        pid1 = fork();
        if(pid1 == 0) {
            // second child
            // this will be orphan process
            printf("The child process (orphan) is: %d with Parent PID: %d.\n", getpid(), getppid());
            sleep(3);
            printf("Sleep over for child PID: %d, now the Parent ID is: %d\n", getpid(), getppid());
            // This sleep so that orphan process keep alive and parent exits
        }
        else {
            // parent process which exit, so to make one of child orphan
            sleep(1);
            printf("The parent process is: %d (ending)....\n", getpid());
            exit(0);
        }
    }
    return 0;
}
