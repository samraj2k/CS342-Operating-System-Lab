// Name: Sameer Raj
// Roll No: 1801CS42
// Assignment 6
#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
	int n, sum = 0;
	cin >> n;			// Check input
	if(n <= 0) {			
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
	sort(process.begin(), process.end());		// Sort as per arrival time
	vector<int> lastExec(n);
	for(int i = 0; i < n; i++)
		lastExec[i] = process[i][0];
	int lastFinished = process[0][0], totWait = 0;
	for(int i = 0; i < n;) {
		int cur = -1, tim = INT_MAX, idx = INT_MAX;
		for(int j = 0; j < n; j++) {
			if(!fin[j]) {
				cur = j, tim = process[j][1], idx = process[j][2];
				break;
			}
		}
		for(int j = 0; j < n; j++) { // This loop chooses the next process (preemtive) which has shortest remaining timr
			if(!fin[j] and process[j][0] <= lastFinished and (process[j][1] < tim or (process[j][1] <= tim and process[j][2] < idx))) {
				cur = j, tim = process[j][1], idx = process[j][2];
			}
		}
		lastFinished = max(lastFinished, process[cur][0]);		// Finally update in two case:
		array<int, 3> search = {lastFinished + 1, 0, 0};
		auto next = lower_bound(process.begin(), process.end(), search);
		if(next == process.end() or (*next)[0] >= lastFinished + process[cur][1]) { // Case 1: The process terminates
			totWait += lastFinished - lastExec[cur];
			lastFinished = lastFinished + process[cur][1];
			order.push_back(process[cur][2]);
			fin[cur] = true;
			i++;
		}
		else {																	// Case 2: The process preempt
			int nextStop = (*next)[0];
			totWait += lastFinished - lastExec[cur];
			process[cur][1] -= nextStop - lastFinished;
			lastFinished = nextStop;
			lastExec[cur] = lastFinished;
		}
	}// Turnaround time is wait time + total burst time
	cout << fixed << setprecision(2) << (double) totWait / n << " " << (double) (totWait + sum) / n << endl; // Print
	for(int i = 0; i < n; i++)				// Print order
		cout << "P" << order[i] + 1 << " ";
	cout << endl;
 }