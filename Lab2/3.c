// Sameer Raj
// 1801CS42
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This function, as stated in the problem convert the strber in binary form
//63 is taken due to 64 bit integer support in Linux 64-bit
char* binaryForm(long long int give) {
	int i;
	char* ans = (char*)malloc(64 * sizeof(char));
	// This convert the num in binary
	for (i = 0; i < 63; i++) {
		int j = 63 - i - 1;
		int rem = give % 2;
		ans[j] = (char)(rem + '0');
		give /= 2;
	}
	ans[63] = '\0';
	return ans;
}
//This function convert the strber in decimal form
long long int decForm(char* arr) {
	int i;
	long long int formed = 0;
	// This convert in decimal
	for (i = 0; i < 63; ++i) {
		if(arr[i] == '1')
			formed = (long long int)(2 * formed) + 1;
		else 
			formed = (long long int)(2 * formed);
	}
	return formed;
}
//This function, as stated in the problem finds the XOR of two strbers in binary
char* takeXOR(char* str1, char* str2) {
	char* formed = (char*)malloc(64 * sizeof(char));
	int i; 
	// This takes XOR
	for (i = 0; i < 63; ++i) {
		if (str1[i] != str2[i]) {
			formed[i] = '1';
		} 
		else {
			formed[i] = '0';
		}
	}
	formed[63] = '\0';
	return formed;
}

int main(int argc, char* argv[]) {
	// argc = No of arguments
	if (argc != 3) {
		printf("Error: Invalid Input\n");
		return 0;
	}
	// Arguments are stored in array argv
	long long int a, b;
	// The string to number conversion of two numbers
	a = atoi(argv[1]), b = atoi(argv[2]);
	// Convert in binary
	char* form1 = binaryForm(a);
	char* form2 = binaryForm(b);
	// Print the binary form
	printf("The input -> %lld in binary:\n%s\n", a, form1);
	printf("The input -> %lld in binary:\n%s\n", b, form2);
	char* n1 = takeXOR(form1, form2);
	// Print the XOR in binary
	printf("The XOR in binary will be:\n%s\n", n1);
	long long int n2 = decForm(n1);
	// Print the XOR in decimal
	printf("The XOR in decimal will be:\n%lld \n", n2);
	return 0;
}