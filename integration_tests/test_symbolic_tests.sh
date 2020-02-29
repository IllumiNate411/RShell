#!/bin/sh

INPUTS=("[ -f src ]" "[ -d src ]" "[ src ]" "[ src/rshell.cpp ]" "[ -f src/rshell.cpp ]" "[ -d src/rshell.cpp ]" "[ -f CMakeLists.txt ]" "[ -d CMakeLists.txt ]" "[ CMakeLists.txt ]" "[ -e CMakeLists.txt ]" "[ -e src/rshell.cpp ]")

for input in "${INPUTS[@]}"
do
        echo "------Testing: ${input}--------"
        eval ${input}
done

