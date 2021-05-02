#include<iostream>
#include<queue>
#include<algorithm>    
//#define int long long int  
using namespace std;

struct jobDetails {  
    /*
    struct for storing the job details as given in the input
    Stores jobId --> String
    Arrival time of that job
    Execution type
    All are input values
    */   
    char jobId[16];
    int arrivalTime;
    int executionTime;
};
bool custom(jobDetails &a , jobDetails &b){
    /*
    Function to sort the joDetails input array based on arrival time.
    */  
    int ok = 1;
    ok &= (a.arrivalTime < b.arrivalTime) ;
    return ok;
}
struct schedulingInfo {
    /*
    This struct stores details of scheduling info
    Start time
    End time
    And status
    As asked in output
    */
    int startTime;
    int endTime;
    char status;
};
struct processorQueue {
    /*
    This struct stores info of the job that is currenty executing in the processor
    Index is index of process
    ExecLeft is execution time left for that job to complete
    timeExecuted is time for which it is executed by that processor
    */
    int index;
    int execLeft;
    int timeExecuted;
};
void printTable(int n, schedulingInfo table[], jobDetails data[], int timeInstant) {
    cout << "Details of job scheduled at time instant: " << timeInstant << endl;
    /*
    This function prints the table at the given time
    As asked in the output
    Only prints for the jobs which have arrival time less than the asked time
    */
    printf("job_id\tarrival_time\tExecution time\tstart_time\tend_time\tcurrent_status\n");
    for(int i = 0; i < n and data[i].arrivalTime <= timeInstant; i++) {
        /*
        Print in table form
        */
        printf("%s\t%d\t\t%d\t\t", data[i].jobId, data[i].arrivalTime, data[i].executionTime);
        if(table[i].startTime != -1)
            printf("%d", table[i].startTime);
        printf("\t\t");
        if(table[i].endTime != -1)
            printf("%d", table[i].endTime);
        printf("\t\t");
        printf("%c\n", table[i].status);
    }
}
void pushQueue(int &pBusy, queue<int> &q, schedulingInfo table[], jobDetails data[], processorQueue &p, int &time, int &done, int d, int n) {
    /*
    This function finds the job for processor if any of processor is not busy.
    If busy do nothing 
    */
    if(done >= n)
        return;
    if(!pBusy && !q.empty()) {
        /*
        Job is chosen and given to processor
        */
        int cur = q.front();
        q.pop();
        /*
        Dont change start time is job is nnot new and executed some time
        */
        if(table[cur].startTime == -1)
            table[cur].startTime = time;
        p.index = cur;
        p.execLeft = data[cur].executionTime;
        p.timeExecuted = 0;
        pBusy = 1;
        /*
        Marked in executed phase
        */
        table[cur].status = 'E';
    }
}
void doWork(int &pBusy, queue<int> &q, schedulingInfo table[], jobDetails data[], processorQueue &p, int &time, int &done, int d, int n) {
    /*
    This function executes the job by processor.
    */
    if(done >= n)
        return;
    if(pBusy) {
        /*
            Decrease execution time by 1
            And increase processor execution time by 1
        */
        p.timeExecuted++;
        p.execLeft--;
        if(p.execLeft == 0) {
            /*
            The job finishes its execution and thus it is marked completed
            */
            table[p.index].status = 'C';
            table[p.index].endTime = time;
            pBusy = 0;
            done++;
        }
        else if(p.timeExecuted == d) {
            /*
            Time sliced finished, the job is marked waiting, pushed into queue
            */
            table[p.index].status = 'W';
            q.push(p.index);
            data[p.index].executionTime = p.execLeft;
            pBusy = 0;
        }
    }
}
void process(int n, jobDetails data[], int d1, int d2, int timeInstant, jobDetails orig[]) {
    /*
    This main function simulates the job scheduling.
    As soon as the process arrives, it is pushed in the main queue
    And calls print function if time matches
    */
    int p1Busy = 0, p2Busy = 0, done = 0, time = -1;
    processorQueue p1, p2;
    schedulingInfo table[n];
    /*
        Initliaize
    */
    for(int i = 0; i < n; i++) {
        table[i].startTime = table[i].endTime = -1;
        table[i].status = 'W';
    }
    int taken[n] = {0};
    queue<int> q;
    while(done < n) {
    /*
    In this while loop, processors are given jobs by calling pushQueue function
    ANd executed by calling doWork() function
    */
        pushQueue(p1Busy, q, table, data, p1, time, done, d1, n); // processor1
        pushQueue(p2Busy, q, table, data, p2, time, done, d2, n); // processor2
        /*
        Print as asked if time matches by calling printTable()
        */
        if(timeInstant == time)
            printTable(n, table, orig, timeInstant);
        time++;
        for(int i = 0; i < n; i++) {
            if(data[i].arrivalTime <= time && taken[i] == 0) {
                q.push(i);
                taken[i] = 1;
            }  
        }
        /*
        Do work at time t 
        */
        doWork(p1Busy, q, table, data, p1, time, done, d1, n);   //processor 1
        doWork(p2Busy, q, table, data, p2, time, done, d2, n); // processor 2
    }
    if(timeInstant >= time) {
        /*
            If whole job completed then print table
        */
        printTable(n, table, orig, timeInstant);
    }
}
int32_t main() {  
    /*
    main() takes input and skips input is time <= 0 
    */  
    int d1, d2, n;
    cin >> d1 >> d2 >> n;
    jobDetails data[n], temp[n];
    for(int i = 0; i < n; i++) {
        cin >> data[i].jobId >> data[i].arrivalTime >> data[i].executionTime;
        if(data[i].arrivalTime < 0 || data[i].executionTime <= 0) {
            cout << "Invalid Input, arrival time cannot be < 0 and execution time cannot be <= 0\n";
            cout << "Skipping this input\n";
            n--;
            i--;
        }
        temp[i] = data[i];
    }
    /*
    Sort the data 
    */
    sort(data, data + n, custom);
    sort(temp, temp + n, custom);
    int timeInstant;
    cin >> timeInstant;
    /*
    Call the function to simulate 
    */
    process(n, temp, d1, d2, timeInstant, data);
}