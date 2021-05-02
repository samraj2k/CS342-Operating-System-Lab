Name: Sameer Raj
Roll Number: 1801CS42
Date: 17 March 2021
Mid Sem Assignment

---------------------------------------------

1. 
Execution: 
gcc -o 1 1.c
./1 &
& to input command in between
Output: (This is for checking zombie process)

The parent process is: 81739.
The child process (zombie) is: 81740 and parent is: 81739. The parent is sleeping so this process becomes zombie after exit.
ps aux | grep 81740
samraj2k   81740  0.0  0.0      0     0 pts/1    Z    03:49   0:00 [a.out] <defunct>   ---------> Z is zombie process
samraj2k   81750  0.0  0.0   9044   728 pts/1    R+   03:49   0:00 grep --color=auto 81740
Parent sleep finised.
The child process (orphan) is: 81756 with Parent PID: 81739.
The parent process is: 81739 (ending)....
Sleep over for child PID: 81756, now the Parent ID is: 998


For checking Orphan process, we print tree
Execute: ./1 &
Output:
 The parent process is: 82049.
The child process (zombie) is: 82050 and parent is: 82049. The parent is sleeping so this process becomes zombie after exit.
Parent sleep finised.
The child process (orphan) is: 82064 with Parent PID: 82049.
The parent process is: 82049 (ending)....
pstree -s 82064
systemd───systemd───a.out
[1]+  Done                    ./a.out
Sleep over for child PID: 82064, now the Parent ID is: 998

Note: Wait for some time after shellusername shows since main has terminated the orphan process will continue printing output
---------------------------------------------

2a.
Execution:
gcc -o 2a 2a.c
./2a 15
Output:
1st child to compute sum of negative numbers, PID: 76786, Parent PID: 76785
2nd child to compute sum of positive prime numbers, PID: 76787, Parent PID: 76785
3rd child to compute sum of positive non-prime numbers, PID: 76788, Parent PID: 76785
Parent to compute and print total sum of n terms of series, PID: 76785
The sum of n terms of series is:
0.725372

---------------------------------------------

2b.
Execution:
gcc -o 2b 2b.c -lpthread
./2b
Output: 
Enter order n x m of the input matrix.
2 3
Enter matrix A:
1 2 3 
1 3 5
Enter matrix B:
2 4 6
3 5 7
Enter matrix C:
2 56 78
2 6 3
Thread ID: 139849343137536 to check commutativity.
Commutative
Thread ID: 139849343137536 to check assosiativity.
Assosiative
Thread ID: 139849343137536 to check and print additive identity.
The additive identity is:
0 0 0 
0 0 0 
Thread ID: 139849343137536 to check and print additive inverse.
The additive inverse is:
-1 -2 -3 
-1 -3 -5 

Note: pthread_join() has been used evertime after thread creation so output remian correct.
------------------------------------------------------------------

3.
Execution:
g++ -o 3 3.cpp
./3
Input:
10
0 3 8
1 1 1
2 2 3
3 3 2
4 4 6
12 9 2
12 6 88
10 99 99
7 6 6
12 8 8

Output: 
Wait Time:
147.90
Turnaround Time:
170.20
The completion order of processes is:
P8 P6 P10 P9 P7 P5 P1 P4 P3 P2 


------------------------------------------------------------------
4.
Execution:
./4.sh a.txt 4
Here a.txt is file
3 is K
Output:
The changes have been made to files in directory to the words whose occurence is F.txt is > K
The files with MASKED frequency >= K/2 in descending order is
12 times in b.txt
7 times in 4.sh
5 times in a.txt
2 times in ne.txt

Note: Original file will change too, be careful!
Little change is made in resubmission
------------------------------------------------------------------
