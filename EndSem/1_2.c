#include <stdio.h>
#include <stdlib.h>


int main() {
	int n, totSum = 0;
	/*
	Take input
	*/
	printf("Enter n -> No of processes:\n");
	scanf("%d", &n);
	int c[n];
	printf("Enter the number of copies for each process:\n");
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		totSum += c[i];
	}
	/*
	Max resources required such that deadlock free guarantee fails is:
	resouces < sumOfCopeis - noOfProcess + 1
	*/
	int resources = (totSum - n + 1) - 1;
	printf("Maximum resources r such that deadlock free operation is not guaranteed is:\n%d\n", resources);
	/*
	Min resources required such that deadlock free guarantee holds is:
	resouces >= sumOfCopeis - noOfProcess + 1
	*/
	resources = totSum - n + 1;
	printf("Minimum resources r such that deadlock free operation is guaranteed is:\n%d\n", resources);
}