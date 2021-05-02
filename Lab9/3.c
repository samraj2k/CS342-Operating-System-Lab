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
// bool array allocation
void initFinish(bool **ptr, int n) {
    *ptr = (bool *)malloc(n * sizeof(bool));
    int i;
    for(i = 0; i < n; i++)
        (*ptr)[i] = false;
    return;
}
// compare functiom
bool compare(int a[], int b[], int n) {
    int j = 0;
    for(j = 0; j < n; j++) {
        if(b[j] > a[j])
            return false;
    }
    return true;
}
// Pint safe sequence in C
void printSafeSequences(int *work, int **requestMatrix, int **allocationMatrix, bool * finish, int ans[], int n, int m, int pos) {
    int i, j, k, cnt = 0, *curPossible;
    if(pos == n) {      // Print all sequences
        printf("Safe sequence %d: ", SeqNo + 1);
        for(i = 0; i < n - 1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
        SeqNo++;
        return;
    }
    allocArray(&curPossible, n);
    bool exist = false;
    // Banker algorithm
    for(i = 0; i < n; i++) {
        if(finish[i] == false && compare(work, requestMatrix[i], m)) {
            curPossible[cnt++] = i; // find possible indexes
            exist = true;
        }
    }
    if(!exist)
        return;
    for(i = 0; i < cnt; i++) {      // run recusrion on them
        finish[curPossible[i]] = true;
        ans[pos] = curPossible[i];
        for(j = 0; j < m; j++) 
            work[j] += allocationMatrix[curPossible[i]][j];
        // Print all safe sequences using recursion
        printSafeSequences(work, requestMatrix, allocationMatrix, finish, ans, n, m, pos + 1);
        // revert changes
        finish[curPossible[i]] = false;
        for(j = 0; j < m; j++) 
            work[j] -= allocationMatrix[curPossible[i]][j];
    }
    free(curPossible);
    return;
}
int main() {
    int n, m, i = 0, j = 0, k = 0;
    int *available, *work, *ans;
    int **maxMatrix, **allocationMatrix, **requestMatrix;
    printf("Enter the no of process: ");        // Take user input
    scanf("%d", &n);
    printf("Enter the no of resources: ");
    scanf("%d", &m);
    // Input total amount of resources
    allocArray(&available, m);
    for(j = 0; j < m; j++) {
        printf("Total Amount of the Resource R%d: ", j + 1);
        scanf("%d", &available[j]);
    }
    // Input max matrix
    printf("\nEnter the Max matrix:\n");
    allocMatrix(&maxMatrix, n, m);
    for(i = 0; i < n; i++) {
        maxMatrix[i] = (int *)malloc(m * sizeof(int)); 
        printf("P%d ", i);
        for(j = 0; j < m; j++) {
            scanf("%d", &maxMatrix[i][j]);
        }
    }
    // Input allocation matrix
    printf("\nEnter the allocation matrix:\n");
    allocMatrix(&allocationMatrix, n, m);
    allocMatrix(&requestMatrix, n, m);
    for(i = 0; i < n; i++) {
        printf("P%d ", i);
        for(j = 0; j < m; j++) {
            scanf("%d", &allocationMatrix[i][j]);
            requestMatrix[i][j] = maxMatrix[i][j] - allocationMatrix[i][j];
        }
    }
    // Algorithm start
    bool *finish;
    initFinish(&finish, n);
    allocArray(&work, m);
    allocArray(&ans, n);
    // Make work matrix
    for(j = 0; j < m; j++)
        work[j] = available[j];
    // Print safe sequences using Banker algo
    printSafeSequences(work, requestMatrix, allocationMatrix, finish, ans, n, m, 0);
    if(SeqNo == 0) {
        printf("No safe sequence found\n");
    }
    // free memory
    free(available), free(work), free(finish), free(ans);
    for(i = 0; i < n; i++) {
        free(requestMatrix[i]), free(allocationMatrix[i]), free(maxMatrix[i]);
    }
    free(requestMatrix), free(allocationMatrix), free(maxMatrix);
    return 0;
}

