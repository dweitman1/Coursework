/* Daniel Weitman
 * COSC-350
 * Park
 * 4/5/19
 */

#include <sys/types.h>
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
    
    printf("fork program starting\n");
    pid = fork();
    switch(pid) 
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n = Nc;
            break;
        default:
            message = "This is the parent";
            n = Np;
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
    exit(0);
}
