#!/bin/sh

INPUTS=("git status && ls" "git status && echo yippee")

for input in "${INPUTS[@]}"
do
        echo "------Testing: ${input}--------"
        eval ${input}
	
done

