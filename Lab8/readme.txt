Name: Sameer Raj
Roll Number: 1801CS42
Date: 30 March 2021
Assignment 8

---------------------------------------------

1. 
Execution: 
gcc -o 1 1.c -lpthread
./1

Output:
Lock acquired by pthread1
pthread1 is accessing function f()
Lock released by pthread1
pthread2 cannot access function f() lock acquired by pthread1
Lock acquired by pthread2
pthread2 is accessing function f()
Lock released by pthread2

Note:
Above output may vary in different execution since the output depends on order of thread execution.
--------------------------------------------

Execution:
gcc -o 2 2.c -lpthread
./2
Output:
The sum of primes from 1 to 10000 is: 5736396 

Note:
Thread1 calculates the sum of primes of numbers: 1, 5, 9, 13.......9997
Thread2 calculates the sum of primes of numbers: 2, 6, 10, 14.....9998
Thread3 calculates the sum of primes of numbers: 3, 7, 11, 15.....9999
Thread4 calculates the sum of primes of numbers: 4, 8, 12, 16.....10000
Since each thread is also calculating whether that number is prime or not, this is done to maintain load balancing between threads.
---------------------------------------------

3.
Execution:
gcc -o 3 3.c -lpthread
./3
or
./3 x where x is no of times you want to run the code i.e each philosopher will try to eat x times.
Ex: ./3 4

Note: 
------->As per question, allocation and request matrix is printed at each step.
	Deadlock is also checked 
-------> mutex semaphore is used for sync while printing!

Output: (Deadlock is found and prevented) 

Philosopher 0 starts thinking
Philosopher 1 starts thinking
Philosopher 3 starts thinking
Philosopher 4 starts thinking
Philosopher 2 starts thinking
Philosopher 0 waiting for left fork
Philosopher 0 grabs fork 0 (left)
Allocation matrix when philosopher 0 picked left fork: 
1 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 0 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 3 waiting for left fork
Philosopher 3 grabs fork 3 (left)
Allocation matrix when philosopher 3 picked left fork: 
1 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 0 
Request matrix when philosopher 3 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 4 waiting for left fork
Philosopher 4 grabs fork 4 (left)
Allocation matrix when philosopher 4 picked left fork: 
1 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when philosopher 4 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 1 waiting for left fork
Philosopher 1 grabs fork 1 (left)
Allocation matrix when philosopher 1 picked left fork: 
1 0 0 0 0 
0 1 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when philosopher 1 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 2 waiting for left fork
Philosopher 2 grabs fork 2 (left)
Allocation matrix when philosopher 2 picked left fork: 
1 0 0 0 0 
0 1 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when philosopher 2 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Parent detects deadlock, going to initiate recovery
Allocation matrix when deadlock found:
1 0 0 0 0 
0 1 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when deadlock found:
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Parent preempts Philosopher 1
Allocation matrix when after preemting to remove deadlock:
1 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when after preemting to remove deadlock:
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 4 waiting for right fork
Philosopher 1 waiting for right fork
Philosopher 0 waiting for right fork
Philosopher 0 grabs fork 1 (right)
Allocation matrix when philosopher 0 picked right fork: 
1 1 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when philosopher 0 picked right fork: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
1 0 0 0 0 
Philosopher 0 starts eating.
Philosopher 3 waiting for right fork
Philosopher 2 waiting for right fork
Philosopher 0 ends eating and releases forks 0 (left) and 1 (right)
Allocation matrix when philosopher 0 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when philosopher 0 released both forks: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
1 0 0 0 0 
Philosopher 4 grabs fork 0 (right)
Allocation matrix when philosopher 4 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
1 0 0 0 1 
Request matrix when philosopher 4 picked right fork: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
0 0 0 0 0 
Philosopher 4 starts eating.
Philosopher 4 ends eating and releases forks 4 (left) and 0 (right)
Allocation matrix when philosopher 4 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 0 
Request matrix when philosopher 4 released both forks: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
0 0 0 0 0 
Philosopher 3 grabs fork 4 (right)
Allocation matrix when philosopher 3 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 1 
0 0 0 0 0 
Request matrix when philosopher 3 picked right fork: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 3 starts eating.
Philosopher 3 ends eating and releases forks 3 (left) and 4 (right)
Allocation matrix when philosopher 3 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 3 released both forks: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 2 grabs fork 3 (right)
Allocation matrix when philosopher 2 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 1 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 2 picked right fork: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 2 starts eating.
Philosopher 2 ends eating and releases forks 2 (left) and 3 (right)
Allocation matrix when philosopher 2 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 2 released both forks: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 1 grabs fork 2 (right)
Allocation matrix when philosopher 1 picked right fork: 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 1 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 1 waiting for left fork
Philosopher 1 grabs fork 1 (left)
Allocation matrix when philosopher 1 picked left fork: 
0 0 0 0 0 
0 1 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 1 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 1 starts eating.
Philosopher 1 ends eating and releases forks 1 (left) and 2 (right)
Allocation matrix when philosopher 1 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 1 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 


