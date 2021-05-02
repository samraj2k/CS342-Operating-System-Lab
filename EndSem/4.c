#include <stdio.h>
#include <stdlib.h>
int seekRate = 5;
int n, cnt = 0;
/*
User defined functions
*/
int max(int a, int b) {
    if(a >= b)
        return a;
    return b;
}
int min(int a, int b) {
    if(a <= b)
        return a;
    return b;
}
int abs(int x) {
    if(x < 0)
        return -x;
    return x;
}
void leftProceed(int *head, int start, int end, int cntCylinder, int *totalHeadMv, int *pres) {
    /*
    This function moves the head to left
    */
    if(cnt >= n)
        return;
    int i = start;
    for (i = start; i >= end && cnt < n; i--) {
        if(pres[i]) {
            pres[i] = 0;
            cnt = cnt + 1;
            int curMov = abs(*head - i);
            *head = i;
            *totalHeadMv += curMov;
            printf("%d", *head);
            if(cnt < n) printf(" -> ");
        }
    }
}
void rightProceed(int *head, int start, int end, int cntCylinder, int *totalHeadMv, int *pres) {
    /*
    This function moves the head to right
    */
    if(cnt >= n)
        return;
    int i = start;
    for(i = start; i <= end && cnt < n; i++) {
        if(pres[i]) {
            pres[i] = 0;
            cnt = cnt + 1;
            int curMov = abs(*head - i);
            *head = i;
            *totalHeadMv += curMov;
            printf("%d", *head);
            if(cnt < n) printf(" -> ");
        }
    }
}
int SLOOK(int head, int *requestQueue, int cntCylinder) {
    /*
    This function is main function for implementing SLOOK
    */
    int totalHeadMv = 0;
    int i = 0;
    int pres[cntCylinder];
    for (i = 0; i < cntCylinder; i++)
        pres[i] = 0;
    for (i = 0; i < n; i++) {
        pres[requestQueue[i]] = 1;
    }
    int mn = cntCylinder + 10;
    int mx = -1;
    for (i = 0; i < n; i++) {
        mn = min(mn, requestQueue[i]);
        mx = max(mx, requestQueue[i]);
    }
    /*
    Check where to move by checking min and max value
    And proceed accordingly
    */
    if(abs(head - mn) <= abs(mx - head)) {
    	leftProceed(&head, head, mn, cntCylinder, &totalHeadMv, pres);
    	rightProceed(&head, head + 1, mx, cntCylinder, &totalHeadMv, pres);
    }
    else {
    	rightProceed(&head, head + 1, mx, cntCylinder, &totalHeadMv, pres);
    	leftProceed(&head, head, mn, cntCylinder, &totalHeadMv, pres);
    }
    return totalHeadMv;
    
}
int main()
{
    /*
    Take input
    */
	int head, cntCylinder;         // Take input
    int i;
    printf("Enter count of Cylinders:\n");
    scanf("%d", &cntCylinder);
    printf("Enter head position:\n");
    scanf("%d", &head);
    printf("Enter request size:\n");
    scanf("%d", &n);
    int requestQueue[n];
    printf("Enter the %d requests:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &requestQueue[i]);
    }
    printf("\nThe head movement is:\n");
    int totalHeadMv = SLOOK(head, requestQueue, cntCylinder);
    printf("\nTotal disk head movement: %d\n", totalHeadMv);     // print what asked
    printf("Total seek time: %d\n", seekRate * totalHeadMv);
	return 0 ;
}