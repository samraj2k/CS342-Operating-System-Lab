Name: Sameer Raj
Roll Number: 1801CS42
Date: 16 Feb 2021
Assignment 5

---------------------------------------------

1. 
Execution: 
gcc -o 1 1.c -lpthread
./1 <number>
Ex: ./1 22

Output:
I am groot 139978311014208. Created new groot(139978311010048) in iteration 1
Hello from groot 139978311010048 - I was created in iteration 1
I am groot 139978311014208. Created new groot(139978302617344) in iteration 2
Hello from groot 139978302617344 - I was created in iteration 2
I am groot 139978311014208. Created new groot(139978294224640) in iteration 3
Hello from groot 139978294224640 - I was created in iteration 3
I am groot 139978311014208. Created new groot(139978285831936) in iteration 4
Hello from groot 139978285831936 - I was created in iteration 4
I am groot 139978311014208. Created new groot(139978277439232) in iteration 5
Hello from groot 139978277439232 - I was created in iteration 5
I am groot 139978311014208. Created new groot(139978269046528) in iteration 6
I am groot 139978311014208. Created new groot(139978260653824) in iteration 7
Hello from groot 139978260653824 - I was created in iteration 7
Hello from groot 139978269046528 - I was created in iteration 6
I am groot 139978311014208. Created new groot(139978252261120) in iteration 8
Hello from groot 139978252261120 - I was created in iteration 8
I am groot 139978311014208. Created new groot(139978243868416) in iteration 9
Hello from groot 139978243868416 - I was created in iteration 9
I am groot 139978311014208. Created new groot(139978235475712) in iteration 10
Hello from groot 139978235475712 - I was created in iteration 10
I am groot 139978311014208. Created new groot(139978227083008) in iteration 11
I am groot 139978311014208. Created new groot(139978218690304) in iteration 12
Hello from groot 139978227083008 - I was created in iteration 11
Hello from groot 139978218690304 - I was created in iteration 12

---------------------------------------------

2.
Execution:
gcc -o 2 2.c -lpthread
./2
Output:
Iteration: 1 In thread: 140628042131200 the global varibale is: 1, and static variable is: 1.
Iteration: 4 In thread: 140628016953088 the global varibale is: 4, and static variable is: 4.
Iteration: 2 In thread: 140628033738496 the global varibale is: 2, and static variable is: 2.
Iteration: 3 In thread: 140628025345792 the global varibale is: 3, and static variable is: 3.
Iteration: 5 In thread: 140628008560384 the global varibale is: 5, and static variable is: 5.
Iteration: 6 In thread: 140628000167680 the global varibale is: 6, and static variable is: 6.
Iteration: 7 In thread: 140627991774976 the global varibale is: 7, and static variable is: 7.
Iteration: 8 In thread: 140627983382272 the global varibale is: 8, and static variable is: 8.
Iteration: 9 In thread: 140627899578112 the global varibale is: 9, and static variable is: 9.
Iteration: 10 In thread: 140627891185408 the global varibale is: 10, and static variable is: 10.
The final value of static variable is: 10 and global variable is: 10.

Note: Sometimes the output is not 10, because increment is not atomic operation.

---------------------------------------------

3.
Execution:
gcc -o 3 3.c -lpthread
./3
Output: 
Computation underprocess. Please wait...
The cube root of 0 is: 0.000000
The cube root of 1 is: 1.000000
The cube root of 2 is: 1.259921
The cube root of 3 is: 1.442249
The cube root of 4 is: 1.587401
The cube root of 5 is: 1.709976
The cube root of 6 is: 1.817120
The cube root of 7 is: 1.912931
The cube root of 8 is: 2.000000
The cube root of 9 is: 2.080083
The cube root of 10 is: 2.154434
The cube root of 11 is: 2.223980
The cube root of 12 is: 2.289428
The cube root of 13 is: 2.351334
The cube root of 14 is: 2.410142
The cube root of 15 is: 2.466212
The cube root of 16 is: 2.519842
The cube root of 17 is: 2.571281
The cube root of 18 is: 2.620741
The cube root of 19 is: 2.668402
The cube root of 20 is: 2.714418
The cube root of 21 is: 2.758924
The cube root of 22 is: 2.802039
The cube root of 23 is: 2.843867
The cube root of 24 is: 2.884499
The cube root of 25 is: 2.924017
The cube root of 26 is: 2.962496
The cube root of 27 is: 3.000000
The cube root of 28 is: 3.036588
.... and so on

Note: Binary search is used to find cube root (for better precision).
------------------------------------------------------------------
