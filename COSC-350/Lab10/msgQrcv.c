/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 5/3/19
 * task 1
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct my_msgbuf {
    long mtype;
    char mtext[200];
    int a;
    int b;
};

int main(){
    struct my_msgbuf buf;
    int msqid;
    key_t key;
    
    //Find same key as in msgQsnd.c
    if((key = ftok("msgQsnd.c", 'B')) == -1) {  
        perror("ftok error");
        exit(1);
    }
    
    //Finds msgQ
    if((msqid = msgget(key, 0644)) == -1) {
        perror("msgget error");
        exit(1);
    }
    
    printf("Waiting on input to msg queue...\n");
    for(;;){ 
        
        //Goes through msgQ and prints some of buf.a and buf.b
        if(msgrcv(msqid, (struct my_msgbuf *)&buf, sizeof(buf), 0, 0) == -1) {
            perror("msgrcv error");
            exit(1);
        }
        printf("Summation: %d\n", (buf.a + buf.b));
    }
    return 0;
}