Output: (When deadlock not found)

Philosopher 0 starts thinking
Philosopher 1 starts thinking
Philosopher 4 starts thinking
Philosopher 3 starts thinking
Philosopher 2 starts thinking
Philosopher 1 waiting for left fork
Philosopher 1 grabs fork 1 (left)
Allocation matrix when philosopher 1 picked left fork: 
0 0 0 0 0 
0 1 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 1 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 1 waiting for right fork
Philosopher 1 grabs fork 2 (right)
Allocation matrix when philosopher 1 picked right fork: 
0 0 0 0 0 
0 1 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 1 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 1 starts eating.
Philosopher 1 ends eating and releases forks 1 (left) and 2 (right)
Allocation matrix when philosopher 1 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 1 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 3 waiting for left fork
Philosopher 3 grabs fork 3 (left)
Allocation matrix when philosopher 3 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 0 
Request matrix when philosopher 3 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 2 waiting for left fork
Philosopher 2 grabs fork 2 (left)
Allocation matrix when philosopher 2 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 0 
Request matrix when philosopher 2 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 0 waiting for left fork
Philosopher 0 grabs fork 0 (left)
Allocation matrix when philosopher 0 picked left fork: 
1 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 0 
Request matrix when philosopher 0 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 4 waiting for left fork
Philosopher 4 grabs fork 4 (left)
Allocation matrix when philosopher 4 picked left fork: 
1 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when philosopher 4 picked left fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 2 waiting for right fork
Philosopher 3 waiting for right fork
Philosopher 4 waiting for right fork
Philosopher 0 waiting for right fork
Philosopher 0 grabs fork 1 (right)
Allocation matrix when philosopher 0 picked right fork: 
1 1 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when philosopher 0 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 1 
1 0 0 0 0 
Philosopher 0 starts eating.
Philosopher 0 ends eating and releases forks 0 (left) and 1 (right)
Allocation matrix when philosopher 0 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
Request matrix when philosopher 0 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 1 
1 0 0 0 0 
Philosopher 4 grabs fork 0 (right)
Allocation matrix when philosopher 4 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
1 0 0 0 1 
Request matrix when philosopher 4 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 1 
0 0 0 0 0 
Philosopher 4 starts eating.
Philosopher 4 ends eating and releases forks 4 (left) and 0 (right)
Allocation matrix when philosopher 4 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 0 
Request matrix when philosopher 4 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 1 
0 0 0 0 0 
Philosopher 3 grabs fork 4 (right)
Allocation matrix when philosopher 3 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 1 
0 0 0 0 0 
Request matrix when philosopher 3 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 3 starts eating.
Philosopher 3 ends eating and releases forks 3 (left) and 4 (right)
Allocation matrix when philosopher 3 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 3 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 2 grabs fork 3 (right)
Allocation matrix when philosopher 2 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 1 1 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 2 picked right fork: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Philosopher 2 starts eating.
Philosopher 2 ends eating and releases forks 2 (left) and 3 (right)
Allocation matrix when philosopher 2 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
Request matrix when philosopher 2 released both forks: 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
--------------------------------------------------------------------------------
