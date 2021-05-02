// Name: Sameer Raj
// Roll number: 1801CS42
// Task 3
// Assignment 10
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#define MX 100
#define NN 1000001
#define INT_MAX 1000000000
int arr[NN];
int ctr = 1;
bool over = false;
FILE *fptr;
struct node {
    int val;
    struct node *next;
};

struct node* allocNode() {                  // for allocating linkedlist node in C
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node -> next = NULL;
    return Node;
}
void deallocate(struct node* ptr) {     // deallocate the dynamic memory 
    while(ptr != NULL) {
        struct node* temp = ptr;
        ptr = ptr -> next;
        free(temp);
    }
}
void print(struct node *ptr, int tot, int tim) {        // print the pages after every second
    int cnt = 0;
    while(ptr != NULL) {
        printf("%d\t", ptr -> val);
        ptr = ptr -> next;
        cnt++;
    }
    while(cnt++ < tot)
        printf("X\t");
    printf("at t = %d\n", tim);
}
int findLastUsed(struct node * location[][2], bool pagePresent[], int tim) {
    int i, mn = -1, idx;
    for(i = 0; i < MX; i++) {
        if(!pagePresent[i])
            continue;
        if(location[i][0] == NULL) {
            idx = i;
            break;
        }
        else if(mn < location[i][0] -> val){
            mn = location[i][0] -> val;
            idx = i;
        }
    }
    return idx;
}
void changeNode(int value, struct node* head, int put) {         // remove the least used node from linkedlist
    while(head != NULL) {   
        if(head -> val == value) {
            head -> val = put;
            break;
        } 
        head = head -> next;
    }
    return;
}

void solve() {          // Main solve function
    int pages, cur, size = 0, faults = 0, tot = 0, i;      // Define varibales 
    bool pagePresent[MX];
    struct node* location[MX][2];       // location array stores the head of linkedlist, implemented a vector for making complexity o(frames) in C
    for(i = 0; i < MX; i++) {               // fill with NULL initiallly
        location[i][0] = location[i][1] = NULL;
        pagePresent[i] = false;
    }
    struct node *head = NULL, *itr = NULL;  
    if(fscanf(fptr,"%d", &pages) == EOF) {      // Scan the f value if not EOF
        over = true;        
        return;
    }
    printf("Try: %d\n\n", ctr++);
    printf("Optimal:\n");
    while(true) {
        fscanf(fptr, "%d", &cur);
        if(cur == -1)
            break;
        printf("%d ", cur);
        arr[tot] = cur;
        if(location[cur][0] == NULL) {      // prprocess each page value to store their locations
            location[cur][0] = allocNode();
            location[cur][1] = location[cur][0];
        }
        else {
            location[cur][1] -> next = allocNode();
            location[cur][1] = location[cur][1] -> next;
        }
        location[cur][1] -> val = tot;
        location[cur][1] -> next = NULL;
        tot++;
    } printf("\n");
    printf("Frame content at each time step t\n");
    for(i = 0; i < pages; i++) {
        printf("F%d\t", i + 1);
    }
    printf("\n");
    print(head, pages, 0);            // Print at start
    for (i = 0; i < tot; i++) {
        if(!pagePresent[arr[i]]) {         // page is not present
            faults++;
            if(size < pages) {          // all the pages are not allocated in page table
                if(head == NULL) {
                    head = allocNode(); // Then only add that page in the end of linkedlist, check if head is NULL
                    head -> val = arr[i];
                    head -> next = NULL;
                    itr = head;
                }
                else {                  
                    itr -> next = allocNode();      // head is present just add at end
                    itr = itr -> next;
                    itr -> val = arr[i];
                    itr -> next = NULL;
                }
                size++;
            }
            else {                  // Remove the front from linedlist and add to the end
                int lastUsed = findLastUsed(location, pagePresent, i);  // find fartesht to be used
                pagePresent[lastUsed] = false;
                changeNode(lastUsed, head, arr[i]);
            }   
        } 
        location[arr[i]][0] = location[arr[i]][0] -> next;
        pagePresent[arr[i]] = true;  
        print(head, pages, i + 1);          // print each time
    }
    deallocate(head);       // deallocate the memory
    for(i = 0; i < MX; i++)
        deallocate(location[i][0]), deallocate(location[i][1]);
    printf("#Page Faults: %d\n", faults);     // Print the page faults
    printf("-------------------------------------------------------------------\n\n");
}
int main() {
    fptr = fopen("pages.txt", "r");     // open file
    if(fptr == NULL) {      // If file not found
        printf("Error: File not found!\n");
    }
    while(!over) {      // Till file content not over
        solve();
    }
    
    fclose(fptr);
}

