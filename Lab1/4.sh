#! /bin/bash

#Sameer Raj
#1801CS42
if [ $# -ne 3 ]
then
	#Invalid input
	echo "Error: Invalid Input"
	exit
fi
ipath=$1
cd $ipath
#The path of directory
ptrn=$2
#The giveb patrn
final=$3
#The final name to be given
itr=1
#Now looping in direcotry
for file in *
	do
		filename=$file
		ex="${file##*.}"
		p=${#ptrn}
		file="${file%.*}"
		#Here selecting the first file wil be matched with others
		f=${#file}
		sz=$(( f-p+1 ))
	#Checking using two nesed loop
	for(( i=0; i<sz; i++ ))
		do
			if [[ ${file:i:1} == ${ptrn:0:1} ]]
			then
				#Check for pattern now
				chk=0
				k=0
				lin=$((i + p))
				for(( j=$i; j<lin; j++ ))
				do
					#This loop check for each substring
					if [[ ${file:j:1} != ${ptrn:k:1} ]]
					then 
						chk=1
						break 
					fi
					k=$((k + 1))
				done
				#Loop end
				if [ $chk -eq 0 ]
				then 
					give="${final}_${itr}"."${ex}"
					mv "$filename" "$give"
					itr=$((itr + 1))
				fi
			fi
		done
	done