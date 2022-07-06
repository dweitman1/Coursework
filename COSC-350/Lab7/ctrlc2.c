/* Name: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/12/19
 * 
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ouch(int sig){
    //Print message upon signal
    printf("OUCH! - I got signal %d\n", sig);
    
}

int main(){
    
    struct sigaction act;
    //Set handler to ouch
    act.sa_handler = ouch; 
    sigemptyset(&act.sa_mask);
    
    //Resets signal function to default after one call
    act.sa_flags = SA_RESETHAND;
    
    sigaction(SIGINT, &act, 0);
    
    while(1){
        printf("Hello World!\n");
        sleep(1);
    }
    
}

