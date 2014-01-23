#!/bin/bash
for((i=1;i<=2222;i++));do
	python genb.py | ./convex.exe > in
	./b.exe <in >out
	./btup.exe < in > ans
	diff ans out || break
done
