#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myatoi(char *st){
    int ret = 0;
    int sign = 1;
    int i = 0;
    
    if(st[0] == '-'){
        sign = -1;
        i++;
    }
    
    for(; st[i] != '\0'; ++i){
        ret = ret*10 + st[i] -'0';
    }
    
    return sign*ret;
}

int convIntToStr(char* str, int x){
    sprintf(str, "%d", x);
    return (strlen(str));
    
}

int main(int argc, char *argv[]){
    
    if(argc != 2){
        write(1, "Invalid Arguments\n", 18);
        exit(-1);
    }
  
    int fd;
    
    if((fd = open(argv[1], O_RDWR)) < 0){
        write(1, "Open error\n", 11);
    }
    
    
    char buffer[1];
    char str[80];
    int i = 0;
    int j = 0;
    
    while(read(fd, buffer, 1) > 0 && i <= 80){
        if(buffer[0] == 10){
            break;
        }
        
        if(buffer[0] > 47 && buffer[0] < 58){
            str[j] = buffer[0];
            j++;
        }
        
        i++;
    }
    
    //printf("%s\n", str);
    int x = myatoi(str);
    x+=10;
    int length = convIntToStr(str, x);
    write(1, str, length);
    write(1, "\n", 1);
    
    
    close(fd);
    exit(0);
}
