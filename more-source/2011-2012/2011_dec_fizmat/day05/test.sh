#!/bin/bash
for((i=1;i<=10000;i++));do
	python gen.py > in
#	printf "1\n $i $j" > in
	./a.exe < in > out
	./atup.exe < in > ans
	diff out ans || break
	echo done $i
done
