#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//Copy file contents with open files
int main(){
    
    int bytes;
    char buffer[2];
    
    int filedes = open("foo", O_RDWR);//Open foo
    int filedes2 = creat("clone1", 0666);//Create 'clone1' file with rw_rw_rw_
    
    //Loop to read filedes and write
    while((bytes = read(filedes, buffer, 2)) > 0){
        
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
