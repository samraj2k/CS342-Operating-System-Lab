// Name: Sameer Raj
// Roll number: 1801CS42
// Task 1
// Assignment 10
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#define MX 100
#define NN 1000001
int arr[NN], ctr = 1;
bool over = false;
FILE *fptr;
struct node {
	int val;
	struct node *next;
};
struct node* allocNode() {					// for allocating linkedlist node in C
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node -> next = NULL;
	return Node;
}
void deallocate(struct node* ptr, int tot) {		// deallocate the dynamic memory 
	int cnt = 0;
	while(ptr != NULL && cnt < tot) {
		struct node* temp = ptr;
		ptr = ptr -> next;
		free(temp);
		cnt++;
	}
}
void print(struct node *ptr, int tot, int tim) {		// print the pages after every second
	int cnt = 0;
	while(ptr != NULL && cnt < tot) {
		printf("%d\t", ptr -> val);
		ptr = ptr -> next;
		cnt++;
	}
	while(cnt++ < tot)
		printf("X\t");
	printf("at t = %d\n", tim);
}

void solve() {			// Main solve function
	int pages, cur, size = 0, faults = 0, tot = 0, i;		// Define varibales
	bool pagePresent[MX];		// defin and alloacte bool array to check if page is present or not
	for (cur = 0; cur < MX; cur++)
		pagePresent[cur] = false;					
	struct node *head = NULL, *itr = NULL, *change = NULL;	
	if(fscanf(fptr,"%d", &pages) == EOF) {		// Scan the f value if not EOF
		over = true;		
		return;
	}
	printf("Try: %d\n\n", ctr++);
	printf("FIFO:\n");
	while(true) {
		fscanf(fptr, "%d", &cur);
		if(cur == -1)
			break;
		arr[tot] = cur;
		tot++;
		printf("%d ", cur);
	} printf("\n");
	printf("Frame content at each time step t\n");
    for(i = 0; i < pages; i++) {
        printf("F%d\t", i + 1);
    }
    printf("\n");
	print(head, pages, 0);			// Print at start
	for (i = 0; i < tot; i++) {
		cur = arr[i];
		if(!pagePresent[cur]) {			// page is not present
			faults++;
			if(size < pages) {			// all the pages are not allocated in page table
				if(head == NULL) {
					head = allocNode();	// Then only add that page in the end of linkedlist, check if head is NULL
					head -> val = cur;
					head -> next = NULL;
					itr = head;
				}
				else {					
					itr -> next = allocNode();	// head is already present add at end
					itr = itr -> next;
					itr -> val = cur;
					itr -> next = NULL;
				}
				size++;
				if(size == pages) {
					itr -> next = head;
					change = head;
				}
			}
			else {					// Change the front node the oldest one
				pagePresent[change -> val] = false;
				change -> val = cur;
				change = change -> next;
			}	
			pagePresent[cur] = true;			// Make that new page as present
		}	
		print(head, pages, i + 1);			// print each time
	}
	deallocate(head, pages);		// deallocate the memory
	printf("#Page Faults: %d\n", faults);		// Print the page faults
	printf("-------------------------------------------------------------------\n\n");
}
int main() {
	fptr = fopen("pages.txt", "r");		// open file
	if(fptr == NULL) {		// If file not found
		printf("Error: File not found!\n");
	}
	while(!over) {		// Till file content not over
		solve();
	}
	
	fclose(fptr);
}