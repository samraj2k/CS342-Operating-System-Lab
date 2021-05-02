#!/bin/bash

#Sameer Raj
#1801CS42

#If the input is in invalid format, print error
if [ $# -ne 1 ]; then
	echo "Error: Invalid Input"
	exit
fi
#This function check whether given number if prime or not
function primeCheck() {
	for (( i = 2; i * i <= $1; i++ ))
	do
		if [ $(($1 % i)) == 0 ]
		then
			echo 0
			return
		fi
	done
	echo $1
}
#This function calculates the factorial using recursion
#As stated in the problem
#fact(i) =  i * fact(i - 1)
function fact() {
	if [ $1 -le 1 ]
	then
		echo "$1"
		return
	fi
	echo $(($1 * $(fact $(($1 - 1)))))
}
#This function calculates the number of primes less than given number
#As stated in the problem
function PrimeNoLessThan() {
	if [ $1 -le 1 ]; 
	then
		echo 0
		return
	fi
	if [ $(primeCheck $1) -eq 0 ]
	then
		echo $(PrimeNoLessThan $(($1 - 1)))
	else
		echo $(($(primeCheck $1) + $(PrimeNoLessThan $(($1 - 1)))))
	fi
}
#Print the output of the program
output=$(($(fact $1) * $(PrimeNoLessThan $1)))
echo $output