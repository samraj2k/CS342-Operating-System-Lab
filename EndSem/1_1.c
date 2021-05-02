#include <stdio.h>
#include <stdlib.h>

int main() {
	int c, r;
	printf("Enter the values of c and r:\n");
	scanf("%d %d", &c, &r);
	if(r <= c) {
		printf("Invalid input\n");
		return 0;
	}
	/*
	If c == 1
	Then deadlock can't occur
	*/
	if (c <= 1) {
		printf("Infinite number of processes can run without deadlock satisfying the input.\n");
		return 0;
	}
	/*
	In other cases, max process required will be follow the equation I derived:
	resouces >= noOfProcess * (copies - 1) + 1
	*/
	int noOfProcess = (r - 1) / (c - 1);
	printf("Maximum number of processes to ensure deadlock free operation is:\n%d\n", noOfProcess);
	return 0;
}