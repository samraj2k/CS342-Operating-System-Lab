// Name: Sameer Raj
// Roll number: 1801CS42
// Task 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Error: Invalid arguments\n");
        exit(0);
    }
    int n = atoi(argv[1]);              // Input and error check
    if(n <= 0) {
    	printf("Error: Invalid Input\n");
    	exit(0);
    }
    int pip1[2], pip2[2], pip3[2];  // pipes for communication
    if(pipe(pip1) == -1) {
    	printf("Error: Pipe Creation between parent and 1st child failed!\n");
    }
    if(pipe(pip2) == -1) {
    	printf("Error: Pipe Creation between parent and 2st child failed!\n");
    }
    if(pipe(pip3) == -1) {
    	printf("Error: Pipe Creation between parent and 3st child failed!\n");
    }    
    int pid, pid1, pid2;
    pid = fork();
    wait(NULL);
    if(pid == 0) {
    	// first child
    	// this computes the sum of negative numbers i.e. -(1/2 + 1/4 ..)
        printf("1st child to compute sum of negative numbers, PID: %d, Parent PID: %d\n", getpid(), getppid());
    	int cur = 2, i;
    	double ansNeg = 0.0;
    	for(i = 2; i <= n; i += 2) {
    		ansNeg -= (double) 1 / i;
    	}
    	write(pip1[1], &ansNeg, sizeof ansNeg);
    	// here ansNeg is sum of negative numbers
    }
    else {
    	pid1 = fork();
    	wait(NULL);
    	if(pid1 == 0) {
    		// second child
    		// compute the sum of positive prime numbers in the series
            printf("2nd child to compute sum of positive prime numbers, PID: %d, Parent PID: %d\n", getpid(), getppid());
    		double ansPrime = 0.0;
    		int cur = 3, i, j;
    		for(i = 3; i <= n; i += 2) {
    			int num = i;
    			int isPrime = 1;
    			for(j = 2; j * j <= num; j++) {
    				if(num % j == 0) {
    					isPrime = 0;
    					break;
    				}
    			}
    			if(isPrime) {
    				ansPrime += (double) 1 / i;
    			}
    		}
    		write(pip2[1], &ansPrime, sizeof ansPrime);
    	}
    	else {
    		pid2 = fork();
    		wait(NULL);
    		if(pid2 == 0) {
    			// third child
                printf("3rd child to compute sum of positive non-prime numbers, PID: %d, Parent PID: %d\n", getpid(), getppid());
	   			double ansNonPrime = 0.0;
	    		int cur = 1, i, j;
	    		for(i = 1; i <= n; i += 2) {
	    			int num = i;
	    			int isPrime = 1;
	    			for(j = 2; j * j <= num; j++) {
	    				if(num % j == 0) {
	    					isPrime = 0;
	    					break;
	    				}
	    			}
	    			if(isPrime == 0 || i == 1) {
	    				ansNonPrime += (double) 1 / i;
	    			}
	    		}
	    		write(pip3[1], &ansNonPrime, sizeof ansNonPrime);
    		}
    		else {
    			// parent child
                // reads from all the pipes
                // Prints the sum
                printf("Parent to compute and print total sum of n terms of series, PID: %d\n", getpid());
    			double ansNeg, ansPrime, ansNonPrime;
    			read(pip1[0], &ansNeg, sizeof(ansNeg)); 
    			read(pip2[0], &ansPrime, sizeof(ansPrime)); 
    			read(pip3[0], &ansNonPrime, sizeof(ansNonPrime)); 
    			close(pip2[1]), close(pip2[1]), close(pip3[1]);
    			double ansTot = ansNonPrime + ansNeg + ansPrime;
    			printf("The sum of n terms of series is:\n%lf\n", ansTot);
    		}
    	}
    }
    return 0;
}
