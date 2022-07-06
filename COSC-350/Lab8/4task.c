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

int main(int argc, char* argv[]){
    
    char *cmd = malloc(sizeof(char) * 128);
    char *scmd = malloc(sizeof(char) * 128);
    char *fptr = malloc(sizeof(char) * 128);
    char buf[1024];
    FILE *ptr;
    int i = 0;
    int bytes;
    
    //Get shell cmd from usr
    write(1, "Enter shell command: ", 21);
    bytes = read(0, buf, 256);
    
    for(i = 0; i < bytes; i++){
        //copy buf to cmd
        cmd[i] = buf[i];
    }
    cmd[bytes - 1] = ' ';
    int bytes1;
    
    //Get file name from usr
    write(1, "Enter file name: ", 17);
    bytes1 = read(0, buf, 256);
    
    for(i = 0; i < bytes1; i++){
        //Concatenate buf to cmd
        cmd[bytes + i] = buf[i];
    }
    
    //String 
    strcat(cmd, scmd);
    strcat(cmd, fptr);
    //printf("%s", cmd);
    
    //popen() child process to exe shell cmd on file
    if((ptr = popen(cmd, "r")) != NULL){
        //write child processes work through STDOUT
        while(fgets(buf, 1024, ptr) != NULL)
            (void) printf("%s", buf);
        
    }
    
    //pipe close
    pclose(ptr);
    
    return 0;
    
}
