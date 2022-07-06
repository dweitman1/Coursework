/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 4/19/18
 * 
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int *arr[20];
int sz = 1;

int sort(){
    //Function for insertion sort
    int j;
    int k;
   
    for(int i = 1; i < sz; i++){
        k = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > k){
            arr[j + 1] = arr[j];
            j = j - 1;
            
        }
            
        arr[j + 1] = k;
    }
}
void *populate(void *);
void *meanmedian(void *);
void *minmax(void *);

int main(){
    
    //Declare 3 new threads
    pthread_t threads[3];
    
    printf("Creating threads...\n");
    
    //Create all threads and send to appropriate functions w args
    pthread_create(&threads[0], NULL, populate, NULL);
    pthread_create(&threads[1], NULL, meanmedian, (void *)threads[0]);
    pthread_create(&threads[2], NULL, minmax, (void *)threads[0]);
    
    //Main thread must wait for threads 2&3 to finish
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    
    
    printf("All threads done.\n");
    
    pthread_exit(NULL);
    return 0;
}

void *populate(void *para){
    //Populate array through STDIN
    int x = 0;
    
    for(int i = 0; i < 20; i++){
        printf("Type in a number (Negative to quit): ");
        scanf("%d", &x);
        if(x < 0){
            break;
        } else {
            arr[i] = x;
            sz++;
        }
    }
    sz--;
    //Sort for easier use later
    sort();
    
    pthread_exit(NULL);
}

void *meanmedian(void *para){
    
    //Don't continue until thread 3 unlocks the mutex
    pthread_mutex_lock(&mutex);
    
    double sum = 0;
    int median;
    int mid = (sz/2);
    
    if(sz % 2 == 1){
        
        for(int i = 0; i < sz; i++){
            sum = (double) (sum + (int) arr[i]);
            if(mid == i){
               median = arr[i]; 
            }
            
        }
        
        
    } else {
        
        for(int i = 0; i < sz; i++){
            sum = (double) (sum + (int) arr[i]);
            if(mid == i){
                mid = arr[i - 1];
                median = arr[i];
                median = (mid + median)/2;
            }
            
        }
    }
    
    sum = (sum)/sz;
    printf("Average: %g\n", sum);
    printf("Median: %d\n", median);
    
    pthread_exit(NULL);
}

void *minmax(void *para){
    //Lock mutex until thread 1 has completed so threads 2&3 can work concurrently
    pthread_mutex_lock(&mutex);
        pthread_join((pthread_t) para, NULL);
        sleep(1);
    //Mutex unlocked
    pthread_mutex_unlock(&mutex);
    
    //Thread 2 work
    printf("Min: %d\n", arr[0]);
    printf("Max: %d\n", arr[sz - 1]);
    pthread_exit(NULL);
}




