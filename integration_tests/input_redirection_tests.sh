#!/bin/sh

INPUTS=("cat < names.txt" "cat < names.txt && echo success" "(echo A && cat < names.txt) || (echo B && echo C)")

for input in "${INPUTS[@]}"
do
        echo "------Testing: ${input}--------"
        eval ${input}
done

