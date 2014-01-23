C:\FPC\2.0.2\bin\i386-win32\ppc386 fib.pas
dcc32 -cc fib.dpr
for %%i in (1,2,3,4,5,6,7,8,9,10) do call test %1 %%i