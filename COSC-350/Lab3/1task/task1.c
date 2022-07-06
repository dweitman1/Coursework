#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//Program to copy contents off file foo to a file clone
int main(){
    
    //function to use shell command to copy content
    system("cat foo > clone");
    
    exit(0);
}
