#!/bin/bash

n=0
for i in tests/*; do
	if [ -d $i ]; then
		i=${i#*/}
		pr[$n]=$i
		n=$(( $n + 1 ))
	fi
done

printf "%d\n" $n
for ((i=0; i < $n; i++)); do
	echo ${pr[$i]}
done

m=0
for i in submits/*; do
		i=${i#*/}
		su[$m]=$i
		m=$(( $m + 1 ))
done

printf "%d\n" $m
for ((i=0; i < $m; i++)); do
	echo ${su[$i]}
done

