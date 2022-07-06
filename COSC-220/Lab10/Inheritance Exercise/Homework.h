#ifndef HOMEWORK_H
#define HOMEWORK_H 

#include "GradedActivity.h"

class Homework : GradedActivity{
    
    public:
        Homework();
        Homework(double);
        void setScoreHW(double);
        virtual char getLetterGrade();
};


char Homework :: getLetterGrade(){
 
    if(score > 19){
        return 'S';
    } else {
        return 'U';
    }
}

#endif
