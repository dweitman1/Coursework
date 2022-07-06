/* Daniel Weitman
 * COSC-350
 * Park
 * 4/5/19
 * 
 * Output in forkWait.c differs from fork1.c in that
 * it envokes the wait function that has the parent
 * process wait until the child process has finished 
 * before the parent starts to run.
 */


#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 5){
        printf("Invalid arguments\n");
        exit(1);
    }
    
    int Nc = atoi(argv[1]);
    int Np = atoi(argv[2]);
    int Tc = atoi(argv[3]);
    int Tp = atoi(argv[4]);
    
    pid_t pid;
    char *message;
    int n;
    int exit_code;
    
    printf("fork program starting\n");
    pid = fork();
    
    if(pid != 0){
        int stat_val;
        pid_t cpid;
        
        cpid = wait(&stat_val);
        
        printf("Child finished: PID = %d\n", cpid);
        
        if(WIFEXITED(stat_val)){
            printf("Child exited w/ code %d\n", WEXITSTATUS(stat_val));
        } else {
            printf("Child terminated abnormally\n");
        }
        
    }
    
    switch(pid) 
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n = Nc;
            exit_code = 37;
            break;
        default:
            message = "This is the parent";
            n = Np;
            exit_code = 0;
            break;
    }
    
    
    for(; n > 0; n--) {
        puts(message);
         if(pid == 0){
            sleep(Tc);
        } else {
            sleep(Tp);
        }
    }
    
    
    exit(exit_code);
}
