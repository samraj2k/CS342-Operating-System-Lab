Name: Sameer Raj
Roll Number: 1801CS42
Date: 19 Jan 2021
Assignment 2

---------------------------------------------

1. 
Execution: ./1.sh 5 1 1 1 1 1 1 
Output: 1 is found at the following index: 
1 2 3 4 5

Only 1 input via command line else error

---------------------------------------------

2.
Execution: ./2.sh 6
Output: 7200
Note: Be careful with overflow!

---------------------------------------------

3.
Execution: ./3.sh 7 11 
Output: 
The input -> 7 in binary:
000000000000000000000000000000000000000000000000000000000000111
The input -> 11 in binary:
000000000000000000000000000000000000000000000000000000000001011
The XOR in binary will be:
000000000000000000000000000000000000000000000000000000000001100
The XOR in decimal will be:
12
(Same for C file also)

Execution time compare using time function in linux terminal: 
Execution for sh file: time ./q3.sh 7 11
0m0.010s (real time)

For C file:
Execution for C file: 
gcc 3.c -o 3c
time ./3c 7 11
0m0.001s (real time)

Thus C program takes significantly less time than shell script.
C is nearly 10 times faster.

---------------------------------------------

4.
Execution: ./4.sh "sadjk(A7"
Result: <Valid Password>
Note: Enter the string in " "


--------------------X------------------------
