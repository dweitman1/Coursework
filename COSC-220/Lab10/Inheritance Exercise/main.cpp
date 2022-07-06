#include <iostream>
#include <vector>
#include "GradedActivity.h"
#include "Lab.h"

using namespace std;

int main(){
 
    vector<GradedActivity*> grades;
    int selection;
    
    while(selection != 7){
    
    cout << "1. Input new lab grade.\n2. Input new homework grade.\n3. Input new scored exam grade.\n4. Input new pass/fail exam grade.\n5. Input new essay grade.\n6. Display grade information.\n7. Quit.\n" << endl; 
    
    cout << "Input selection: ";
    cin >> selection;
    
    if(selection == 1){
        
    } else if (selection == 2){
        
    } else if (selection == 3){
        
    } else if (selection == 4){
        
    } else if (selection == 5){
        
    } else if (selection == 6){
        for(unsigned int i = 0; i < grades.size(); i++){
            cout << ": " <<grades[i]->getScore() << "  Grade: " << 
            grades[i]->getLetterGrade() << endl;
        }
    } else if (selection == 7){
        continue;
    }
    
    }
    
    return 0;
}
