#!/bin/bash

if [ -e report.txt ]; then
	rm report.txt
fi
for name in submits/*; do
	if [ -d "$name" ]; then
		name=${name#*/}
		printf "%s\t\t" "$name"
	else continue
	fi
	for prob in tests/*; do
		if [ -d "$prob" ]; then
			prob=${prob#*/}
#			echo -n "$prob "
		else continue
		fi
		if [ -e "$prob.cpp" ]; then
			rm "$prob.cpp"
		elif [ -e "$prob.pas" ]; then
			rm "tests/$prob/$prob.pas"
		fi
		if [ -e "submits/$name/$prob.cpp" ]; then
			cp "submits/$name/$prob.cpp" ./
		elif [ -e submits/$name/$prob.pas ]; then
			cp submits/$name/$prob.pas ./
		fi
		cp tests/$prob/check ./
		./test.sh $prob tests/$prob/ "$name" 2>> report.txt
		if [ -e $prob.cpp ]; then
			rm $prob.cpp
		elif [ -e $prob.pas ]; then
			rm tests/$prob/$prob.pas
		fi
		if [ -e check ]; then
			rm check
		fi
		if [ -e a ]; then
			rm a
		fi
		if [ -e $prob.in ]; then
			rm $prob.in
		fi
		if [ -e $prob.out ]; then
			rm $prob.out
		fi
		if [ -e ans ]; then
			rm ans
		fi
	done
	echo ""
done

