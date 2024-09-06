#!/bin/bash

# Delete existing binary file
rm -f 8_puzzle

# Compile C file and verify compilation success
if gcc -o 8_puzzle ./*.c; then
    echo "Compilation OK. Executing 8_puzzle."

    # Execute program
    ./8_puzzle
else
    echo "Compilation KO. Execution failed."
fi
