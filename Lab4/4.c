// Name: Sameer Raj
// Roll number: 1801CS42
// Task 4
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <string.h>
void merge(char a[][100], int l, int mid, int r, int strPres) {            // Merge sort to merge in O(nlogn)
    char ord[r - l + 1][100];
    int i = l, j = mid + 1, cur = 0;
    for( ; i <= mid && j <= r; ) {
        if((strPres && strcmp(a[i], a[j]) <= 0) || (!strPres && atoi(a[i]) <= atoi(a[j]))) {
            strcpy(ord[cur], a[i]);
            cur++;
            i++;
        }
        else {
            strcpy(ord[cur], a[j]);
            cur++;
            j++;
        }
    }
    while(i <= mid) {
        strcpy(ord[cur], a[i]);
        cur++;
        i++;
    }
    while(j <= r) {
        strcpy(ord[cur], a[j]);
        cur++;
        j++;
    }
    for(i = l; i <= r; i++) {
        strcpy(a[i], ord[i - l]);
    }
    return;
}
void sort(char a[][100], int l, int r, int strPres) {      // SOrt recursive function
    if(r - l <= 0)
        return;
    int mid = (l + r) / 2;
    sort(a, l, mid, strPres);
    sort(a, mid + 1, r, strPres);
    merge(a, l, mid, r, strPres);
}
const int N = 1e5;
int main(int argc, char *argv[]) {      
    if(argc != 3) {             // Invalid input if 2 arument i.e. file1 and file2
        printf("Error: Invalid Input\n");
        return 0;
    }
    pid_t PID = fork();     // Fork to create child process
    wait(NULL);             // Wait for that child to complete since we cant show file2 without copying from file1
    if(PID) {               // Parent process - after child is complete to create more child
        PID = fork();       // Create another child
        wait(NULL);         // And wait it to complete
        if(PID) {           // Parent process - after 2nd child is complete to create more child
            PID = fork();   // Create 3rd child
            wait(NULL);
            if(!PID) {      // In 3rd child pro
                FILE *ptr1;                         // Sort the input
                char c[100];
                int len = 0, i = 0;
                char a[3000][100];
                ptr1 = fopen(argv[2], "r");
                while(fscanf(ptr1, "%s", c) == 1) {
                    strcpy(a[len], c);
                    len++;
                }
                sort(a, 0, len - 1, stringPres);
                fclose(ptr1);
            }

        }
        else {          // 2nd child process
            printf("2nd child process: %d to display content of file2.\n", getpid());
            printf("Parent of 2nd child process is -> %d.\n\n", getppid());
            printf("The content of file2 are:\n");
            FILE *ptr1;             // Iterate over file2 to display its content
            char arr[100];
            ptr1 = fopen(argv[2], "r");
            while(fscanf(ptr1, "%s", arr) == 1) {
                printf("%s\n", arr); // Write the received word to file
            }
            printf("\n");
            fclose(ptr1);       // CLose file pointer
        }
    }
    else {      // 1st child process
        printf("1st child process: %d to copy files.\n", getpid());
        printf("Parent of 1st child process is -> %d.\n\n", getppid());
        FILE *ptr1;                 // Iterate over file1 and write to file2
        FILE *ptr2;
        char arr[100];
        ptr1 = fopen(argv[1], "r");
        ptr2 = fopen(argv[2], "w");
        while(fscanf(ptr1, "%s", arr) == 1) {
            fprintf(ptr2, "%s\n", arr); // Write the received word to file
        }
        fclose(ptr1);           // CLose both file
        fclose(ptr2);
    }
    return 0;
}

