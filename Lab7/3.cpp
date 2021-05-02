// Name: Sameer Raj
// Roll No: 1801CS42
// Task 3
#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
    int n, tq[2], sum = 0;
    cin >> n >> tq[0];           // Check input
    tq[0] = 4, tq[1] = 3;
    if(n <= 0) {            
        cout << "Enter input n: greater than 0." << endl;
        return 0;
    }
    vector<array<int, 4>> process(n);       // Take process input with storing index
    // 0 is arrival
    // 1 is type
    // 2 index
    // 3 is burst
    queue<int> q[2];
    vector<int> order;
    vector<bool> fin(n, false);
    for(int i = 0; i < n; i++) {	// Take input
        cin >> process[i][0] >> process[i][3] >> process[i][1];
        sum += process[i][3];
        process[i][2] = i;
        process[i][1]--;
    }
    sort(process.begin(), process.end());  // Sort as per arrival time
     
    vector<int> lastExec(n); 	// This stored last time process executed
    int lastFinished = process[0][0], totWait = 0; // lastFinished stores the last process execution finish time
    set<int> st; // Processes not pushed in queue
    for(int i = 0; i < n; i++) {
        lastExec[i] = process[i][0];
        if (i) st.insert(i);
    }
    q[process[0][1]].push(0); // Push in 2 circular queue in multilevel queue
    for(int done = 0; done < n; ) {	// Till n process is not over
    	int state = -1, cur;
    	bool finished = false;
        if(!q[0].empty())			// Check  which process to take
        	state = 0;
        else if(!q[1].empty())
        	state = 1;
        cur = q[state].front();	// Next lines are for adding wait time and executing process
        q[state].pop();				// Same as that of round robin Q1
	    lastFinished = max(lastFinished, process[cur][0]);
        int timeOnThis = min(tq[state], process[cur][3]);
        totWait += lastFinished - lastExec[cur];
        lastFinished += timeOnThis;
        lastExec[cur] = lastFinished;
        process[cur][3] -= timeOnThis;
        finished = 1 - min(1LL, process[cur][3]);
        vector<int> eras;
        for(auto to: st){
            if(process[to][0] <= lastFinished) {
                q[process[to][1]].push(to);
                eras.push_back(to);
            }
        }
        for(auto to: eras) st.erase(to);
        if(!finished)
            q[state].push(cur);
        else {
            done++;
            order.push_back(process[cur][2]);
        }
        if(q[0].empty() and q[1].empty() and done < n) {
            q[process[*st.begin()][2]].push(*st.begin());
            st.erase(*st.begin());
        }
    }// Turnaround time is wait time + total burst time
    cout << fixed << setprecision(2) << "Avg_WT = " << (double) totWait / n << " Avg_TAT = " << (double) (totWait + sum) / n << endl; // Print
    for(int i = 0; i < n; i++)              // Print order
        cout << "P" << order[i] + 1 << " ";
    cout << endl;
 }