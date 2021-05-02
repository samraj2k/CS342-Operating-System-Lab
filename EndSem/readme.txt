Name: Sameer Raj
Roll Number: 1801CS42
Date: 20 April 2021
EndSem Assignment

---------------------------------------------
Update all directly using makefile
1. 
PART I
Execution: 
gcc -o 1_1 1_1.c
./1_1

Input/Output:
Enter the values of c and r:
3 7
Maximum number of processes to ensure deadlock free operation is:
3

PART II
gcc -o 1_2 1_2.c
./1_2

Input/Output:
Enter n -> No of processes:
10
Enter the number of copies for each process:
5 3 6 3 5 1 6 4 7 3
Maximum resources r such that deadlock free operation is not guaranteed is:
33
Minimum resources r such that deadlock free operation is guaranteed is:
34

---------------------------------------------

2.
My Algorithm

This algorithm removes the pages which has maxFrequency / maxTimeStayedInQueue (Divide operation)
If that page is called say x times, and it has stayed in queue foy y secons, then the page with minimum x / y
is removed.
This is a direct enhancement of LFU algorithm, but accounts for both the cases
a) Either it is being least frequently used
b) Though it is used few times, but has stayed for longer in the memory, and thus given "enough" changes but wasting a page
With this, we can account for both the characterstics, onstead of relying on only 1.
This is a better algorithm, but unfortunately takes more time to implement, and also complex to implement on low level.
But give more meaningful result then LFU, and takes accounts for two criteria: Frequency till now and Time stayed in queue (Ratio is taken)

Execution:
g++ -o 2 2.cpp
./2

Input:
1
4 18
1 3 2 3 1 3 4 1 3 1 2 1 5 3 1 2 3 4

Output:
Page Faults:
My Algorithm		6 
FCFS Algorithm		7 
LIFO Algorithm		6 
LRU Algorithm		6 

Algorithm		Time Taken(ms)
My Algorithm		128
FCFS Algorithm		42
LIFO Algorithm		29
LRU Algorithm		51

---------------------------------------------

3.
Note: Inout format as per question
Don't enter ID with spaces, otherwise we cant decide if it is part of ID or time
Don't put unfinished input
Inout format:
d1 d2
N
Next lines lines: ID arrivaltime executiontime
TimeInstant
Compilation/Execution:
g++ -o 3 3.cpp
./3

Input:
5
10
7
A 0 18
B 0 12
C 0 7
D 0 11
E 0 28
F 7 18
G 16 12
53

Output: 
Details of job scheduled at time instant: 53
job_id	arrival_time	Execution time	start_time	end_time	current_status
A	0		18		0		43		C
B	0		12		0		24		C
C	0		7		5		22		C
D	0		11		10		30		C
E	0		28		10				E
F	7		18		20		51		C
G	16		12		25		52		C


------------------------------------------------------------------
4.
Execution:
gcc -o 4 4.c
./4

Input/Output:
Enter count of Cylinders:
200
Enter head position:
98
Enter request size:
8
Enter the 8 requests:
98 183 37 122 14 124 65 67

The head movement is:
98 -> 67 -> 65 -> 37 -> 14 -> 122 -> 124 -> 183
Total disk head movement: 253
Total seek time: 1265

------------------------------------------------------------------
