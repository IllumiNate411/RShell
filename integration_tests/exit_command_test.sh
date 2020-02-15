#!/bin/sh

echo TEST_1: "echo hi; exit"
eval "echo hi; exit"

echo TEST_2: "exit; echo hello"
eval "exit; exho hello"
