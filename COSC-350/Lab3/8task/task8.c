#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//Doesn't work
int palind(int fd1, int fd2){
    
    char buf1[1];
    char buf2[1];
    
    int offset;
    
    read(fd1, buf1, 1);
    offset = lseek(fd2, -2, SEEK_END);
    read(fd2, buf2, 1);
    
}

int main(int argc, char *argv[]){
    
    if(argc != 2){
        printf("Need one file\n");
    }
    
    int fd1 = open(argv[1], O_RDWR);
    int fd2 = dup(fd1);
    
    palind(fd1, fd2);
    
    exit(0);
}
