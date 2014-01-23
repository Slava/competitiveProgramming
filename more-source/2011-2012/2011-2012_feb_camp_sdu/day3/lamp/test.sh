#!/bin/bash
for ((i=0; i < 10000; i++)); do
	./gen.exe $RANDOM > in
	./a.exe < in > out
	./b.exe < in > ans
	diff out ans || break
	echo test $i
	cat ans
done
