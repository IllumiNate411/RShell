#!/bin/sh

INPUTS=("cat < sample.txt | tr A-Z a-z | tee newsample.txt | tr a-z A-Z > newsample.txt")

for input in "${INPUTS[@]}"
do
        echo "------Testing: ${input}--------"
        eval ${input}
done

