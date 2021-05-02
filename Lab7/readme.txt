Name: Sameer Raj
Roll Number: 1801CS42
Date: 24 March 2021
Assignment 7

// Compile in C++11 and above
---------------------------------------------


1. 
Execution: 
g++ -o 1 1.cpp

Input Format: 
N (no of processes) tq (Time quantum)
Next n lines for each process -> arrival_time burst_time

Input:
8 3
12 41
15 31
15 23
16 3
20 2389
25 93
27 32
1000 31
Output:
Avg_WT = 130.12 Avg_TAT = 460.50
P4 P3 P2 P7 P1 P6 P8 P5 

--------------------------------------------

Execution:
g++ -o 2 2.cpp
./2

Input Format: 
N (no of processes)
Next n lines for each process -> arrival_time burst_time priority(lower is higher priority)

Input:
8
12 41 7
15 31 1
15 23 31
16 3 13
20 2389 0
25 93 11
27 32 34
1000 31 41
Output:
Avg_WT = 1775.12 Avg_TAT = 2105.50
P1 P5 P2 P6 P4 P3 P7 P8 

---------------------------------------------

3.
Execution:
g++ -o 3 3.cpp
./3

Input Format: 
N (no of processes) Q(No of queues, >= 1, and <= 2)
Next n lines for each process -> arrival_time burst_time queue_number

Input:
8 2
12 41 2
15 31 1
15 23 2
16 3 1
20 2389 1
25 93 1
27 32 2
1000 31 1

Output: 
Avg_WT = 1017.38 Avg_TAT = 1347.75
P4 P2 P6 P8 P5 P3 P7 P1 
 
Note: In input Q should be either 1 or 2
And for each process queue value should be >=1 and <= Q
For Q1 time quantam is 4 as given in question, and time quantum is 3 for queue 2. 

------------------------------------------------------------------
