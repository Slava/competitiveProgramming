#!/bin/bash
for i in *; do
	if [ -d $i ]; then
		if [[ $i != "submits" && $i != "tests" ]]; then
			rm -rfi $i
		fi
	elif [[ $i != "clear.sh" && $i != "defaultoptions.txt" && $i != "gencustom.sh" && $i != "maketable" && $i != "options.txt" && $i != "readme.txt" && $i != "report.txt" && $i != "run" && $i != "test.sh" && $i != "testcustom.sh" && $i != "testgroup.sh" ]]; then
		rm -i $i
	fi
done;
