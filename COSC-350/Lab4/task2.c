#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  
  if(argc != 3){
    printf("Invalid parameters passed.\n");
    exit(-1);
  }
  
  int fd1;
  if((fd1 = open(argv[1], O_RDWR)) == -1){
      write(1, "Open error.\n", 12);
      exit(-1);
  }
  int fd2;
  if((fd2 = open(argv[2], O_RDWR)) == -1){
      printf("Cannot open output file... Creating file\n");
      fd2 = creat(argv[2], 0666);
  }
  
  char buffer[1];
  
  while(read(fd1, buffer, 1) > 0){
    write(fd2, buffer, 1); 
    
  }
  
  close(fd1);
  close(fd2);
  exit(0);
}

