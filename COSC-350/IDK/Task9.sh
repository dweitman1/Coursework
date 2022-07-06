#!/bin/sh

echo "What directory would you like to search?"
read directory

if [ -d $directory ]
    then
        echo "The directory exists"
else
    echo "The directory doesn't exist"
    exit 1
    
    #cd ./$directory
    
echo "What file would you like to search?"
read file
for i in {1..3}
do
if [ -e $file ]
    then
        echo "The file exists"
        
elif [ -e $file]  
    then
        

else
    echo "The file doesn't exist"
    
    exit 2
fi 
done

    cd ./$directory
    
        
