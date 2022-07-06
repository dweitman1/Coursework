/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/26/19
 * task 4
 * 
 * Part C: Command used: "mkfifo /task4_fifo"
 *         Possible command: "mknod /task4_fifo"
 * 
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//Global variables to make code more readable on pipes
const int READ_END = 0;
const int WRITE_END = 1;

int main(){
    
    int data_processed;
    //int file_pipes[2]; Use fifo instead
    
    const char some_data[] = "123";
    char *buffer = malloc(sizeof(some_data));//Dynamically allocate buffer
    
    buffer = some_data;//Set buffer equal to the string in some_data
    
    int fd;
    fd = open("task4_fifo", O_RDWR);//Open fifo file
    
    //if(pipe(file_pipes) == 0){//Use fifo not pipe
        
        //write to pipe
        data_processed = write(fd, some_data, strlen(some_data));
        printf("Write %d bytes\n", data_processed);
        
        //read from pipe
        data_processed = read(fd, buffer, sizeof(buffer));
        printf("Read %d bytes: %s\n", data_processed, buffer);
        
        
        exit(EXIT_SUCCESS);
    //}
    //exit(EXIT_SUCCESS);
}
