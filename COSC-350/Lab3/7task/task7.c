#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//changes int to char*
char* myitoa(int x, char *str){
  
  int a = (x%10);
  int b = (x%100)/10;
  int c = (x%1000)/100;
  
  str[0] = '0' + c;
  str[1] = '0' + b;
  str[2] = '0' + a;
  
  //printf("%s\n",str);
  
  return str;
  
}

//takes a file from command line and converts to ascii value in another file
int main(int argc, char *argv[]){
  
    //checks arguments passed
  if(argc != 3){
    write(1, "Invalid parameters\n",  19);
    exit(1);
  }
  
  //opens two files passed
  int filedes = open(argv[1], O_RDONLY);
  int filedes2 = open(argv[2], O_RDWR);
  
  //checks open error
  if(filedes == -1 || filedes2 == -1){
    write(1, "Cannot open files properly", 26);
  }
  
  char buffer[1];
  char str[3];
  int ASC;
  char b;
  char c[1];
  
  //reads each char and sends to new file
  while(read(filedes, buffer, 1) > 0){
 
    b = buffer[0];
    //printf("%c",b);
    ASC = b;
    //printf("%d\n", ASC);
    
    // '0' + 8 -> ascii for '8'
    write(filedes2, myitoa(ASC, str), 3);
    write(filedes2, " ", 1);
    
  }
  exit(0);
}
