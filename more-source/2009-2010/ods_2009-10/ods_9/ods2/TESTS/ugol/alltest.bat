C:\FPC\2.0.2\bin\i386-win32\ppc386 ugol.pas
dcc32 -cc ugol.dpr
for %%i in (1,2,3,4) do call test %1 %%i