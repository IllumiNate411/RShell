#!/bin/sh

INPUTS=("test -f src" "test -d src" "test src" "test src/rshell.cpp" "test -f src/rshell.cpp" "test -d src/rshell.cpp" "test -f CMakeLists.txt" "test -d CMakeLists.txt" "test CMakeLists.txt" "test -e CMakeLists.txt" "test -e src/rshell.cpp")

for input in "${INPUTS[@]}"
do
	echo "------Testing: ${input}--------"
	eval ${input}
done
