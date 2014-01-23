@ echo off
copy %1.in fib.in
run -t 3s -m 64M fib
echo %1
fc %1.out fib.out
pause
