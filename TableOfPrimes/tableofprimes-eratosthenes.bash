#!/bin/bash

# this script finds all the primes <N.
declare -i N
N=1000

# list of numbers.
declare -a table

# initialise
table[0]=0
table[1]=0
declare -i i
for (( i=2; $i < (N+1); ++i)); do
	table[$i]=1
done;

# sieve
declare -i n
for (( n=1; $n < (N+1)/2; ++n)); do
	if [ ${table[$n]} == 1 ]; then
		for (( i=2; $n*$i <= N; ++i)); do
			table[$n*$i]=0
		done;
	fi
done;

# printout
for (( n=1; $n < N+1; ++n)); do
	if [ ${table[$n]} == 1 ] ; then
		echo -n $n', '
	fi
done;

# clear line
echo ""
