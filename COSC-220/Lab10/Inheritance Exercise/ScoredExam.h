#ifndef SCOREDEXAM_H
#define SCOREDEXAM_H 

#include "GradedActivity.h"

class ScoredExam : GradedActivity{
    
    
    public:
        ScoredExam();
        ScoredExam(double);
        void setScoreSExam(double);
        virtual char getLetterGrade();
};


char ScoredExam :: getLetterGrade(){
 
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
