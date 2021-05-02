// Name: Sameer Raj
// Roll No: 1801CS42
// Assignment 6
#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
	int n;
	cin >> n;		// Check input
	if(n <= 0) {
		cout << "Enter input n: greater than 0." << endl;
		return 0;
	}
	vector<array<int, 3>> process(n);		// Take process input with storing index
	vector<int> order;
	vector<bool> vis(n, false);
	for(int i = 0; i < n; i++) {
		process[i][2] = i;
		cin >> process[i][0] >> process[i][1];
	}
	sort(process.begin(), process.end());		// Sort as per arrival time
	int lastFinished = process[0][0], totWait = 0, totTurnAround = 0;		
	for(int i = 0; i < n; i++) {
		int cur = -1, tim = INT_MAX, idx = INT_MAX;
		for(int j = 0; j < n; j++) {
			if(!vis[j]) {
				cur = j, tim = process[j][1], idx = process[j][2];
				break;
			}
		}
		for(int j = 0; j < n; j++) {
			if(!vis[j] and process[j][0] <= lastFinished and (process[j][1] < tim or (process[j][1] <= tim and process[j][2] < idx))) {
				cur = j, tim = process[j][1], idx = process[j][2];
			}
		}
		lastFinished = max(lastFinished, process[i][0]);
		totWait += lastFinished - process[cur][0];		// Update waitTime in SJF order
		totTurnAround += lastFinished - process[cur][0] + process[cur][1];	// Similar for turnAround time
		lastFinished = lastFinished + process[cur][1];
		order.push_back(process[cur][2]);
		vis[cur] = true;
	}
	cout << fixed << setprecision(2) << (double) totWait / n << " " << (double)totTurnAround / n << endl;	// Print 
	for(int i = 0; i < n; i++)
		cout << "P" << order[i] + 1 << " ";		// Print order
	cout << endl;
 }