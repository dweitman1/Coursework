/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/26/19
 * task 2
 * 
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    int data_processed;
    char buffer[BUFSIZ + 1];
    int file_descriptor;
    
    memset(buffer, '\0', sizeof(buffer));
    
    sscanf(argv[1], "%d", &file_descriptor);
    data_processed = read(file_descriptor, buffer, BUFSIZ);
    printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
    
    /*
    //d. Close the file descriptor of the read end of the pipe on the child's side.
    close(atoi(argv[1]));
    */
    
    exit(EXIT_SUCCESS);
    
}
