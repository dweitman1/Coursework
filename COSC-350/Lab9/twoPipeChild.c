/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/26/19
 * task 3
 * 
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    
    int data_processed;
    const char msg[] = "Hi, Mom";
    char buffer[BUFSIZ + 1];
    int file_descriptor[4];
    
    memset(buffer, '\0', sizeof(buffer));
    
    //Copy argv[i] into file_descriptor[i - 1]
    sscanf(argv[1], "%d", &file_descriptor[0]);
    sscanf(argv[2], "%d", &file_descriptor[1]);
    sscanf(argv[3], "%d", &file_descriptor[2]);
    sscanf(argv[4], "%d", &file_descriptor[3]);
    
    close(file_descriptor[1]);
    close(file_descriptor[2]);
    
    //read from pipe
    data_processed = read(file_descriptor[0], buffer, BUFSIZ);
    printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
    
    //write to pipe1
    data_processed = write(file_descriptor[3], msg, strlen(msg));
    printf("%d - wrote %d bytes\n", getpid(), data_processed);
            
    close(file_descriptor[0]);
    close(file_descriptor[3]);
    
    exit(EXIT_SUCCESS);
}

