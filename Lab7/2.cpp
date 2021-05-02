// Name: Sameer Raj
// Roll No: 1801CS42
// Task 2
#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
    int n, sum = 0;
    cin >> n;           // Check input
    if(n <= 0) {            
        cout << "Enter input n: greater than 0." << endl;
        return 0;
    }
    vector<array<int, 4>> process(n);       // Take process input with storing index
    // 3 is burst
    // 1 is priority
    // 0 is arrival
    // 2 is index
    vector<int> order;
    vector<bool> fin(n, false);
    for(int i = 0; i < n; i++) {
        process[i][2] = i;
        cin >> process[i][0] >> process[i][3] >> process[i][1];
        sum += process[i][3];
    }
    sort(process.begin(), process.end());       // Sort as per arrival time
    vector<int> lastExec(n);		// This stored last time process executed
    for(int i = 0; i < n; i++)
        lastExec[i] = process[i][0];
    int lastFinished = process[0][0], totWait = 0;		// lastFinished stores the last process execution finish time
    for(int i = 0; i < n; i++) {			// Till n processes processed
        int cur = -1, prior = INT_MAX;
        for(int j = 0; j < n; j++) {			// Take the next correct process as per priority and current time
            if(fin[j])
            	continue;
            cur = j, prior = process[j][1];
            break;
        }
        for(int j = 0; j < n; j++) { // This loop chooses the next process (preemtive) which has max priority
            if(!fin[j] and process[j][0] <= lastFinished and process[j][1] < prior)
                cur = j, prior = process[j][1];
        }
        lastFinished = max(lastFinished, process[cur][0]);     
        // Process completes execution
        totWait += lastFinished - lastExec[cur];
        lastFinished = lastFinished + process[cur][3];
        order.push_back(process[cur][2]);
        fin[cur] = true;
    }// Turnaround time is wait time + total burst time
    cout << fixed << setprecision(2) << "Avg_WT = " << (double) totWait / n << " Avg_TAT = " << (double) (totWait + sum) / n << endl; // Print
    for(int i = 0; i < n; i++)              // Print order
        cout << "P" << order[i] + 1 << " ";
    cout << endl;
 }