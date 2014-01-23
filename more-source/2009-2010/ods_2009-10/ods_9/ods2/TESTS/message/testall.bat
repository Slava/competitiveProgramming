@echo off
for %%i in (??) do (
   echo TEST %%i : 
   copy %%i message.in >nul
   message.exe
   fc %%i.a message.out
   pause
)
del message.in message.out 2>nul
