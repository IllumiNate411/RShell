#!/bin/sh

INPUTS=("test -f echo hello" "test status" "test -f ls -a -l")

for input in "${INPUTS[@]}"
do
	        echo "------Testing: ${input}--------"
		        ${input}
		done

