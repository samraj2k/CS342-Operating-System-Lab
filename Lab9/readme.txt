Name: Sameer Raj
Roll Number: 1801CS42
Date: 3 April 2021
Assignment 9

---------------------------------------------

1. 
Execution: 
gcc -o 1 1.c
./1

Output:
SIMULATION OF DEADLOCK PREVENTION
Enter number of processes, resources
3 2
Enter allocation matrix
2 4 5
3 4 5
Enter max matrix
4 3 4
5 6 1
Enter available matrix: 2 2


Failing :Mutual exclusion
By allocating required resources to process 0 dead lock is prevented 
lack of preemption
dead lock is prevented by allocating needed resources
failing:Hold and Wait condition



Note:
m * n is input style as per question
--------------------------------------------

Execution:
gcc -o 2 2.c
./2

Output:
Enter the no of process: 4
Enter the no of resources: 5
Total Amount of the Resource R1: 2
Total Amount of the Resource R2: 1 
Total Amount of the Resource R3: 1
Total Amount of the Resource R4: 2
Total Amount of the Resource R5: 1

Enter the request matrix:
0 1 0 0 1
0 0 1 0 1
0 0 0 0 1
1 0 1 0 1

Enter the allocation matrix:
1 0 1 1 0
1 1 0 0 0 
0 0 0 1 0
0 0 0 0 0

Deadlock detected


Note: If input is wrong, the answer will be deadlock detected, please enter correct input
---------------------------------------------

3.
Execution:
gcc -o 3 3.c
./3

Output:
Enter the no of process: 5
Enter the no of resources: 3
Total Amount of the Resource R1: 3
Total Amount of the Resource R2: 3
Total Amount of the Resource R3: 2

Enter the Max matrix:
P0 7 5 3
P1 3 2 2
P2 9 0 2
P3 2 2 2
P4 4 3 3

Enter the allocation matrix:
P0 0 1 0
P1 2 0 0
P2 3 0 2
P3 2 1 1
P4 0 0 2

Safe sequence 1: P1 -> P3 -> P0 -> P2 -> P4
Safe sequence 2: P1 -> P3 -> P0 -> P4 -> P2
Safe sequence 3: P1 -> P3 -> P2 -> P0 -> P4
Safe sequence 4: P1 -> P3 -> P2 -> P4 -> P0
Safe sequence 5: P1 -> P3 -> P4 -> P0 -> P2
Safe sequence 6: P1 -> P3 -> P4 -> P2 -> P0
Safe sequence 7: P1 -> P4 -> P3 -> P0 -> P2
Safe sequence 8: P1 -> P4 -> P3 -> P2 -> P0
Safe sequence 9: P3 -> P1 -> P0 -> P2 -> P4
Safe sequence 10: P3 -> P1 -> P0 -> P4 -> P2
Safe sequence 11: P3 -> P1 -> P2 -> P0 -> P4
Safe sequence 12: P3 -> P1 -> P2 -> P4 -> P0
Safe sequence 13: P3 -> P1 -> P4 -> P0 -> P2
Safe sequence 14: P3 -> P1 -> P4 -> P2 -> P0
Safe sequence 15: P3 -> P4 -> P1 -> P0 -> P2
Safe sequence 16: P3 -> P4 -> P1 -> P2 -> P0


--------------------------------------------------------------------------------
