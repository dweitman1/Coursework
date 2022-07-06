/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/19/18
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    
    int fd[2];
    int bytes, bytes1;
    int one, two;
    char buff[128];
    char buff1[128];
    pid_t pid;
    
    //pipe *fd processes
    if(pipe(fd) < 0){
        printf("pipe error\n");
    }
    //Fork two processes
    pid = fork();
    
    if(pid > 0){
        //Parent close read from pipe
        close(fd[0]);
        
        printf("Enter two integers\n");
        //Reads STDIN and sends to pipe
        while((bytes = read(0, buff, 128)) > 0){
            write(fd[1], buff, bytes);
            write(1, "Enter two integers\n", 19);
            
        }
        
    } else {
        //Child close write to pipe
        close(fd[1]);
        
        //Reads pipe and sums to STDOUT
        while((bytes1 = read(fd[0], buff1, 128)) != EOF){
            //Child continue until pipe is EOF
            if(sscanf(buff1, "%d%d", &one, &two) == 2){
                sprintf(buff1, "Sum:%d\n", one + two);
                bytes1 = strlen(buff1);
                
                if(write(1, buff1, bytes1) != bytes1){
                    printf("write error\n");
                }
                
            } else {
                if(write(1, "Invalid args\n", 13) != 13){
                    printf("write error\n");
                }
                
            } 
        }
    }
    
   return 0;
}
