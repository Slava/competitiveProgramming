@ echo off
copy %1 input.txt
run -t 2s -m 64M ugol
echo %1
fc %1.a output.txt
pause
