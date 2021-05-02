#include<bits/stdc++.h>
using namespace std ;
int seekRate = 5;
void moveRight(int &head, int start, int end, int cntCylinder, int &cnt, int n, int &totalHeadMv, bool *pres) {
    for(int i = start; i <= end && cnt < n; i++) {
        if(pres[i]) {
            pres[i] = false;
            cnt++;
            totalHeadMv += abs(head - i);
            head = i;
            if(cnt < n)
            	printf("%d ->", head);
            else printf("%d\n", head);
        }
    }
}
void moveLeft(int &head, int start, int end, int cntCylinder, int &cnt, int n, int &totalHeadMv, bool *pres) {
    for (int i = start; i >= end && cnt < n; i--) {
        if(pres[i]) {
            pres[i] = false;
            cnt++;
            totalHeadMv += abs(head - i);
            head = i;
            if(cnt < n)
            	printf("%d -> ", head);
            else printf("%d\n", head);
        }
    }
}
void SLOOK(int head, int *requestQueue, int n, int cntCylinder) {
    int totalHeadMv = 0, cnt = 0;
    bool pres[cntCylinder];
    memset(pres, false, sizeof pres);
    for (int i = 0; i < n; i++) {
        pres[requestQueue[i]] = true;
    }
    printf("%d -> ", head);
    int mn = *min_element(requestQueue, requestQueue + n);
    int mx = *max_element(requestQueue, requestQueue + n);
    if(abs(head - mn) <= abs(mx - head)) {
    	moveLeft(head, head - 1, mn, cntCylinder, cnt, n, totalHeadMv, pres);
    	if(cnt < n) {
        	moveRight(head, head, mx, cntCylinder, cnt, n, totalHeadMv, pres);
    	}
    }
    else {
    	moveRight(head, head + 1, mx, cntCylinder, cnt, n, totalHeadMv, pres);
    	if(cnt < n) {
        	moveLeft(head, head, mn, cntCylinder, cnt, n, totalHeadMv, pres);
    	}
    }
    
    
    printf("\nTotal head movement: %d\n", totalHeadMv);     // print what asked
    printf("Total seek time: %d\n", seekRate * totalHeadMv);
}
int main()
{
	int head, queueSize, cntCylinder;         // Take input
    printf("Enter Count of Cylinders:\n");
    scanf("%d", &cntCylinder);
    printf("Enter head position:\n");
    scanf("%d", &head);
    printf("Enter request size:\n");
    scanf("%d", &queueSize);
    int requestQueue[queueSize];
    printf("Enter the %d requests:\n", queueSize);
    for(int i = 0; i < queueSize; i++){
        scanf("%d", &requestQueue[i]);
    }
    printf("\nThe disk movement is:\n");
    SLOOK(head, requestQueue, queueSize, cntCylinder);
	return 0 ;
}