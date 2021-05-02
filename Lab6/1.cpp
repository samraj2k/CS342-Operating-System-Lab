// Name: Sameer Raj
// Roll No: 1801CS42
// Assignment 6
#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
	int n;	
	cin >> n;
	if(n <= 0) {			// Check input
		cout << "Enter input n: greater than 0." << endl;
		return 0;
	}
	vector<array<int, 3>> process(n); 	// Take process input with storing index
	for(int i = 0; i < n; i++) {
		process[i][1] = i;
		cin >> process[i][0] >> process[i][2];
	}
	sort(process.begin(), process.end());	// Sort as per arrival time
	for(int i = 0; i < n; i++)
		swap(process[i][1], process[i][2]);  // Implementation details
	int lastFinished = process[0][0], totWait = 0, totTurnAround = 0;
	for(int i = 0; i < n; i++) {
		int curProcess = process[i][2]; 
		totWait += max(0LL, lastFinished - process[i][0]); 		// Update waitTime in FCFS order
		totTurnAround += max(0LL, lastFinished - process[i][0]) + process[i][1]; // Similar for turnAround time
		lastFinished = max(lastFinished + process[i][1], process[i][0] + process[i][1]);
	}
	cout << fixed << setprecision(2) << (double) totWait / n << " " << (double)totTurnAround / n << endl; // Print 
	for(int i = 0; i < n; i++)
		cout << "P" << process[i][2] + 1 << " ";			// Print order
	cout << endl;
 }