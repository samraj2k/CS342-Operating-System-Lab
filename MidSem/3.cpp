// Name: Sameer Raj
// Roll No: 1801CS42
// Task 3
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
        cin >> process[i][0] >> process[i][1] >> process[i][3];
        sum += process[i][3];
        process[i][1] *= -1;
    }
    
    sort(process.begin(), process.end());       // Sort as per arrival time
    vector<int> lastExec(n);
    for(int i = 0; i < n; i++)
        lastExec[i] = process[i][0];
    int lastFinished = process[0][0], totWait = 0;
    for(int i = 0; i < n;) {
        int cur = -1, prior = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(!fin[j]) {
                cur = j, prior = process[j][1];
                break;
            }
        }
        for(int j = 0; j < n; j++) { // This loop chooses the next process (preemtive) which has max priority
            if(!fin[j] and process[j][0] <= lastFinished and process[j][1] < prior) {
                cur = j, prior = process[j][1];
            }
        }
        lastFinished = max(lastFinished, process[cur][0]);     
        int next = -1;
        for(int j = 0; j < n; j++) {
            if(process[j][0] > lastFinished) {
                next = j;
                break;
            }
        }
        if(next == -1 or process[next][0] >= lastFinished + process[cur][3]) { // Case 1: The process terminates
            totWait += lastFinished - lastExec[cur];
            lastFinished = lastFinished + process[cur][3];
            order.push_back(process[cur][2]);
            fin[cur] = true;
            i++;
        }
        else {                                                                  // Case 2: The process preempt
            int nextStop = process[next][0];
            totWait += lastFinished - lastExec[cur];
            process[cur][3] -= nextStop - lastFinished;
            lastFinished = nextStop;
            lastExec[cur] = lastFinished;
        }
    }// Turnaround time is wait time + total burst time
    cout << fixed << setprecision(2) << "Wait Time:\n" << (double) totWait / n << "\nTurnaround Time:\n" << (double) (totWait + sum) / n << endl; // Print
    cout << "The completion order of processes is:\n";
    for(int i = 0; i < n; i++)              // Print order
        cout << "P" << order[i] + 1 << " ";
    cout << endl;
 }