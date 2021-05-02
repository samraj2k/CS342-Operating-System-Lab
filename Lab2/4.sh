#! /bin/bash

#Sameer Raj
#1801CS42
#Enter input within " "
if [ $# -ne 1 ]
then
	echo "Error: Invalid Input"
	exit
fi
#Declaring the reuired characters as strings and later checking them
alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
number="1234567890"
symbols="<>(?)/"
input=$1
sz=${#input}
#This functio checks by bruteforce if the above string match or not
function strength() {
	numbernow=$1
	for (( l1 = 0; l1 < $sz; l1++ ))
	do
		for (( l2 = 0; l2 < ${#numbernow}; l2++ ))
		do
			if [ ${input:l1:1} == ${numbernow:l2:1} ]
			then
				echo 1
				return
			fi
		done
	done
	echo 0					
}
#As per ques, if lenth less than 6, invalid password
if [ $sz -le 6 ]
then
	echo "Password is invalid"
	exit
fi
#Otherwise, check by bruteforce all conditions.
if [ $(strength "$alphabet") -eq 1 -a $(strength "$symbols") -eq 1 -a $(strength "$number") -eq 1 ]; then
	echo "<Valid Password>"
else
	echo "<Invalid Password>"
fi



