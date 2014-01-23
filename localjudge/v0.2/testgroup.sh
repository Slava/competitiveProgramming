#!/bin/bash

work="."

if [ -e report.txt ]; then
	rm report.txt
fi
for prob in tests/*; do
	if [ -d "$prob" ]; then
		prob=${prob#*/}
		echo -n "$prob "
	else continue
	fi
done;
printf "\n"

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
		if [ -e "$work/$prob.cpp" ]; then
			rm "$work/$prob.cpp"
		elif [ -e "$work/$prob.pas" ]; then
			rm "$work/$prob.pas"
		fi
		if [ -e "submits/$name/$prob.cpp" ]; then
			cp "submits/$name/$prob.cpp" $work/
		elif [ -e "submits/$name/$prob.pas" ]; then
			cp "submits/$name/$prob.pas" $work/
		fi
		cp tests/$prob/check $work/
		#cp ./test.sh $work/
		if [ -e "tests/$prob/options.txt" ]; then
			cp "tests/$prob/options.txt" $work/options.txt
		else 
			cp defaultoptions.txt options.txt
		fi
		$work/test.sh "$prob" "tests/$prob/" "$name" 2>> report.txt < options.txt
		if [ -e $work/$prob.cpp ]; then
			rm $work/$prob.cpp
		elif [ -e $work/$prob.pas ]; then
			rm $work/$prob.pas
		fi
		if [ -e $work/check ]; then
			rm $work/check
		fi
		if [ -e $work/a ]; then
			rm $work/a
		fi
		if [ -e $work/$prob.in ]; then
			rm $work/$prob.in
		fi
		if [ -e $work/$prob.out ]; then
			rm $work/$prob.out
		fi
		if [ -e $work/ans ]; then
			rm $work/ans
		fi
	done
	echo ""
done

