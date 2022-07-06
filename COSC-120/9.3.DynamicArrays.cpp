//This program demonstrates the use of dynamic arrays

//Daniel Weitman
//COSC-120
//4-2-18

#include<iostream>
#include<iomanip>
using namespace std;

const int MAXNAME = 10;

int main() {

	float *monthSales = nullptr;	//a pointer used to point to an array
									//holding monthly sales
	float total = 0;				//total of all sales
	float average;					//average of monthly sales
	int numOfSales;					//number of sales to be processed
	int count;						//loop counter

	cout << fixed << showpoint << setprecision(2);

	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;

	monthSales = new float(numOfSales);

	cout << "Enter the sales below\n";

	for (count = 0; count < numOfSales; count++) {

		cout << "Sales for Month number "
			<< count + 1
			<< ": ";
		cin >> monthSales[count];
	}
	for (count = 0; count < numOfSales; count++) {
		total = total + monthSales[count];
	}

	average = total / count;

	cout << "Average monthly sales is $" << average << endl;

	delete [] monthSales;

	return 0;
}