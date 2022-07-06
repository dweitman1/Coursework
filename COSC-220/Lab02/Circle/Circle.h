#ifndef CIRCLE_H
#define CIRCLE_H
/*Author: Daniel Weitman
 * Creation Date: 9/14/18
 * Last Update: 9/17/18
 * Description: Class structure for a circle with private member variable and member
 * function declarations
 */
using namespace std;

class Circle{

    private:
        double radius;//Radius of this Circle object
        const double PI = 3.141592653589793;//Constant for computing Circle attributes
        int x;//X coordinate of this Circle object's center
        int y;//Y coordinate of this Circle object's center
    public:
        Circle();
        Circle(double);
        Circle(double, int, int);
        void setRadius(double);
        void setCenter(int, int);
        int getCenterX();
        int getCenterY();
        double getRadius();
        double getArea();
        double getDiameter();
        double getCircumference();
        bool collide(Circle);
};
#endif
