#!/bin/sh

INPUTS=("echo hello" "git status" "ls -a -l")

for input in "${INPUTS[@]}"
do
	echo "------Testing: ${input}--------"
	${input}
done
