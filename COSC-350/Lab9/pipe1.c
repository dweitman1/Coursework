/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/26/19
 * task 1
 * 
 * Part D: When read()/write() execute in opposite order, the read() 
 * acts on an empty pipe. The write() places some_data into file_pipes[1]
 * and is never read;
 *
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Global variables to make code more readable on pipes
const int READ_END = 0;
const int WRITE_END = 1;

int main(){
    
    int data_processed;
    int file_pipes[2];
    
    const char some_data[] = "123";
    char *buffer = malloc(sizeof(some_data));//Dynamically allocate buffer
    
    buffer = some_data;//Set buffer equal to the string in some_data
    
    //memset(buffer, '\0', sizeof(buffer));
    
    if(pipe(file_pipes) == 0){
        
        data_processed = write(file_pipes[WRITE_END], some_data, strlen(some_data));
        //data_processed = read(file_pipes[0], buffer, BUFSIZ);
        printf("Write %d bytes\n", data_processed);
        
        data_processed = read(file_pipes[READ_END], buffer, sizeof(buffer));
        //data_processed = write(file_pipes[1], some_data, strlen(some_data));
        printf("Read %d bytes: %s\n", data_processed, buffer);
        
        
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_SUCCESS);
}
