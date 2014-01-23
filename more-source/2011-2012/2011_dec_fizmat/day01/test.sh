#!/bin/bash
for((i=1;i<=10000000;i++)); do
	python genc.py > in.txt
	cat in.txt | ./c.exe > out.txt
	cat in.txt | python c.py > ans.txt
	diff ans.txt out.txt || break
	echo "$i done"
done
