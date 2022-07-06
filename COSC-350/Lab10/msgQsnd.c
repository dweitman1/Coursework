/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Date: 5/3/19
 * task 1
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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
    
    //Creates a key for msgQsnd
    if((key = ftok("msgQsnd.c", 'B')) == -1) {
        perror("ftok error");
        exit(1);
    }
    
    //Creates a msgQ of type rw-r--r-- 
    if((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget error");
        exit(1);
    } 
    
    printf("Enter two integers\n");
    buf.mtype = 1; 
    
    //Reads stdin and checks string for ints
    while(fgets(buf.mtext, 256, stdin) != NULL) {
        sscanf(buf.mtext, "%d%d", &buf.a, &buf.b);
        
        //Send struct my_msgbuf to msgQ
        if(msgsnd(msqid, (struct my_msgbuf *)&buf, sizeof(buf), 0) == -1)
            perror("msgsnd error");
    }
    
    //Destroy msgQ
   if(msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl error");
        exit(1);
    }
    exit(0);
}
