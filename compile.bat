@echo off

@REM Delete existing binary file
del 8_puzzle.exe

@REM Compile C file
gcc -o 8_puzzle main.c random_sequence.c

@REM Verify compilation success
if %ERRORLEVEL% EQU 0 (
    echo Compilation OK. Executing 8_puzzle.

    @REM Execute program
    8_puzzle.exe
) else (
    echo Compilation KO. Execution failed.
)
