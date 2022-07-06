#!/bin/sh


if [$# -ne 1]
    then
    echo "One numerical argument please"
    exit 0
fi

var=$1
x = 0
for i in {1..$#var}
    do 
    let x = x + i
    done
