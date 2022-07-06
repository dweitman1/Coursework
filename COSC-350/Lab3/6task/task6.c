#include <stdio.h>
#include <stdlib.h>
//Changes char* to an int value
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

//Adds command line arguments and prints the sum
int main(int argc, char* argv[]){
    
    //command line arguments check
   if(argc == 1){
        printf("No parameters to sum!");
          printf("\n");
        exit(1);   
    }
    
    int sum = 0;
    //Loop to sum all arguments
    for(int i = 1; i < argc; i++){
        sum += myatoi(argv[i]);
    }
    
    //prints Summation
    printf("Summation: %d", sum);
    printf("\n");
    
    exit(0);
}
