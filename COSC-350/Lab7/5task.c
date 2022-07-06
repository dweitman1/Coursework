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
#include <time.h>

int main(){

    time_t t;
    sigset_t one;
    
    //adds SIGINT & SIGQUIT to blocked
    sigemptyset(&one);
    sigaddset(&one, SIGINT);
    sigaddset(&one, SIGQUIT);
    sigprocmask(SIG_BLOCK, &one, NULL);
    
    printf("First loop starting\n");
    for(int i = 0; i < 5; i++){
        t = time((time_t *)0);
        printf("#%d completed: %s", i + 1, asctime(localtime(&t)));
        sleep(1);
    }
    
    //unblock SIGQUIT
    sigdelset(&one, SIGINT);
    sigprocmask(SIG_UNBLOCK, &one, NULL);
    
    printf("\nSecond loop starting\n");
    for(int i = 0; i < 5; i++){
        t = time((time_t *)0);
        printf("#%d completed: %s", i + 1, asctime(localtime(&t)));
        sleep(1);
    }
    
    //Reset set mask
    sigemptyset(&one);
    sigprocmask(SIG_SETMASK, &one, NULL);
    
    return 0;
}
