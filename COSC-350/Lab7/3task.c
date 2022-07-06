/* Name: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/12/19
 * 
 */

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    
    //make child & open foo
    int pid = fork();
    int fd = open("foo", O_RDWR);
    if(pid == 0){
        //child writes to foo
        write(fd, "Hi Mom", 6);
        
    } else {
        //wait for child then write to stdout
       wait();
       char buffer[1];
       lseek(fd, 0, SEEK_SET);
       write(1, "My son said ", 12);
       
       while(read(fd, buffer, 1)){
           write(1, buffer, 1);
           
       }
    }
    
    close(fd);
    return 0;
}
