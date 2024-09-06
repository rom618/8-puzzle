#!/bin/bash

# Delete existing binary file
rm -f 8_puzzle

# Compile C file
gcc -o 8_puzzle main.c

# Verify compilation success
if [ $? -eq 0 ]; then
    echo "Compilation OK. Executing 8_puzzle."

    # Execute program
    ./8_puzzle
else
    echo "Compilation KO. Execution failed."
fi
