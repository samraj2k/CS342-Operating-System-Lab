// Name: Sameer Raj
// Roll number: 1801CS42
// Task 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Error: Invalid Input Format\n");
		return 1;
	}
    int n, m;               // Storing the input number in n, m using the below atoi function
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    int pip1[2], pip2[2]; // File Descriptor declared for both child as pip1 and pip2 respectively.
    int ret1 = pipe(pip1); // Store pip return value
    int ret2 = pipe(pip2);
    if(ret1 == -1 || ret2 == -1) {      // Check if pip was succcesfull or not by the return values
        printf("Error: Declared Pipe communication didn't open as expected/properly.");
        exit(1);
    }
    pid_t PID = fork();     // Fork executed, now there is one parent and one child
    if(PID < 0) {
        printf("Error: Fork unsuccessfull \n");
        exit(2);
    }
    if (PID) {          // For parent process
    	int sumFinal, prodFinal;      // read from pip pipe used for communication 
    	read(pip1[0], &sumFinal, sizeof(int));     
    	read(pip2[0], &prodFinal, sizeof(int));
        if(sumFinal == 0) {
            printf("The division by parent %d: unsuccessfull since division by 0 not possible.\n", getpid()); 
        }
    	else
            printf("The division by parent %d: %d\n", getpid(), prodFinal/ sumFinal); // Print the results
    } 
    else {              // When the process is child
    	PID = fork();  // Forking of child process, now there are two child process
        if(PID < 0) {   // Check if fork was successfull
            printf("Error: Fork unsuccessfull \n");
            exit(2);
        }     
    	if (PID) {     // Child process 1
    		int sum = n + m;  // Calculate the sum
    		printf("Sum by child %d: %d\n", getpid(), sum);
    		write(pip1[1], &sum, sizeof(int));        // Write in pipe communicator
    	}
    	else {         // Child process 2
    		int prod = n * m;     // Calculate the product
    		printf("The multiplication by child %d: %d\n", getpid(), prod);
    		write(pip2[1], &prod, sizeof(int));   // Write in pipe communicator
    	}
    }
    return 0;
}