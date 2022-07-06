#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//Program to copy foo to clone2 0770 using 32 buffer size
int main(){
    
    int bytes;
    char buffer[32];
    
    int filedes = open("foo", O_RDWR);//Open foo
    int filedes2 = creat("clone2", 0770);//Create 'clone1' file with rwxrwx___
    
    //Loop to read filedes and write
    while((bytes = read(filedes, buffer, 32)) > 0){
        
        //write to clone1 and write error check
        if(write(filedes2, buffer, bytes) != bytes){
            write(1, "Write error\n", 11);
        }
        //read error check
        if(bytes < 0){
            write(1, "Read error\n", 10);
        }
        
        
    }
    
    exit(0);
}
