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

int main(){
    
    int data_processed, i;
    int file_pipes[2];//P to C
    int file_pipes1[2];//C to P
    const char some_data[] = "Hi there, Kiddo";
    char buffer[BUFSIZ + 1];//Parent read char arr
    char buffer1[BUFSIZ + 1];//pipe read
    char buffer2[BUFSIZ + 1];//pipe write
    char buffer3[BUFSIZ + 1];//pipe1 read
    char buffer4[BUFSIZ + 1];//pipe1 write
    pid_t fork_result;
    
    memset(buffer1, '\0', sizeof(buffer1));
    memset(buffer2, '\0', sizeof(buffer2));
    memset(buffer3, '\0', sizeof(buffer3));
    memset(buffer4, '\0', sizeof(buffer4));
    
    if (pipe(file_pipes) == 0 && pipe(file_pipes1) == 0) {
        fork_result = fork();
        
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
            
        }
        if (fork_result == 0) {
            //copy fd's into corresponding buffers
            *buffer1 = file_pipes[0] + '0';
            *buffer2 = file_pipes[1] + '0';
            *buffer3 = file_pipes1[0] + '0';
            *buffer4 = file_pipes1[1] + '0';
            
            (void)execl("twoPipeChild", "twoPipeChild", buffer1, buffer2,
                                            buffer3,buffer4, (char *)0);
            exit(EXIT_FAILURE);
            
        }
        else {
            close(file_pipes[0]);
            close(file_pipes1[1]);
            
            //write to pipe
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            printf("%d - wrote %d bytes\n", getpid(), data_processed);
            //sleep(.5);
            
            //read from pipe1
            data_processed = read(file_pipes1[0], buffer, BUFSIZ);
            printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
    
            wait(NULL);
            
            close(file_pipes[1]);
            close(file_pipes1[0]);
        }
    }
    
    exit(EXIT_SUCCESS);
}
