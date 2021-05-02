// Name: Sameer Raj
// Roll number: 1801CS42
// Task 2b

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<pthread.h>
int n, m;
int **A, **B, **C;
void* commutativeChk(void *data) {		// Function to check commutative property
	printf("Thread ID: %ld to check commutativity.\n", pthread_self());
    int **temp1, **temp2, i, j;
    temp1 = (int **)malloc(n * sizeof(int *));
    temp2 = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
		temp1[i] = (int *)malloc(m * sizeof(int)); 
		temp2[i] = (int *)malloc(m * sizeof(int)); 
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			temp1[i][j] = A[i][j] + B[i][j];
			temp2[i][j] = B[i][j] + A[i][j];
		}
	}
	int match = 1;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(temp1[i][j] != temp2[i][j])
				match = 0;
		}
	}
	if(match) {
		printf("Commutative\n");
	}
	else printf("Non-Commutative");
    return NULL;
}
void* assosiativeChk(void *data) {	// Function to check assosiative property
	printf("Thread ID: %ld to check assosiativity.\n", pthread_self());
	int **temp1, **temp2, i, j;
    temp1 = (int **)malloc(n * sizeof(int *));
    temp2 = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
		temp1[i] = (int *)malloc(m * sizeof(int)); 
		temp2[i] = (int *)malloc(m * sizeof(int)); 
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			temp1[i][j] = (A[i][j] + B[i][j]) + C[i][j];
			temp2[i][j] = A[i][j] + (B[i][j] + C[i][j]);
		}
	}
	int match = 1;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(temp1[i][j] != temp2[i][j])
				match = 0;
		}
	}
	if(match) {
		printf("Assosiative\n");
	}
	else printf("Non-Assosiative\n");
    return NULL;
}
void* additiveIdentity(void *data) {	// Function to find additive identity
	printf("Thread ID: %ld to check and print additive identity.\n", pthread_self());
	int **temp1, **zero, i, j;
    temp1 = (int **)malloc(n * sizeof(int *));
    zero = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
		temp1[i] = (int *)malloc(m * sizeof(int)); 
		zero[i] = (int *)malloc(m * sizeof(int)); 
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			temp1[i][j] = (A[i][j] + 0);
			zero[i][j] = 0;
		}
	}
	int match = 1;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(temp1[i][j] != A[i][j])
				match = 0;
		}
	}
	if(match) {
		printf("The additive identity is:\n");
		for(i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				printf("%d ", zero[i][j]);
			} printf("\n");
		}
	}
	else printf("Additive identity does not exist.\n");
    return NULL;
}
void* additiveInverse(void *data) {		// // Function to check additive inverse
	printf("Thread ID: %ld to check and print additive inverse.\n", pthread_self());
    int **temp1, **temp2, i, j;
    temp2 = (int **)malloc(n * sizeof(int *));
    temp1 = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
		temp1[i] = (int *)malloc(m * sizeof(int)); 
		temp2[i] = (int *)malloc(m * sizeof(int)); 
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			temp1[i][j] = (A[i][j] + -A[i][j]);
			temp2[i][j] = (-A[i][j] + A[i][j]);
		}
	}
	int match = 1;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(temp1[i][j] != temp2[i][j])
				match = 0;
		}
	}
	if(match) {
		printf("The additive inverse is:\n");
		for(i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				printf("%d ", -A[i][j]);
			} printf("\n");
		}
	}
	else printf("Additive inverse does not exist.");
    return NULL;
}
int main() {
	int i, j;
	printf("Enter order n  m of the input matrix.\n");
	scanf("%d", &n);	// Take input
	scanf("%d", &m);
	A = (int **)malloc(n * sizeof(int *));		// Make matrices
	B = (int **)malloc(n * sizeof(int *));
	C = (int **)malloc(n * sizeof(int *));
	for(i = 0; i < n; i++) {
		A[i] = (int *)malloc(m * sizeof(int)); 
		B[i] = (int *)malloc(m * sizeof(int)); 
		C[i] = (int *)malloc(m * sizeof(int)); 
	}
	printf("Enter matrix A:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("Enter matrix B:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	printf("Enter matrix C:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			scanf("%d", &C[i][j]);
		}
	}
    pthread_t tAll[4];     // Threads unique identifier		
    pthread_create(&tAll[0], NULL, commutativeChk, NULL);		// create threads
    pthread_join(tAll[0], NULL);  	// join threads
    pthread_create(&tAll[1], NULL, assosiativeChk, NULL);
    pthread_join(tAll[1], NULL);  
    pthread_create(&tAll[2], NULL, additiveIdentity, NULL);
    pthread_join(tAll[2], NULL);  
    pthread_create(&tAll[3], NULL, additiveInverse, NULL);
    pthread_join(tAll[3], NULL);  
    return 0;
}

