#!/bin/sh

echo TEST_1: type "echo hi; exit"
../rshell echo "echo hi; exit"

echo TEST_2: "exit; echo hi"
eval "exit; echo hello"
