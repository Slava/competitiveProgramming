#!/bin/bash
work=~/work/ejudge_kostili
for i in 01????; do
	cp $i/conf/serve.cfg $i/conf/serve.cfg.bak
	cp $i/conf/serve.cfg $work/
	$work/start $i > $work/file
	cat $work/serve.cfg.init >> $work/file
	$work/addition < $work/serve.cfg >> $work/file
	cp $work/file $i/conf/serve.cfg
done
