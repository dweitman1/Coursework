#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    
    int bytes;
    int offset;
    int count = -1;
    char buffer[1];
    
    int filedes = open("foo", O_RDWR, 0770);//open foo 
    int filedes2 = creat("foorev", 0760);////create file for reversed foo
    
    offset = lseek(filedes, -2, SEEK_END);
    
    //loop to read byte by byte until beginning of foo is reached
    while (read(filedes, buffer, 1) > 0 && offset > -1){
        offset = lseek(filedes, -1, SEEK_CUR);//sets offset to next reversed string
        write(filedes2, buffer, 1);//writes to foorev
        offset = lseek(filedes, -1, SEEK_CUR);//sets offset back to next reversed string
        
    }
    
    //cleans up output
    offset = lseek(filedes2, 0, SEEK_END);
    write(filedes2, "\n", 1);
    
    exit(0);
}
