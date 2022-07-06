#!/bin/bash

for i in {1..5}
    do
       for j in {1..$i}
            do
                echo -n \*
            done
            
            if [$i -eq 5]
            then
                echo
                for k in {4..1}
                    do 
                        for l in {1..$k}
                            do
                                echo -n \*
                            done
                echo
                done
            fi
        echo 
    done
