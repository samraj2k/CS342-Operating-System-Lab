// Name: Sameer Raj
// Roll number: 1801CS42
// Task 3
// Assignment 9
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
int SeqNo = 0;
bool flag = false;
// array alloc in C
void allocArray(int **ptr, int n) {
    *ptr = (int *)malloc(n * sizeof(int));
    return;
}
// Matrix allocation in C
void allocMatrix(int ***ptr, int n, int m) {
    *ptr = (int **)malloc(n * sizeof(int *));
    int i;
    for(i = 0; i < n; i++)
       (*ptr)[i] = (int *)malloc(m * sizeof(int)); 
   return;
}
void initFinish(bool **ptr, int n) {
    *ptr = (bool *)malloc(n * sizeof(bool));
    int i;
    for(i = 0; i < n; i++)
        (*ptr)[i] = false;
    return;
}
void check(int n, int m, int **maxMatrix, int **allocationMatrix, int **requestMatrix, int *available, bool *finish) {
    int i, j, k;
    while (true) {
        for (i = 0, flag = false; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < m; j++) {
                    if (requestMatrix[i][j] <= available[j])
                        continue;
                    else
                        break;
                }
                if (j == m) {
                    for (j = 0; j < m; j++)
                        available[j] += allocationMatrix[i][j];
                    flag = true;
                    finish[i] = true;
                }
            }
        }
        if (!flag) {
            break;
        }
    }
}
int main() {
    int n, m, i = 0, j = 0, k = 0;
    int **maxMatrix, **allocationMatrix, **requestMatrix;
    int *available;
    printf("SIMULATION OF DEADLOCK PREVENTION\n");  
  	printf("Enter number of processes, resources\n");  
  	scanf("%d %d", &n, &m); 
  	printf("Enter allocation matrix\n");  
  	allocMatrix(&allocationMatrix, n, m);
  	for(j = 0; j < m; j++)
    	for(i = 0; i < n; i++) 
      	scanf("%d", &allocationMatrix[i][j]);  

  	printf("Enter max matrix\n");  
  	allocMatrix(&maxMatrix, n, m);
  	for(j = 0; j < m; j++) {
    	for(i = 0; i < n; i++) {
      		scanf("%d", &maxMatrix[i][j]);  
    	}
  	}
    // Input total amount of resources
    allocArray(&available, m);
    printf("Enter available matrix: ");
    for(j = 0; j < m; j++) {
    	scanf("%d", &available[i]);  
  	}
  	allocMatrix(&requestMatrix, n, m);
  	for(i = 0; i < n; i++) {
    	for(j = 0; j < m; j++) {
      		requestMatrix[i][j] = maxMatrix[i][j] - allocationMatrix[i][j];  
    	}
  	} 
    bool *finish;
    initFinish(&finish, n);
	for (k = 0; k < n; k++) {
    	if (!flag) {
        	if (finish[k] == 0) {
            // 1
            	printf("\n\nFailing :Mutual exclusion");
	            for (j = 0; j < m; j++) {
	                // checking for mutual exclusion
	                if (available[j] < requestMatrix[k][j])
	                    available[j] = requestMatrix[k][j];
	            }

	            check(n, m, maxMatrix, allocationMatrix, requestMatrix, available, finish);
	            if (finish[k])
	                printf("\nBy allocating required resources to process %d dead lock is prevented ", k);
	            // 2

	            printf("\nlack of preemption");
	            for (j = 0; j < m; j++) {
	                if (available[j] < requestMatrix[k][j])
	                    available[j] = requestMatrix[k][j];
	                allocationMatrix[k][j] = 0;
	            }

	            check(n, m, maxMatrix, allocationMatrix, requestMatrix, available, finish);
	            if (finish[k])
	                printf("\ndead lock is prevented by allocating needed resources");
	            // 3

	            printf("\nfailing:Hold and Wait condition\n");
	            for (j = 0; j < m; j++) {
	                //checking hold and wait condition*/
	                if (available[j] < requestMatrix[k][j])
	                    available[j] = requestMatrix[k][j];
	            }
	            check(n, m, maxMatrix, allocationMatrix, requestMatrix, available, finish);
	            // avoiding any condition out of 3 can prevent deadlock 
	        }
	    }
	}
    
    free(available), free(finish);
    for(i = 0; i < n; i++) {
        free(requestMatrix[i]), free(allocationMatrix[i]), free(maxMatrix[i]);
    }
    free(requestMatrix), free(allocationMatrix), free(maxMatrix);
    return 0;
}

