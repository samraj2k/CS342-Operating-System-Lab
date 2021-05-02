#! /bin/bash

#Sameer Raj
#1801CS42
cnt=0
chk=0
#cnt is to store length
#chk is check for end of file flag
if [ $# -ne 2 ]
then
	#Invalud input
	echo "Error: Invalid Input"
	exit
fi
#Now input is correct, loop till the end of file
while read -r line || [ -n "$line" ]; do
  cnt=$((cnt+1))
done < "$1"
if [ $cnt -lt $2 ]
then
	#Delete as per given condition
	rm $1
fi