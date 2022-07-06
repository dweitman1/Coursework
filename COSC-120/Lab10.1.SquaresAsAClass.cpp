//Daniel Weitman
//COSC-120
//4-30-18

//This program declares the Square class and uses member functions to find
//the perimeter and area of the square

#include<iostream>

using namespace std;

class Square {
private:
	float side;

public:
	void setSide(float length);
	float findArea();
	float findPerimeter();
	Square();
	Square(float length);
	~Square();


};

int main() {

	Square box;
	float size;
	Square box1(9);


	cout << "Enter length of square: ";
	cin >> size;
	cout << endl;

	box.setSide(size);

	cout << "Area of box: " << box.findArea() << endl;
	cout << "Perimeter of box: " << box.findPerimeter() << endl;
	cout << "Area of box1: " << box1.findArea() << endl;
	cout << "Perimeter of box1: " << box1.findPerimeter() << endl;
	return 0;

}

void Square::setSide(float length) {
	side = length;
}

float Square::findArea() {
	return side * side;
}

float Square::findPerimeter(){
	return side * 4;
}

Square::Square() {
	side = 1;
}
Square::Square(float length) {
	side = length;
}
Square::~Square() {
	
}