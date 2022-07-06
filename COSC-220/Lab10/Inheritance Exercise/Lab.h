#ifndef LAB_H
#define Lab_H 
#include "GradedActivity.h"

class Lab : GradedActivity{
    
    public:
        Lab();
        Lab(double);
        void setScoreLab(double);
        virtual char getLetterGrade();
};


char Lab :: getLetterGrade(){
 
    if(score > 14){
        return 'C';
    } else {
        return 'I';
    }
}

#endif
