#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

//Program that appends foo and foo1 to created file foo12 0760
int main(){
    
    int bytes;
    int offset;
    char buffer[2];
    
    int filedes = open("foo", O_RDWR, 0770);//open foo
    int filedes2 = open("foo1", O_RDWR, 0770);//open foo1
    int filedes3 = creat("foo12", 0760);//create foo 12 rwxrw____
    
    //Gives foo12 some data to make clear the appending
    write(filedes3, "Some file data", 14);
    offset = 0;
    offset = lseek(filedes3, 0, SEEK_END);
    
    
    write(filedes3, "\n", 1);//new line to signify append
    
    //Read foo to append to foo12
    while((bytes = read(filedes, buffer, 2)) > 0){
        
        //append and check write error
        if(write(filedes3, buffer, bytes) != bytes){
            write(1, "Write error\n", 11);
        }
        //check read error
        if(bytes < 0){
            write(1, "Read error\n", 10);
        }
    }
    
    //Read foo1 to append to foo12
    while((bytes = read(filedes2, buffer, 2)) > 0){
        
        //append and check write error
        if(write(filedes3, buffer, bytes) != bytes){
            write(1, "Write error\n", 11);
        }
        //check read error
        if(bytes < 0){
            write(1, "Read error\n", 10);
        }
        
        
    }
    
    //printf("The offset is:%d\n", offset);
    exit(0);
}
