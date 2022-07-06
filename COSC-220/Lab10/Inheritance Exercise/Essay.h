#ifndef ESSAY_H
#define ESSAY_H 

#include "GradedActivity.h"

class Essay : GradedActivity{
    
    private:
        double grammar;
        double spelling;
        double length;
        double content;
    
    public:
        Essay();
        Essay(double);
        void setScoreEssay(double);
        virtual char getLetterGrade();
};


char Essay :: getLetterGrade(){
 
    score = grammar + spelling + length + content;
    
    if(score > 89){
        return 'A';
    } else if (score > 79){
        return 'B';
    } else if (score > 69){
        return 'C';
    } else if (score > 59){
        return 'D';
    } else {
        return 'F';
    }
}

#endif
