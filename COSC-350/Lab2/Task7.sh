#!/bin/bash

echo $1

var=$1

while [var -ge 1]
    do
        let x=x*var
        let var--
    done
echo The factorial is $x
