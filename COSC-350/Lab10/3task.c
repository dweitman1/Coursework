/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 5/3/19
 * task 2
 * 
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *producer(void *);
void *consumer(void *);

char buff[256];
int i = 0;

int main(){
    
    pthread_t threads[2];
    int *o;
    
    pthread_create(&threads[0], NULL, producer, o);
    pthread_create(&threads[1], NULL, consumer, o);

    pthread_exit(NULL);
 
    exit(0);
}

void *producer(void *para){
    printf("In producer\n");
    for(i = 0; i == i; i++){
        sleep(1);
        if(i%4==0){
            strcpy(buff, "i % 4 == 0\n");
        } else if (i%4==1){
            strcpy(buff, "i % 4 == 1\n");
        } else if (i%4==2){
            strcpy(buff, "i % 4 == 2\n");
        } else if (i%4==3){
            strcpy(buff, "i % 4 == 3\n");
        }
        
    }
    
    pthread_exit(NULL);
}

void *consumer(void *para){
    printf("In consumer\n");
    for(i = 0; i == i; i++){
        sleep(1);
        if(i%4==0){
            write(1, buff, 11);
        } else if (i%4==1){
            write(1, buff, 11);
        } else if (i%4==2){
            write(1, buff, 11);
        } else if (i%4==3){
            write(1, buff, 11);
        }
        
    }
    
    pthread_exit(NULL);
}

