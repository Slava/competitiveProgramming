#!/bin/bash
for((i=1;i<1000;i++)); do
	python gena.py > sum.in
	time ./a.exe
	python atup.py < sum.in > ans
	diff sum.out ans || break
	echo $i passed
done
