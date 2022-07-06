// This program demonstrates the use of pointer variables
// It finds the area of a rectangle given length and width
//It prints the length and width in ascending order

//Daniel Weitman
//COSC-120
//4-2-18

#include<iostream>

using namespace std;

int main() {

	int length; //Holds length
	int width; //Holds width
	int area; //Holds area

	int *lengthPtr = nullptr; //int pointer which will be set to length
	int *widthPtr = nullptr; //int pointer which will be set to width

	cout << "Please input the length of the rectangle" << endl;
	cin >> length;
	cout << "Please input the width of the rectangle" << endl;
	cin >> width;

	lengthPtr = &length;
	widthPtr = &width;

	area = (*lengthPtr) * (*widthPtr);
	cout << "The area is: " << area << endl;

	if (*lengthPtr > *widthPtr) {
		cout << "The length is greater than the width" << endl;
	} else if (*lengthPtr < *widthPtr) {
		cout << "The width is greater than the length" << endl;
	} else {
		cout << "the width and length are the same" << endl;
	}



	return 0;
}