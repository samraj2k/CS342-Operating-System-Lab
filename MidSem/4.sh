#!/bin/bash
# Name: Sameer Raj
# Roll no: 1801CS42
# Ques 4

# Error Handling
# THe command line input format should be correct
if [ $# -ne 2 ];
then
  echo "Error: Use command line input: file (with extension) k, Ex: file.txt 3";
  exit
fi
# Using variables to store original file
# fileName, k
origFile=$0
fileName=$1
k=$2
k2=$((k/2))

# Ques 4a
# In this loop
# We moves through all the files and check for wotks having frequency greater than K in F.txt
for mv in $(<$fileName); do
	#Get frequency
	freq=$(grep -o "\b$mv\b" "$fileName" | wc -l)
	#Check if freq > k
	if [ $freq -gt $k ];
	then
		for i in $(ls);do 
		# If yes, then change that word in other file in directory
			if [ $i != ${origFile:2} ];
			then
			# FIle changed
				sed -i "s/\b$mv\b/MASKED/g" $i
			fi
		done
	fi
	# Loop over
done
# Done
echo "The changes have been made to files in directory to the words whose occurence is F.txt is > K";
# THis array will store our filenames
declare -A array
# Loop
# This works like map and we will later store freq wise
for i in $(ls);do
	# Find frequency of MASKED in every file
	freq=$(grep -o "\bMASKED\b" "$i" | wc -l)
	# If frequency >= k / 2 then add to array: array with freq
	if [ $freq -gt $k2 ];
	then
	# FIle added
		array[$i]="$freq"
	fi
done
# DOne finally
#Ques 4b
echo "The files with MASKED frequency >= K/2 in descending order is"
# Print name of file and frequency of MASKED in sorted fashion. Max k outputs
# This prints the filenames
for i in "${!array[@]}"
do
	if [ $i != ${origFile:2} ];
	# If condiition satisfies
	then
    	echo ${array["$i"]} 'times in' $i
	fi
done |
sort -rn -k1 | head -$k

