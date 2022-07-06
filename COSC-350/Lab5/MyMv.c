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

int main(int argc, char *argv[]){
    
    //Checks for enough arguments
    if(argc != 3){
        printf("Invalid Arguments\n");
        exit(-1);
    }
    
    //Define struct stat buff to discern # links on a file
    struct stat buff;
    stat(argv[1], &buff);
    printf("%d\n", buff.st_nlink);
    
    //Reformats argument strings for linking
    char str[128] = "";
    char str2[128] = "";
    strcat(str, "./");
    strcat(str, argv[1]);
    printf(str);
    strcat(str2, argv[2]);
    strcat(str2, "/");
    strcat(str2, argv[1]);
    printf("\n");
    printf(str2);
    printf("\n");
    
    //link file into specified directory
    if(link(str, str2) < 0){
        
        //link new file name if argument is not directory
        if(link(str, argv[2]) < 0){
            printf("Link error\n");   
            exit(-1);
            
        //Unlinks old path of the file
        } else {
            stat(argv[1], &buff);
            printf("%d\n", buff.st_nlink);
    
            if(unlink(str) < 0){
                printf("Unlink error\n");   
            }

            stat(argv[2], &buff);
            printf("%d\n", buff.st_nlink);
        }
        
    //Unlinks old path of the file
    } else {
        stat(argv[1], &buff);
        printf("%d\n", buff.st_nlink);
    
    
        if(unlink(str) < 0){
            printf("Unlink error\n");   
        }

        stat(str2, &buff);
        printf("%d\n", buff.st_nlink);
        
    }
    
    return 0;
}
