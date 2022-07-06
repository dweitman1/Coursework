#include <iostream>
#include <cmath>
#include "Circle.h"
/*Author: Daniel Weitman
 * Creation Date: 9/14/18
 * Last Update: 9/17/18
 * Description: Implementation of member functions for class Circle
 */
using namespace std;
//Default constructor
Circle :: Circle(){
    radius = 0;
}
//Constructor given only radius parameter
Circle :: Circle(double r) {
    radius = r;
}
//Constructor given radius and center point parameters
Circle :: Circle(double r, int a, int b) {
    radius = r;
    x = a;
    y = b;
}
//Setter to alter the radius of a Circle object and ensure it is of a non-negative value
void Circle :: setRadius(double r) {
    if(r > 0){
        radius = r;
    } else {
        radius = 0;
    } 
}    
//Setter to alter the center of a Circle object
void Circle :: setCenter(int a, int b){
    x = a;
    y = b;
}
//Getter to access the X coordinate of a Circle object
int Circle :: getCenterX(){
    return x;
}
//Getter to access the Y coordinate of a Circle object
int Circle :: getCenterY(){
    return y;
}
//Getter to access the Radius of a Circle object
double Circle :: getRadius(){
    return radius;        
}
//Function design to calculate and return the area of a Circle object
double Circle :: getArea(){
    return radius * radius * PI;
}
//Function design to calculate and return the diameter of a Circle object
double Circle :: getDiameter(){
    return radius * 2;
}
//Function design to calculate and return the circumference of a Circle object
double Circle :: getCircumference(){
    return radius * 2 * PI;
}
//Function design to calculate the distance between two and return whether the Circle 
//objects overlap
bool Circle :: collide(Circle a){
    double dis;
    double sum;
    dis = pow((x - a.getCenterX()), 2);
    dis = dis + pow((y - a.getCenterY()), 2);
    dis = sqrt(dis);
    
    sum = radius + a.getRadius();
    
    if (dis <= sum){
        return true;
    } else {
        return false;
    }
}
