/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/19/18
 * 
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *sum(void *);
void *fac(void *);

int main(int argc, char* argv[]){
    
    if(argc != 2){
        printf("Invalid arguments\n");
    }
    
    //Declare two threads
    pthread_t threads[2];
    int *o;
    o = atoi(argv[1]);
    
    //Create two threads with sum and factorial start routine
    pthread_create(&threads[0], NULL, sum, o);
    pthread_create(&threads[1], NULL, fac, o);
 
    //Exit main thread
    pthread_exit(NULL);
 
    exit(0);
}

void *sum(void *para){
    //Thread 1 comes here when created in main
    printf("In summation thread...\n");
    
    int sum = 0;
    for(int i = 1; i <= (int) para; i++){
        sum += i;
        
    }
    printf("Summation of %d is: %d\n\n", (int) para, sum);
    
    pthread_exit(NULL);
}

void *fac(void *para){
    //Thread 2 comes here when created in main
    printf("In factorial thread...\n");
    
    int fac = 1;
    for(int i = (int) para; i >= 1; i--){
        fac *= i;
        
    }
    printf("Factorial of %d is: %d\n\n",(int) para, fac);
    
    pthread_exit(NULL);
}

