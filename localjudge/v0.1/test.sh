#!/bin/bash

#test problem $1

if (( ! (($#)) )); then
	echo "no args" >&2
	exit 1
fi
echo "" >&2
echo "testing "$3" problem "$1" : " >&2
if [ -e a ]; then 
	rm a 
fi
if [ -e $1".in" ]; then 
	rm $1".in"
fi
if [ -e a ]; then 
	rm $1".in"
fi
if [ -e $1".cpp" ]; then
	g++ $1".cpp" -o a
	if [ -e a ]; then
		echo "file is cpp and was compiled" >&2
	else 
		echo "Compilation error" >&2
		printf "0\t"
		exit 0
	fi
elif [ -e $1".pas" ]; then
	fpc $1".pas" -oa
	if [ -e a ]; then
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
	cp $i $1".in"
	cp $i.a ans
	./a
	./check $1".in" ans $1".out" 2>&2
	if (( !$? )); then
		res=$(( $res + 1 ))
		echo "$cnt AC" >&2
	else
		echo "$cnt WA" >&2
	fi
done;

bc <<- EOF
	ans=100.0 * $res
	ans=ans / $cnt
	print ans, "\t"
EOF

exit 0
