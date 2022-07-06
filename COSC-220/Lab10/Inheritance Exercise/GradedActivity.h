#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

// GradedActivity class declaration
using namespace std;

class GradedActivity
{
  protected:
    double score;   // To hold the numeric score
   
  public:
    // Default constructor
    GradedActivity()
    {
        score = 0.0;
    }

    // Accessor functions
    double getScore() const
    {
        return score;
    }
    
    virtual char getLetterGrade();
    //virtual String getGradeType();

};

#endif
