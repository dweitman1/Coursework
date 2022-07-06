/* Author: Daniel Weitman
 * Course: COSC-350
 * Instructor: Park
 * Due: 3/29/19
 * 
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

char* myasctime(const struct tm *t){
    char ret[24] = "";
    int x;
    x = t->tm_wday;
    
    //if's to turn number of day into string
    if(x == 0){
        ret[0] = 'S';
        ret[1] = 'u';
        ret[2] = 'n';
    } else if (x == 1){
        ret[0] = 'M';
        ret[1] = 'o';
        ret[2] = 'n';
    } else if (x == 2){
        ret[0] = 'T';
        ret[1] = 'u';
        ret[2] = 'e';
    } else if (x == 3){
        ret[0] = 'W';
        ret[1] = 'e';
        ret[2] = 'd';
    } else if (x == 4){
        ret[0] = 'T';
        ret[1] = 'h';
        ret[2] = 'u';
    } else if (x == 5){
        ret[0] = 'F';
        ret[1] = 'r';
        ret[2] = 'i';
    } else if (x == 6){
        ret[0] = 'S';
        ret[1] = 'a';
        ret[2] = 't';
    } else {
        ret[0] = 'S';
        ret[1] = 'u';
        ret[2] = 'n';
    }
            
    x = t->tm_mon;
    
    //if's to turn number of month into string
    if(x == 0){
        ret[4] = 'J';
        ret[5] = 'a';
        ret[6] = 'n';
    } else if (x == 1){
        ret[4] = 'F';
        ret[5] = 'e';
        ret[6] = 'b';
    } else if (x == 2){
        ret[4] = 'M';
        ret[5] = 'a';
        ret[6] = 'r';
    } else if (x == 3){
        ret[4] = 'A';
        ret[5] = 'p';
        ret[6] = 'r';
    } else if (x == 4){
        ret[4] = 'M';
        ret[5] = 'a';
        ret[6] = 'y';
    } else if (x == 5){
        ret[4] = 'J';
        ret[5] = 'u';
        ret[6] = 'n';
    } else if (x == 3){
        ret[4] = 'J';
        ret[5] = 'u';
        ret[6] = 'l';
    } else if (x == 3){
        ret[4] = 'A';
        ret[5] = 'u';
        ret[6] = 'g';
    } else if (x == 3){
        ret[4] = 'S';
        ret[5] = 'e';
        ret[6] = 'p';
    } else if (x == 3){
        ret[4] = 'O';
        ret[5] = 'c';
        ret[6] = 't';
    } else if (x == 3){
        ret[4] = 'N';
        ret[5] = 'o';
        ret[6] = 'v';
    } else if (x == 3){
        ret[4] = 'D';
        ret[5] = 'e';
        ret[6] = 'c';
    } else {
        ret[4] = 'J';
        ret[5] = 'a';
        ret[6] = 'n';
    }
    
    x = t->tm_mday;
    //month day
    ret[8] = (x/10) + '0';
    ret[9] = (x%10) + '0';
    
    x = t->tm_hour;
    //hours
    ret[11] = (x/10) + '0';
    ret[12] = (x%10) + '0';
    
    x = t->tm_min;
    //mins
    ret[14] = (x/10) + '0';
    ret[15] = (x%10) + '0';
    
     x = t->tm_sec;
    //secs
    ret[17] = (x/10) + '0';
    ret[18] = (x%10) + '0';
    
    ret[20] = '2';
    ret[21] = '0';
    
    x = t->tm_year;
    //years
    ret[22] = (x/10) + '0';
    ret[23] = (x%10) + '0';
    
    //spaces & colons
    ret[3] = ' ';
    ret[7] = ' ';
    ret[10] = ' ';
    ret[13] = ':';
    ret[16] = ':';
    ret[19] = ' ';
    
    char* abc = ret;
    return abc;
}

int main(){
    
    struct tm tp;
   
    tp.tm_wday = 5;
    tp.tm_mon = 2;
    tp.tm_mday = 29;
    tp.tm_hour = 8;
    tp.tm_min = 0;
    tp.tm_sec = 0;
    tp.tm_year = 19;
   
    char str[24] = "";
    strcat(str, myasctime(&tp));
    
    printf("%s\n", str);
    
    return 0;
}
