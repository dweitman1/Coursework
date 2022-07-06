/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Due: 3/29/19
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utmp.h>

int main(){
    
    //Opens the utmp file
    int fd;
    if((fd = open("/var/run/utmp", O_RDONLY)) < 0){
        printf("Open error");
    }
    
    //Displays fildes of utmp
    printf("utmp file descriptor: %d\n", fd);
    
    //Create struct for retrieving utmp user info
    struct utmp *buff;
    int x = -1 * fd;
    setutent();
    buff = getutent();
    printf("Usernames: ");
    //For every user print name and increment count
    while (buff){
        x++;
        if(buff->ut_type == USER_PROCESS){
            printf("%s\n", buff->ut_user);
        }
        buff = getutent();
    }
    
    printf("User count: %d\n", x);
    return 0;
    
}
