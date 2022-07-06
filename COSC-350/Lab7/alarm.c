/* Name: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/12/19
 * 
 */

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

void ding(int sig){
    alarm_fired = 1;
}

int main(){
    
    pid_t pid;
    
    printf("alarm starting\n");
    
    pid = fork();
    switch(pid){
        //Error check 
        case -1:
            perror("forked failed");
            exit(1);
        //Child process calls alrm
        case 0:
            sleep(5);
            kill(getppid(), SIGALRM);
            exit(0);
    }
    
    //place function ding into sigaction function
    struct sigaction act;
    act.sa_handler = ding;
    
    printf("Waiting for alarm to go off\n");
    (void) sigaction(SIGALRM, &act, NULL);
    
    pause();
    
    //check if signal was recieved
    if(alarm_fired){
        printf("Ding!\n");
    }
    
    printf("done\n");
    exit(0);
}
    
