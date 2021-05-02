// Name: Sameer Raj
// Roll No: 1801CS42
// Assignment 6
#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
	int n, sum = 0;
	cin >> n;
	if(n <= 0) {			// Check input
		cout << "Enter input n: greater than 0." << endl;
		return 0;
	}
	vector<array<int, 3>> process(n);		// Take process input with storing index
	vector<int> order;
	vector<bool> fin(n, false);
	for(int i = 0; i < n; i++) {
		process[i][2] = i;
		cin >> process[i][0] >> process[i][1];
		sum += process[i][1];
	}
	vector<int> lastExec(n);
	for(int i = 0; i < n; i++)
		lastExec[i] = process[i][0];
	int lastFinished = 0, totWait = 0;
	for(int i = 0; i < n;) {
		int cur = -1, tim = 0; 
		for(int j = n - 1; j >= 0; j--) {			// This loop finds the next process to take
			if(!fin[j] and process[j][1] >= tim and process[j][0] <= lastFinished) {
				cur = j;
				tim = process[j][1];
			}
		}
		if(cur == -1) {				// Incase CPU waits as no process is there, this finds next process
			int timTaken = -1, curTaken = INT_MAX;
			for(int j = n - 1; j >= 0; j--) {
				if(!fin[j] and process[j][0] <= curTaken) {
					if(process[j][0] == curTaken and process[j][1] >= timTaken) {
						timTaken = process[j][1];
						cur = j;
					}
					else if(process[j][0] < curTaken) {
						curTaken = process[j][0];
						timTaken = process[j][1];
						cur = j;
					}
				}
			}
		}
		lastFinished = max(lastFinished, process[cur][0]);				// Process
		totWait += lastFinished - lastExec[cur];
		lastFinished++;
		lastExec[cur] = lastFinished;
		process[cur][1]--;
		if(process[cur][1] == 0) {
			fin[cur] = true;
			order.push_back(process[cur][2]);
			i++;
		}
	}
	cout << fixed << setprecision(2) << (double) totWait / n << " " << (double) (totWait + sum) / n << endl; // Print
	for(int i = 0; i < n; i++)				
		cout << "P" << order[i] + 1 << " ";		// Print order
	cout << endl;
 }