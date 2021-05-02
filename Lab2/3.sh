#! /bin/bash

#Sameer Raj
#1801CS42
if [ $# -ne 2 ]
then
	echo "Error: Invalid Input"
	exit
fi
#This function, as stated in the problem convert the number in binary form
#63 is taken due to 64 bit integer support in Linux 64-bit
function binaryForm() {
	ans=""
	bit1=$1
	#Concatenate the bit1s in ans string
	for (( i = 0; i < 63; i++ ))
	do
		ans=$((bit1 % 2))$ans
		bit1=$((bit1 / 2))
	done
	echo $ans
}
#This function convert the number in decimal form
function decForm() {
	res=0
	bit2=$1
	for (( i = 0; i < 63; i++ ))
	do
		curBit=${bit2:i:1}
		res=$((res * 2+curBit))
	done
	echo $res
}
#This function, as stated in the problem finds the XOR of two numbers in binary
function XOROut() {
	local bit1=$1
	local bit2=$2
	for (( i = 0; i < 63; i++ )); 
	do
		if [ ${bit1:i:1} != ${bit2:i:1} ]; 
		then
			res="${res}1"
		else 
			res="${res}0"
		fi
	done
	echo $res
}
#Firstly, we convert both the number in binary form
form1=$(binaryForm $1)
echo "The input -> $1 in binary:"
echo $form1
form2=$(binaryForm $2)
echo "The input -> $2 in binary:"
echo $form2
#After this, we tae XOR
n1=$(XOROut $form1 $form2)
echo "The XOR in binary will be:"
echo $n1
n2=$(decForm $n1)
echo "The XOR in decimal will be:"
echo $n2

