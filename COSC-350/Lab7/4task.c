/* Name: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/12/19
 * 
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

void sig_handler(int signo){
    if(signo == SIGUSR1){
        //user defined signal 1
        printf("Hi Honey! Anything wrong?\n");
    } else if(signo == SIGUSR2){
        //user defined signal 2
        printf("Do you make trouble again?\n");
    }
    
}

int main(){
    
    int pid = fork();
    int ppid;
    int cpid;
           
    if(pid == 0){
        //printf("\nIn child\n");
        int ppid = getppid();
        int cpid = fork();
        
        if(cpid == 0){
            cpid = getppid();
            //printf("In Grandchild\n");
            waitpid(getppid(), NULL, 0);
            kill(ppid, SIGUSR2);
            exit(0);
        } else {
            //printf("Back in child\n");
            kill(ppid, SIGUSR1);
            exit(0);
        }
        
    } else {
        //in parent process
        signal(SIGUSR1, sig_handler);
        waitpid(cpid, NULL, 0);
        pause();
        signal(SIGUSR2, sig_handler);
        pause();
            
    }
    
    return 0;
}
