#include <iostream>
#include <cstdlib> 
#include "Circle.h"
/*Author: Daniel Weitman
 * Creation Date: 9/14/18
 * Last Update: 9/17/18
 * Description: Main for user entered circle objects and instructions for which member 
 * functions to run on which Circle objects
 */
using namespace std;

int main(){
    
    double rad;
    Circle circle1;
    
    cout << "Enter the radius for the user defined circle" << endl;
    cin >> rad;
    circle1.setRadius(rad);
    //Displays the attributes of the first user defined Circle
    cout << "Radius: " << circle1.getRadius() << endl;
    cout << "Area: " << circle1.getArea() << endl;
    cout << "Diameter: " << circle1.getDiameter() << endl;
    cout << "Circumference: " << circle1.getCircumference() << endl << endl;

    
    Circle circleArr[1000];
    //For loop test the above declared array of 1000 circle objects to see if they overlap
    for (int i = 0; i < 1000; i++){
       /* circleArr[i].setRadius(rand()%2+1);
        circleArr[i].setCenter(rand()%20+1, rand()%20+1);
        cout << "Circle " << i + 1 << endl;
        cout << "Radius: " << circleArr[i].getRadius() << endl;
        cout << "(" << circleArr[i].getCenterX() << "," << circleArr[i].getCenterY() << ")" << endl;*/
       
        if (circleArr[i-1].collide(circleArr[i]) && i < 999){
        cout <<"Circles "<< i + 1 << " and " << i + 2 << " collide"<< endl;
        } else if (i < 999) {
        cout <<"Circles "<< i + 1 << " and " << i + 2 << " do not collide"<< endl;
        }
    }
    return 0;
}
