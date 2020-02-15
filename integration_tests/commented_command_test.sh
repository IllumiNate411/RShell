#!/bin/sh


echo TEST_1: "echo hello # echo thisshouldntprint"
eval "echo hello # echo thisshouldntprint"

echo TEST_2: "echo hello; ls -a # echo maybe?"
eval "echo hello; ls -a # echo maybe?" 
