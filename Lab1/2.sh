#!/bin/bash

#Sameer Raj
#1801CS42
i=$1
#Storing the first argument if present
if [ $# -ne 2 ]
	#Invalid input
	then echo "Error: Provide valid arguments."
elif [ $1 -gt $2 ]
	#Invalid input
	then echo "Error: Provide valid input."
else 
	#Use while loop to print the numbers in betweeb
	while [ $i -lt $2 ]
		do 
			echo -n "$i "
			i=$(( i+1 ))
	done
	echo $2
fi
