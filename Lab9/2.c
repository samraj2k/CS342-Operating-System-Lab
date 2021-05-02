// Name: Sameer Raj
// Roll number: 1801CS42
// Task 2
// Assignment 9
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

void allocArray(int **ptr, int n) {
    *ptr = (int *)malloc(n * sizeof(int));
    return;
}

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
bool compare(int a[], int b[], int n) {
    int j = 0;
    for(j = 0; j < n; j++) {
        if(b[j] > a[j])
            return false;
    }
    return true;
}
int main() {
    int n, m, i = 0, j = 0, k = 0;
    int *resources, *available, *work;
    int **requestMatrix, **allocationMatrix;
    printf("Enter the no of process: ");         // Take user input
    scanf("%d", &n);
    printf("Enter the no of resources: ");
    scanf("%d", &m);
    // Input total amount of resources
    allocArray(&resources, m);
    for(j = 0; j < m; j++) {
        printf("Total Amount of the Resource R%d: ", j + 1);
        scanf("%d", &resources[j]);
    }
    // Input request matrix
    printf("\nEnter the request matrix:\n");
    allocMatrix(&requestMatrix, n, m);
    for(i = 0; i < n; i++) {
        requestMatrix[i] = (int *)malloc(m * sizeof(int)); 
        for(j = 0; j < m; j++) {
            scanf("%d", &requestMatrix[i][j]);
        }
    }
    // Input allocation matrix
    printf("\nEnter the allocation matrix:\n");
    allocMatrix(&allocationMatrix, n, m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &allocationMatrix[i][j]);
        }
    }
    // Calculate the available resources for each process
    allocArray(&available, m);
    for(j = 0; j < m; j++) {
        int sumJAllocated = 0;
        for(i = 0; i < n; i++)
            sumJAllocated += allocationMatrix[i][j];
        available[j] = resources[j] - sumJAllocated;
    }
    // Algorithm start
    bool *finish;
    initFinish(&finish, n);
    allocArray(&work, m);
    // work = available
    for(j = 0; j < m; j++)
        work[j] = available[j];
    // Outer loop
    for(k = 0; k < n; k++) {
        bool exist = false;
        for(i = 0; i < n; i++) {    // Compare (2nd point)
            if(finish[i] == false && compare(work, requestMatrix[i], m)) {
                finish[i] = true;
                exist = true;
                for(j < 0; j < m; j++) {    // 3rd point
                    work[j] += allocationMatrix[i][j];
                }
                break;
            }
        }
        if(!exist)
            break;
    }
    bool safeState = true;      // 4th point
    for(i = 0; i < n; i++)
        safeState &= finish[i];
    if(safeState) {     // In safe state
        printf("\nSystem in Safe State\n");
    }
    else {      // Deadlock detected
        printf("\nDeadlock detected\n");
    }
    // free matrices
    free(resources), free(available), free(work), free(finish);
    for(i = 0; i < n; i++) {
        free(requestMatrix[i]), free(allocationMatrix[i]);
    }
    free(requestMatrix), free(allocationMatrix);
    return 0;
}

