#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("Invalid arguments\n");
        exit(1);
    }
    
    int fd;
    umask(0);
    if((fd = open(argv[1], O_RDWR) < 0)){
        printf("Open error\n");
    }
    printf("FD: %d\n", fd);
    char buff[1];
    /*
    read(fd, buff, 1);
    write(1, buff, 1);
    /*
    int pid = fork();
    int coffset = 0;
    int poffset = 0; 
    
    if(pid == 0){
        coffset = 0;
        while(coffset += read(fd, buff, 1)){
            lseek(fd, (-1 * poffset), SEEK_CUR);
            poffset = 0;
            
                write(1, buff, 1);
            
        }
    } else {
        poffset = 0;
        while(poffset += read(fd, buff, 1)){
            lseek(fd, (-1 * coffset), SEEK_CUR);
            coffset = 0;
            
                write(1, buff, 1);
            
            
        }
        
         
    }
    */
    return 0;
    
}
