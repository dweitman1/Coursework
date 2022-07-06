#!/bin/bash

echo "Enter a number (5-9)"
read number
x=1
while [$x -eq 1]
    do

if [number -gt 9]
    then 
    echo "Invaid index try again (5-9)"
    read number
elif [number -lt 5]
    then 
    echo "Invaid index try again (5-9)"
    read number
else 
    $x=0
fi


for i in {1..$number}
    do
       for j in {1..$i}
            do
                echo -n "$i"
            done
        echo 
    done
