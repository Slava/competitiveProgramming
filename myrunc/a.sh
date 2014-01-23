#!/bin/bash
#GEDIT='gvim --servername GVIM --remote-tab'
GEDIT=gedit
a=a
export GEDIT


open_project(){
	cd ~/work/pr
	stty echo
	select pr in *; do
		work=$pr
		break
	done
	stty -echo
	cd $work
	$GEDIT $a.cpp > /dev/null 2>&1 &
}

new_project() {
	cd ~/work/pr
	echo -e "Enter name of new project"
	stty echo
	read name
	stty -echo
	if [[ -d $name ]]; then 
		echo such project already exists
		cd $work
	else
		mkdir $name
		cd $name
		work="$name"
		$GEDIT $a.cpp > /dev/null 2>&1 &
	fi
}

inform() {
	clear
	col=$( tput cols )
	st=$(( $col - 34 ))
	ramka=$(( $st - 2 ))
	for((i=0;i<=24;i++)); do
		echo -e "\E[${i};${ramka}f\E[40;40m|\033[0m"
	done
	echo -en "\E[0;${st}fproject: "
	echo -e '\E[35;40m'"\033[1m$work\033[0m"
	echo -en "\E[2;$(( $st + 3 ))fmain: "
	echo -e '\E[35;40m'"\033[1m$a\033[0m"
	for((i=1;i<=20;i++)); do
		echo -e -n "\E[$(( $i + 3 ));${st}f$i"
		if [[ -e $a.in.$i ]]; then
			printf "\ttest"
		else
			printf "\t"
		fi
		if [[ -e $a.expect.$i ]]; then
			printf "\tans"
		else
			printf "\t"
		fi
		if [[ -e $a.out.$i ]]; then
			printf "\tout"
		else
			printf "\t"
		fi
		if [[ -e $a.bak.$i ]]; then
			printf "\tbak"
		else
			printf "\t"
		fi
		echo
	done
}

add_test() {
	for((i=1;i<=1000;i++)); do
		if [[ -e $a.in.$i ]]; then
			true
		else
			T=$i
			break
		fi
	done
	echo create test no $T
	$GEDIT $a.in.$T > /dev/null 2>&1
	echo create expected output? y/n
	read -s -n 1 B
	case $B in
		"y" | "Y" ) $GEDIT $a.expect.$T > /dev/null 2>&1 &;;
		*) echo "no ans will be created"
	esac
}

run() {
	echo -e "\E[25;0f"
	runc $a.cpp
	echo 
	echo "continue?"
	read -s -n 1 b
#	if [[ -e a.compile.err ]]; then
#		$GEDIT a.compile.err
#	fi
}

execute(){ 
	stty echo
	echo -n '$ '
	read cmdaaa
	echo $cmdaaa will be executed
	$cmdaaa
	stty -echo
	echo 
	echo "continue?"
	read -s -n 1 b
}

edit() {
	stty echo
	echo -n "Edit: "
	read name
	$GEDIT "$name" > /dev/null 2>&1 &
	stty -echo
}

backup() {
	echo BackUp file...
	for((i=1;i<1000;i++)); do
		if [[ -e $a.bak.$i ]]; then
			true
		else 
			T=$i
			break
		fi
	done
	echo "name for backup will be $T,"
   	echo "agree(y) or change suffix(n)?"
	read -s -n 1 B
	if [[ $B == "n" || $B == "N" ]]; then
		stty echo
		echo "Enter your suffix"
		read T
		stty -echo
	fi
	echo "$a.bak.$T"
	cp $a.cpp $a.bak.$T
}

recover() {
	echo "Recover file from backup"
	stty echo
	select name in $a.bak.*; do
		echo will recover from $name
		cp $name $a.cpp
		break
	done
	stty -echo
}

_help() {
	echo -e "\033[1mo\033[0mpen project"
	echo -e "\033[1mn\033[0mew project"
	echo -e "\033[1ma\033[0mdd test"
	echo -e "\033[1me\033[0mdit file"
	echo -e "\033[1mb\033[0mackup source"
	echo -e "\033[1mr\033[0mecover source"
	echo -e "\033[1mg\033[0men tests or anses"
	echo -e "\033[1mm\033[0move to ~/work/ folder"
	echo -e "\033[1m:\033[0m execute command"
	echo -e "\033[1m?\033[0m help"
	echo -e "\033[1mq\033[0muit"
	echo 
	echo "continue?"
	read -s -n 1 b
}

clear
stty -echo
echo -e "\E[0;0f"
open_project
clear
while true; do
	inform
	echo -e -n "\E[0;0f>>"
	read -s -n 1 b
	echo $b
	case $b in
		"o" ) open_project;;
		"n") new_project;;
		"a") add_test;;
		"q") stty echo
			clear
			exit;;
		"t") run;;
		"e") edit;;
		"b") backup;;
		"r") recover;;
		"g") gen;;
		"m") cp $a.cpp ~/work/$work.cpp;;
		":") execute;;
		"?") _help;;
		*) echo "error"
	esac
done
