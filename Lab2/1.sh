#!/bin/bash

# Sameer Raj
# 1801CS42

#Case 1: sz of less than 3: Invalid input
if [ $# -lt 3 ]; 		
then
	echo "Invalid Input"
	exit
fi
#Case 2: The arguments not properly given in input
if [ $1 -ne $(($# - 2)) ]; 
then
	echo "Invalid Input"
	exit
fi
#Declare array and some variables to use
sz=0
last=${*: -1:1}
declare -a arr
idx=0
#This is the main loop which iterates in array
#If any element is found
#The index (1 based) is stored in arr array and size increment by 1
#mv is loop variable
for mv in "$@"; 
do
	((idx++))
	#Index increases for loop
	if [ $idx == 1 -o $idx == $# ]
	then
		continue
	fi
	if [ $idx == $# ] 
	then
		continue
	fi
	#This is case when element is found
	if [ $mv == $last ]
	then
		arr[sz]=$(($idx - 1))
		((sz++))
	fi
done
#Printing part
#Prints the size and the index where the element is found
if [ $sz == 0 ] 
then
	echo "Error: $last not found in the array"
else
	echo "$last is found at the following index: "
	echo "${arr[*]}"
fi