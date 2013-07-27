@echo off 
setlocal enabledelayedexpansion
:: this script finds all the primes <N.
set /a N=1000
set /a Nplus=%N%+1
set /a Npldiv=%Nplus%/2

:: list of numbers.
for /L %%i in (1,1,%N%) do set /a table[%%i]=1

:: initialise
set /a table[1]=0

:: sieve
for /L %%i in (2,1,%Npldiv%) do (
if "!table[%%i]!"=="1" (
for /L %%j in (%%i,%%i,%N%) do (
set /a table[%%j]=0
)
set /a table[%%i]=1
)
)

:: printout
for /L %%i in (1,1,%Nplus%) do (
if "!table[%%i]!"=="1" (
set /p="%%i, "<nul
)
)
:: clear line
echo.
pause
cls
