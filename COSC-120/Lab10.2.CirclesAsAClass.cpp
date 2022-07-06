//Daniel Weitman
//COSC-120
//4-30-18

//This program declares a class for a circle that will have
//member functions that set the center, find the area, find
//the circumference and display these attributes.

#include<iostream>

using namespace std;

class Circles {
private:
	float radius;
	int centerx;
	int centery;

public:
	void setCenter(int x, int y);
	double findArea();
	double findCircumference();
	void printCircleStats();
	Circles();
	Circles(float r, int x, int y);
	Circles(float r);
	Circles(int x, int y);
	

};

const double PI = 3.14;

int main() {
	Circles sphere(8,9,10);
	Circles sphere1(2);
	Circles sphere2();

	sphere.printCircleStats();
	cout << "The area of the circle is " << sphere.findArea() << endl;
	cout << "The circumference of the circle is " << sphere.findCircumference() << endl;

	sphere1.printCircleStats();
	cout << "The area of the circle is " << sphere1.findArea() << endl;
	cout << "The circumference of the circle is " << sphere1.findCircumference() << endl;

	sphere2.printCircleStats();
	cout << "The area of the circle is " << sphere2.findArea() << endl;
	cout << "The circumference of the circle is " << sphere2.findCircumference() << endl;


	return 0;
}

Circles::Circles() {
	radius = 1;
	centerx = 0;
	centery = 0;
}
Circles::Circles(float r, int x, int y) {
	radius = r;
	centerx = x;
	centery = y;
}
Circles::Circles(float r) {
	radius = r;
}
Circles::Circles(int x, int y) {
	centerx = x;
	centery = y;
}
double Circles::findArea() {
	return PI * radius * radius;
}
double Circles::findCircumference() {
	return 2 * radius * PI;
}
void Circles::printCircleStats() {
	cout << "The radius of the circle is " << radius << endl;
	cout << "The center of the circle is (" << centerx << ", " << centery << ")" << endl;
}
