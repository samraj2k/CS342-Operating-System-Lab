Name: Sameer Raj
Roll Number: 1801CS42
Date: 9 Feb 2021
Assignment 4

---------------------------------------------

1. 
Execution: 
gcc 1.c
./a.out &
(To run external command)
Output:
The PID of parent process is: 47375
The PID of child process is: 47376
Exiting from child process to create zombie process
ps aux | grep 47376
samraj2k   47376  0.0  0.0      0     0 pts/0    Z    21:39   0:00 [a.out] <defunct>
samraj2k   47382  0.0  0.0   9036   660 pts/0    S+   21:39   0:00 grep --color=auto 47376
Sleep over, killing zombie process: 47376

Note: Z infront of process denoted zombie process

---------------------------------------------

2.
Execution:
gcc 2.c
./a.out &
Output:
The PID of parent process is: 51420
The PID of child process is: 51421
pstree -s 51421
systemd───systemd───a.out
[1]+  Done                    ./a.out
The PID of child parent process after making it orphan process is: 1043

Note: The parent of child get killed and thus it is only linked with systemd

Significance of Orphan process:

Orphan process can be usedfor significant purposes. 
A process can be intentionally orphaned to keep it running for exmaple: running in the background or running it for long sessions which don’t need any manual intervention and going to take long time, then we can detach from user session.
The orphans process are running without parent in detached session.
Also in case of crash of parent process, the child process (orphan process) can be helpful in many ways.

---------------------------------------------

3.
Execution:
gcc 3.c
./a.out 11
Output: 
The 11 fibonacci number are:
1 1 2 3 5 8 13 21 34 55 89 
The primes fibonacci are:
The fibonacci number: 2 at position 3 is prime.
The fibonacci number: 3 at position 4 is prime.
The fibonacci number: 5 at position 5 is prime.
The fibonacci number: 13 at position 7 is prime.
The fibonacci number: 89 at position 11 is prime.

Note: Maximum input can be 93 to fit in long long int (64 bit) integer. 

---------------------------------------------
4.
Execution:
gcc 4.c
./a.out file1.txt file3.txt
Output1: 
1st child process: 49741 to copy files.
Parent of 1st child process is -> 49740.

2nd child process: 49743 to display content of file2.
Parent of 2nd child process is -> 49740.

The content of file2 are:
my
name
is
sameer
raj
my
roll
number
is
1801CS42
branch
cse
year
2022
thanks
---------

3rd child process: 49745 to display content sorted of file2 in reverse.
Parent of 3rd child process is -> 49740.
The file2 in desending sorted order is :
year thanks sameer roll raj number name my my is is cse branch 2022 1801CS42 --------- 
XX--------------XX

Output 2:
./a.out file12.txt file3.txt
1st child process: 53446 to copy files.
Parent of 1st child process is -> 53445.

2nd child process: 53447 to display content of file2.
Parent of 2nd child process is -> 53445.

The content of file2 are:
45
3453
34
635423
543
4437634

3rd child process: 53448 to display content sorted of file2 in reverse.
Parent of 3rd child process is -> 53445.
The file2 in desending sorted order is :
4437634 635423 3453 543 45 34 


Note: Works for both strings and integers
If all integers are given sort them as integers else if any line is string then sort them as strings
------------------------------------------------------------------
