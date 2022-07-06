#ifndef PASSFAILEXAM_H
#define PASSFAILEXAM_H 

#include "GradedActivity.h"

class PassFailExam : GradedActivity{
    
    private:
        double min;
    
    
    public:
        PassFailExam();
        PassFailExam(double);
        void setScorePFExam(double);
        virtual char getLetterGrade();
};


char PassFailExam :: getLetterGrade(){
 
   if(score >= min){
        return 'P';
   } else {
        return 'F';
   }
}

#endif
