Name: Sameer Raj
Roll Number: 1801CS42
Date: 15 April 2021
Assignment 12

---------------------------------------------

1. 
Execution: 
g++ -o Q1 Q1.cpp
./Q1

Input/Output:
Enter Count of Cylinders:
200
Enter head position:
100
Enter request size:
5
Enter the 5 requests.
23 89 132 42 187


FCFS disk Scheduling Algorithm:

Total head movement: 421
Total seek time: 2105


SCAN disk Scheduling Algorithm:

Total head movement: 287
Total seek time: 1435


CSCAN disk Scheduling Algorithm:

Total head movement: 366
Total seek time: 1830


SSTF disk Scheduling Algorithm:

Total head movement: 273
Total seek time: 1365

Algorithms in sorted order of seek time:
Rank			Algorithm		SeekTime
1			FCFS			2105
2			CSCAN			1830
3			SCAN			1435
4			SSTF			1365

-------------------------------------------------------------------

2.
Execution: 
g++ -o Q2 Q2.cpp
./Q2

Input/Output:
Enter Count of Cylinders:
200
Enter head position:
100
Enter request size:
8
Enter the 8 requests:
98 183 37 122 14 124 65 57

The disk movement is:
100 -> 122 ->124 ->183 ->98 -> 65 -> 57 -> 37 -> 14

Total head movement: 252
Total seek time: 1260

---------------------------------------------------------------------

