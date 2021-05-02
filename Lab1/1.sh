#!/bin/bash

#Sameer Raj
#1801CS42
str=$1
revstr=""
#declare variables for storing string and reverse string
len=${#str}
#finding lenth of string
if [ $# -ne 1 ]
then 
    echo "Error: Invalid Input"
    #This is case when input is not given correctly
elif [[ ${str:0:1} == "-" ]]
	then
		#If number is negative, then retain minus sign
	   	for((i=$len-1;i>0;i--))
	   	do
	     	revstr=$revstr${str:i:1}
	    done
	    #Print
	    revstr="-"$revstr
	    echo $revstr
else 
    for((i=$len-1;i>=0;i--))
    do
      revstr=$revstr${str:i:1}
    done
    #Print
    echo $revstr
fi