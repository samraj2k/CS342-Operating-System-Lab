#include <bits/stdc++.h>
using namespace std;
#define seekRate 5
pair<int, string> compare[4] = {{0, "FCFS"}, {0, "SCAN"}, {0, "CSCAN"}, {0, "SSTF"}};
void PlotGraph(vector< string >&x , vector< string >&y , string name , string num){
  int total_pts = x.size() ;
  int total_cmds = total_pts + 100 ;
  char *commands[total_cmds] ;

  for(int i = 0 ; i < total_cmds ; i++){
    commands[i] = (char*)malloc(100*sizeof(char)) ;
  }
  int idx = 0 ;
  string ini = "set term wxt " + num ;
  strcpy(commands[idx++],ini.c_str()) ; 
  string title = "set title \"" + name + "\"" ;
  strcpy(commands[idx++],title.c_str()) ;
  for(int i = 0 ; i < total_pts ; i++){
    string tmp= "\"" + x[i]  + "\"" ;
      tmp = "set label "+ tmp + " at " +  x[i] + "," + y[i] ;
      strcpy(commands[idx++] , tmp.c_str()) ;
  }
  string plname = "points" + num + ".temp" ;
  string end = "plot '" + plname +  "' with linespoints" ;
  strcpy(commands[idx++] , end.c_str()) ;
  
  FILE *temp = fopen(plname.c_str() , "w") ;
  FILE *gnuplot = popen("gnuplot -persistent" , "w") ;

  for(int i = 0 ; i < total_pts ; i++){
    fprintf(temp, "%s %s \n", x[i].c_str() , y[i].c_str());
  }

  for(int i = 0 ; i < idx ; i++){
    fprintf(gnuplot, "%s \n",commands[i]);
  }
  fclose(temp) ;
}
void moveRight(int &head, int start, int cntCylinder, int &cnt, int n, int &totalHeadMv, bool *pres, vector <string> &x, vector<string> &y) {
    for(int i = start; i < cntCylinder && cnt < n; i++) {
        if(pres[i]) {
            pres[i] = false;
            cnt++;
            totalHeadMv += abs(head - i);
            head = i;
            x.push_back(to_string(head));
            y.push_back(to_string(seekRate * totalHeadMv));
        }
    }
}
void moveLeft(int &head, int start, int cntCylinder, int &cnt, int n, int &totalHeadMv, bool *pres, vector <string> &x, vector<string> &y) {
    for (int i = start; i >= 0 && cnt < n; i--) {
        if(pres[i]) {
            pres[i] = false;
            cnt++;
            totalHeadMv += abs(head - i);
            head = i;
            x.push_back(to_string(head));
            y.push_back(to_string(seekRate * totalHeadMv)) ;
        }
    }
}
void SCAN(int head, int *requestQueue, int n, int cntCylinder) {
    vector<string> x, y;
    x.push_back(to_string(head));
    y.push_back("0");
    int totalHeadMv = 0, cnt = 0;
    int cur = 1;
    bool pres[cntCylinder];
    memset(pres, false, sizeof pres);
    for (int i = 0; i < n; i++) {
        pres[requestQueue[i]] = true;
    }
    moveLeft(head, head - 1, cntCylinder, cnt, n, totalHeadMv, pres, x, y);
    if(cnt < n) {
        totalHeadMv += head;
        head = 0;
        moveRight(head, 0, cntCylinder, cnt, n, totalHeadMv, pres, x, y);
    }
    
    printf("Total head movement: %d\n", totalHeadMv);     // print what asked
    printf("Total seek time: %d\n", seekRate * totalHeadMv);
    compare[1].first = seekRate * totalHeadMv;
    PlotGraph(x, y, "SCAN", "1");
}
void CSCAN(int head, int *requestQueue, int n, int cntCylinder) {
    vector<string> x, y;
    x.push_back(to_string(head));
    y.push_back("0");
    int totalHeadMv = 0, cnt = 0;
    int cur = 1;
    bool pres[cntCylinder];
    memset(pres, false, sizeof pres);
    for (int i = 0; i < n; i++) {
        pres[requestQueue[i]] = true;
    }
    moveLeft(head, head - 1, cntCylinder, cnt, n, totalHeadMv, pres, x, y);
    if(cnt < n) {
        totalHeadMv += head;
        totalHeadMv += cntCylinder - 1;
        head = cntCylinder - 1;
        moveLeft(head, head, cntCylinder, cnt, n, totalHeadMv, pres, x, y);
    }
    printf("Total head movement: %d\n", totalHeadMv);     // print what asked
    printf("Total seek time: %d\n", seekRate * totalHeadMv);
    compare[2].first = seekRate * totalHeadMv;
    PlotGraph(x, y, "CSCAN", "2");
}
void SSTF(int head, int *requestQueue, int n, int cntCylinder) {
    vector<string> x, y;
    x.push_back(to_string(head));
    y.push_back("0");
    int totalHeadMv = 0;
    bool pres[n];
    memset(pres, false, sizeof pres);
    for (int i = 0; i < n; i++) {
        pres[i] = true;
    }
    for(int tot = 0; tot < n; tot++) {
        int idx = -1, seekTime = 1000000000; 
        for(int i = 0; i < n; i++) {
            if(pres[i] == true && abs(head - requestQueue[i]) < seekTime) {
                seekTime = abs(head - requestQueue[i]);
                idx = i;
            }
        }
        totalHeadMv += abs(head - requestQueue[idx]);
        head = requestQueue[idx];
        pres[idx] = false;
        x.push_back(to_string(head));
        y.push_back(to_string(seekRate * totalHeadMv)) ;
    }
    printf("Total head movement: %d\n", totalHeadMv);     // print what asked
    printf("Total seek time: %d\n", seekRate * totalHeadMv);
    compare[3].first = seekRate * totalHeadMv;
    PlotGraph(x, y, "SSTF", "3");
}
void FCFS(int head, int *requestQueue, int n, int cntCylinder) {
    vector<string> x, y;
    x.push_back(to_string(head));
    y.push_back("0");
    int totalHeadMv = 0;
    for(int i = 0; i < n; i++) {
        totalHeadMv += abs(head - requestQueue[i]);
        head = requestQueue[i];
        x.push_back(to_string(head));
        y.push_back(to_string(seekRate * totalHeadMv)) ;
    }
    printf("Total head movement: %d\n", totalHeadMv);           // print what asked
    printf("Total seek time: %d\n", seekRate * totalHeadMv);
    compare[0].first = seekRate * totalHeadMv;
    PlotGraph(x, y, "FCFS", "0");
}
int main() {
    int head, queueSize, cntCylinder;         // Take input
    printf("Enter Count of Cylinders:\n");
    scanf("%d", &cntCylinder);
    printf("Enter head position:\n");
    scanf("%d", &head);
    printf("Enter request size:\n");
    scanf("%d", &queueSize);
    int requestQueue[queueSize];
    printf("Enter the %d requests.\n", queueSize);
    for(int i = 0; i < queueSize; i++){
        scanf("%d", &requestQueue[i]);
    }
    printf("\n\nFCFS disk Scheduling Algorithm:\n\n");      // Run fcfs algo
    FCFS(head, requestQueue, queueSize, cntCylinder);
    printf("\n\nSCAN disk Scheduling Algorithm:\n\n");      // Run scan algo
    SCAN(head, requestQueue, queueSize, cntCylinder);
    printf("\n\nCSCAN disk Scheduling Algorithm:\n\n");      // Run csan algo
    CSCAN(head, requestQueue, queueSize, cntCylinder);
    printf("\n\nSSTF disk Scheduling Algorithm:\n\n");      // Run sstf algo
    SSTF(head, requestQueue, queueSize, cntCylinder);
    cout << "\nAlgorithms in sorted order of seek time:\n";
    printf("Rank\t\t\tAlgorithm\t\tSeekTime\n");
    sort(compare, compare + 4, greater<pair<int, string>>());
    for(int i = 0; i < 4; i++) {
        cout << i + 1 << "\t\t\t" << compare[i].second << "\t\t\t" << compare[i].first << endl;
    }
}
