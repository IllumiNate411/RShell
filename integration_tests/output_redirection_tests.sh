#!/bin/sh

INPUTS=("echo Hello > sample.txt" "cat < sample.txt" "ls -a > sample.txt" "cat < sample.txt" "cat sample.txt >> sample.txt" "cat < sample.txt" "echo goodbye > sample.txt && echo success")

for input in "${INPUTS[@]}"
do
        echo "------Testing: ${input}--------"
        eval ${input}
done

