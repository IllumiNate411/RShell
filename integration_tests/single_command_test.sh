#!/bin/sh

INPUTS=("ls -a" "echo hello" "git status")

echo "Executing .././rshell ${INPUTS[2]}"
.././rshell ${INPUTS[2]}
