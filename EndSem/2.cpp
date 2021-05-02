#include<bits/stdc++.h>	
using namespace std;
vector<int> pf[4];
double duration_sec[4];
int fcfs(int n, int k, vector<int> &pageNo) {
	/*
    Function to implement fcfs
    */
	set<int> st;
	vector<int> frames;
	int pageFaults = 0;
	for(int i = 0, mv = 0; i < n; i++) {
		int check = pageNo[i];
		if(st.count(check))
			continue;
		pageFaults++;
		st.insert(check);
		if(frames.size() < k) {
			frames.push_back(check);	
		}		
		else {
			st.erase(frames[mv]);
			frames[mv] = check;
			mv++;
			if(mv == k)
				mv = 0;
		}			
	}
	return pageFaults;
}
int lifo(int n, int k, vector<int> &pageNo) {
	/*
    Function to implement LIFO
    */
	set<int> st;
	vector<int> frames;
	int pageFaults = 0;
	for(int i = 0; i < n; i++) {
		int check = pageNo[i];
		if(st.count(check))
			continue;
		pageFaults++;
		st.insert(check);
		if(frames.size() == k) {
			st.erase(frames.back());
			frames.back() = check;
		}		
		else {
			frames.push_back(check);
		}	
	}
	return pageFaults;
}

int lru(int n, int k, vector<int> &pageNo) {
	/*
    Function to implement LRU
    */
	vector<int> frames;
	int pageFaults = 0;
	map<int, int> timeUsed;
	map<int, int> processPos;
	map<int, int> proTime;
	for(int i = 0; i < n; i++) {
		int check = pageNo[i];
		if(processPos.count(check)) {
			int tim = proTime[check];
			timeUsed.erase(tim);
			proTime[check] = i;
			timeUsed[i] = check;
			continue;
		}
		pageFaults++;
		if(frames.size() < k) {
			processPos[check] = (int)frames.size();
			proTime[check] = i;
			frames.push_back(check);			
			timeUsed[i] = check;
		}
		else {
			auto it = timeUsed.begin();
			int procID = it -> second;
			int idx = processPos[procID];
			timeUsed.erase(it);
			frames[idx] = check;
			processPos.erase(procID);
			processPos[check] = idx;
			timeUsed[i] = check;
			proTime[check] = i;
		}
		
	}
	return pageFaults;
}
int myAlgo(int n, int k, vector<int> &pageNo) {
	/*
    Function to implement MyAlgo
    This algorithm removes the pages which has maxFrequency / maxTimeStayedInQueue (Divide operation)
    If that page is called say x times, and it has stayed in queue foy y secons, then the page with minimum x / y
    is removed.
    This is a direct enhancement of LFU algorithm, but accounts for both the cases
    a) Either it is being least frequently used
    b) Though it is used few times, but has stayed for longer in the memory, and thus given "enough" changes but wasting a page
    With this, we can account for both the characterstics, onstead of relying on only 1.
    This is a better algorithm, but unfortunately takes more time to implement, and also complex to implement on low level.
    But give more meaningful result then LFU, and takes accounts for two criteria: Frequency till now and Time stayed in queue (Ratio is taken)
    */
	set<int> st;
	map<int, int> timeStayed;
	map<int, int> timeCalled;
	int pageFaults = 0;
	vector<int> frames;
	for(int i = 0; i < n; i++) {
		int check = pageNo[i];
		if(!st.count(check)) {
			pageFaults++;
			if(frames.size() < k) {
				frames.push_back(check);	
			}
			else {
				vector<pair<double, int>> comp(k);
				for(int j = 0; j < k; j++) {
					comp[j] = {double(timeCalled[frames[j]] / timeStayed[frames[j]]), j};
				}
				sort(comp.begin(), comp.end());
				int idxRemove = comp[0].second;
				int eleRemove = frames[idxRemove];
				frames[idxRemove] = check;
				st.erase(eleRemove);
			}	
			st.insert(check);
		}
		timeCalled[check]++;
		for(auto to: frames) {
			timeStayed[to]++;
		}
	}
	return pageFaults;
}
void print(int idx, string s) {
	/*
    Function to print page fault for each algo
    */
	cout << s << "\t\t";
	for(auto to: pf[idx]) {
		cout << to << " "; 
	}
	cout << endl;
}
void printTime(double duration_sec[]) {
	cout << "Algorithm\t\tTime Taken(ms)\n";
	cout << "My Algorithm\t\t" << duration_sec[3] << endl;
	cout << "FCFS Algorithm\t\t" << duration_sec[0] << endl;
	cout << "LIFO Algorithm\t\t" << duration_sec[1] << endl;
	cout << "LRU Algorithm\t\t" << duration_sec[2] << endl;
}
void solve(int num) {
	/*
    Solve for each trial
    */
	int k, n;
	cin >> k >> n;
	vector<int> pageNo(n);
	for(int i = 0; i < n; i++)
		cin >> pageNo[i];
	clock_t start, end;
	start = clock();
	end = clock();
    start = clock();

    pf[0].push_back(myAlgo(n, k, pageNo));
    end = clock();
    duration_sec[3] += double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    pf[1].push_back(fcfs(n, k, pageNo));
    fcfs(n, k, pageNo);
    end = clock();
    duration_sec[0] += double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    pf[2].push_back(lifo(n, k, pageNo));
    lifo(n, k, pageNo);
    end = clock();
    duration_sec[1] += double(end-start)/CLOCKS_PER_SEC;

    start = clock();
    pf[3].push_back(lru(n, k, pageNo));
    end = clock();
    duration_sec[2] += double(end-start)/CLOCKS_PER_SEC;
}

int32_t main() {	
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	int num = 1;
	cin >> t;
	while(t--){
		solve(num++);
	}
	cout << "\nPage Faults:\n";
	print(0, "My Algorithm");
	print(1, "FCFS Algorithm");
	print(2, "LIFO Algorithm");
	print(3, "LRU Algorithm");
	cout << endl;
	for(int i = 0; i < 4; i++)
		duration_sec[i] *= 1000000;
	printTime(duration_sec);
	cout << endl << endl;
}