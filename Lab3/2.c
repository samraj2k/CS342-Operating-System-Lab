// Name: Sameer Raj
// Roll number: 1801CS42
// Task 2
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t id1 = fork();		// First fork -> Now two process: Child and Parent
    if (id1 > 0) {			// If the process is parent then go further otherwise child will print Hello at end
        pid_t id2 = fork();		// Again, calling fork, now two children one parent
        if (id2 > 0) {
            pid_t id3 = fork(); // Again, calling fork, now 3 children one parent
            if (id3 > 0) {
                id3 = fork();	// Again, calling fork, now 4 children one parent
            }
        }
    }
    printf("Hello "); 		// Printinh Hello, 4 times by children and one by parent.
}

