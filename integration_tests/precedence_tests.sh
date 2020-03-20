#!/bin/sh

INPUTS=("(echo A)" "(echo A && echo B) || echo C" "(echo A && echo B) || (echo C && echo D)" "ls -a; (echo Hi && echo Bye) || (git status && ls -j)" "test -d src && (echo Exists || ls -a)" "[ header ]; ((echo A && ls -j) || echo B)")

for input in "${INPUTS[@]}"
do
        echo "------Testing: ${input}--------"
        eval ${input}
done

