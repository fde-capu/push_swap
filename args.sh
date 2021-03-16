#!/bin/bash

numbers=()
n=0
while [ $n -le $(expr $1 - 1) ]
do
	new=$((1 + RANDOM % "$1"));
	check=1;
	for x in $(seq $n)
	do
		if [ "$new" == "${numbers[$(expr $x - 1)]}" ]
		then
			check=0
			break
		fi
	done
	if [ $check -eq 1 ]
	then
		numbers[$n]=$new
		n=$(( $n + 1 ))
	fi
done
echo -n ${numbers[*]}
