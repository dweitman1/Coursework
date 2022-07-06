#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    
    umask(0);
    mkdir("dweitman", 0777);

    mkdir("dweitman/Dir2", 0777);
    
    mkdir("dweitman/Dir2/Dir21", 0777);
    
    mkdir("dweitman/Dir1", 0777);
    
    link("/home/Documents/COSC350/hello", "/home/Documents/COSC350/dweitman/Dir2/Dir21/hello");
    
    symlink("/home/Documents/COSC350/dweitman1/Dir1/toDir12", "/home/Documents/COSC350/dweitman1/Dir2/Dir21");
}
  
