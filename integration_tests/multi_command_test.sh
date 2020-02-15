#!/bin/sh

INPUTS=("git status && ls -a" "echo yippee; ls -a" "echo \"I am tired\" || ls -j")

for input in "${INPUTS[@]}"
do
        echo "------Testing: ${input}--------"
        ${input}
done

