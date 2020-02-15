#!/bin/sh


echo TEST_1: "echo hello; in haha # echo thisshouldprint"
eval "echo hello; in haha # echo thisshouldprint"

echo TEST_2: "echo hello; ls -a # echo maybe?"
eval "echo hello; ls -a # echo maybe?" 
