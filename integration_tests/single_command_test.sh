#!/bin/sh

INPUTS=("ls -a" "echo hello" "git status")

for input in "${INPUTS[@]}"
do 
	echo "../rshell ${input}"
	output=$(./c-echo ${input})
	if [ "$(output}" = "${input}" ]	
	then
		echo "Test passed"
	else
		echo "test failed"
		echo "Expected: \"${input}\""
		echo "Recieved: \"${output}\""
	fi
done
