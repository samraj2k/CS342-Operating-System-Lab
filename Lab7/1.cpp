// Name: Sameer Raj
// Roll No: 1801CS42
// Task 1
#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
    int n, tq, sum = 0;
    cin >> n >> tq;           // Check input
    if(n <= 0) {            
        cout << "Enter input n: greater than 0." << endl;
        return 0;
    }
    vector<array<int, 3>> process(n);       // Take process input with storing index
    // 1 is burst
    // 0 is arrival time
    // 2 is index (initially 1 is index but later swapped)
    queue<int> q;
    vector<int> order;
    vector<bool> fin(n, false);
    for(int i = 0; i < n; i++) {		// Take input
        cin >> process[i][0] >> process[i][2];
        sum += process[i][2];
        process[i][1] = i;
    }
    sort(process.begin(), process.end());	// Sort as per arrival time     
    for(int i = 0; i < n; i++) swap(process[i][1], process[i][2]);
    int lastFinished = process[0][0], totWait = 0;		// lastFinished stores the last process execution finish time
    set<int> st;	// Processes not pushed in queue
    vector<int> lastExec(n);		// This stored last time process executed
    for(int i = 0; i < n; i++) {
        lastExec[i] = process[i][0];
        if (i) st.insert(i);
    }
    q.push(0);		// Push in circular queue
    for(int done = 0; done < n; ) {		// Till n process is not over
        auto cur = q.front();
        q.pop();							// Next lines are for adding wait time and executing process
        lastFinished = max(lastFinished, process[cur][0]);
        int timeOnThis = min(tq, process[cur][1]);
        totWait += lastFinished - lastExec[cur];
        lastFinished += timeOnThis;
        lastExec[cur] = lastFinished;
        process[cur][1] -= timeOnThis;
        bool finished = 1 - min(1LL, process[cur][1]);		// Check if finished
        vector<int> eras;			// Erase the newly pushed processes
        for(auto to: st){
            if(process[to][0] <= lastFinished) {
                q.push(to);
                eras.push_back(to);
            }
        }
        for(auto to: eras) st.erase(to);
        if(!finished)
            q.push(cur);			// If process not finished push again
        else {
            done++;
            order.push_back(process[cur][2]);
        }
        if(q.empty() and done < n) {
            q.push(*st.begin());			// Increase time is no process is remaining 
            st.erase(*st.begin());
        }
    }// Turnaround time is wait time + total burst time
    cout << fixed << setprecision(2) << "Avg_WT = " << (double) totWait / n << " Avg_TAT = " << (double) (totWait + sum) / n << endl; // Print
    for(int i = 0; i < n; i++)              // Print order
        cout << "P" << order[i] + 1 << " ";
    cout << endl;
 }