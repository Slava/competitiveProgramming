#!/bin/bash

#test problem $1

work="."

read tl ml std
ml=$(( ml * 1024 ))
printf "tl = $tl seconds\nml = $ml Mb\nuse stdin/stdout = $std\n\n" >&2


if (( ! (($#)) )); then
	echo "no args" >&2
	exit 1
fi
echo "" >&2
echo "testing "$3" problem "$1" : " >&2
if [ -e $work/a ]; then 
	rm $work/a 
fi
if [ -e $work/$1".in" ]; then 
	rm $work/$1".in"
fi
if [ -e $work/$1".out" ]; then 
	rm $work/$1".out"
fi
if [ -e $work/$1".cpp" ]; then
	g++ $work/$1".cpp" -o $work/a >&2
	if [ -e $work/a ]; then
		echo "file is cpp and was compiled" >&2
	else 
		echo "Compilation error" >&2
		printf "0\t"
		exit 0
	fi
elif [ -e $work/$1".pas" ]; then
	fpc $work/$1".pas" -o"$work"/a >&2
	if [ -e $work/a ]; then
		echo "file is pas and was compiled" >&2
	else 
		echo "Compilation error" >&2
		printf "0\t"
		exit 0
	fi
else
	echo "no source file found" >&2
	printf "0\t"
	exit 1
fi

res=0
cnt=0
for i in $2??; do
	cnt=$(( $cnt + 1 ))
	cp $i $work/$1".in"
	cp $i.a $work/ans
	if (( $std == 0 )); then
		./run --memsize=$ml --time=$tl --quiet $work/a
	else
		./run --memsize=$ml --time=$tl --quiet $work/a < $work/$1".in" > $work/$1".out"
	fi
	re=$?;
	if (( $re == 1 )); then
		echo "$cnt RE" >&2
		continue
	fi
	$work/check $work/$1".in" $work/ans $work/$1".out" 2>&2
	if (( !$? )); then
		res=$(( $res + 1 ))
 		echo "$cnt AC" >&2
	else
		echo "$cnt WA" >&2
	fi
done;

printf "%d\t" $(( $res * 100 / $cnt ))
printf "\n\n\n" >&2

exit 0
