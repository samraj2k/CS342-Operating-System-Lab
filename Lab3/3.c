// Name: Sameer Raj
// Roll number: 1801CS42
// Task 3
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	pid_t id = fork();			// Fork the process, now one child and one parent
	if(!id) {					// If the process is parent
		char* arguments[argc - 2];
		char* file = argv[1];			// File name
		int i = 0;
		for(i = 0; i < argc - 3; i++) {		// This process will open task1.sh file
			arguments[i] = argv[i + 1];		// Making arguments array
		}
		arguments[argc - 3] = NULL;
		execv(file, arguments);				// Calling execv to replace the current process
	}
	else {							// If the process is child
		char* file = argv[argc - 2];	// FIle name
		char* arguments[3];
		int i = 0;
		for(i = 0; i < 3; i++) {
			arguments[i] = NULL;		
		}
		arguments[0] = file, arguments[1] = argv[argc - 1];		// Making arguments array
		execv(file, arguments);				// Calling execv to replace the current process
	}
	return 0;
}