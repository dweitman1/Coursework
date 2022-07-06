/* Author: Daniel Weitman
 * Course: COSC-320
 * Instructor: Anderson
 * Due: 2/28/19
 * 
 */

#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;

/* Description: Displays every matrix in the list
 * Parameters: int size
 * Return: void
 */
void display(int size){
    cout << "----------\n| ";
    for(int i = 0; i < size; i++){
        cout << i + 1 << " ";
    }
    cout << "|\n----------" << endl;
}

int main(){
    
    srand(time(0));
    
    vector<matrix> list;
    int x;
    matrix add;
    
    do{
        cout << "====Menu====" << endl;
        cout << "(1) Create a new matrix" << endl;
        cout << "(2) Change an element of a matrix" << endl;
        cout << "(3) Display matrices" << endl;
        cout << "(4) Display a matrix" << endl;
        cout << "(5) Add two matrices" << endl;
        cout << "(6) Subtract two matrices" << endl;
        cout << "(7) Multiply two matrices" << endl;
        cout << "(8) Multiply a matrix by a scalar" << endl;
        cout << "(9) Exit" << endl;
        
        cout << "Choice: ";
        cin >> x;
        
        switch (x){
            case 1:
                int r, c;
                cout << "Enter rows: ";
                cin >> r;
                cout << "Enter columns: ";
                cin >> c;
                add.setDim(r, c);
                int pop;
                cout << "How would you like to populate?\n";
                cout << "(1) Identity Matrix\n";
                cout << "(2) All single element\n";
                cout << "(3) Random elements\n";
                cin >> pop;
                
                if(pop == 2){
                    int ele;
                    cout << "Enter an integer: ";
                    cin >> ele;
                    add.populateME(ele);
                } else if(pop == 3){
                    int low;
                    int high;
                    cout << "Enter lower bound: ";
                    cin >> low;
                    cout << "Enter upper bound: ";
                    cin >> high;
                    add.populateMR(low, high);
                    
                }
                
                list.push_back(add);
                
                break;
                
            case 2:
                if(list.size() <= 0){
                    break;
                }
                cout << "Choose a matrix\n";
                display(list.size());
                int m, e, ro, co;
                do{
                    cout << "Matrix: ";
                    cin >> m;
                } while (m > list.size() || m <= 0);
                
                cout << "Enter rows: ";
                cin >> ro;
                cout << "Enter columns: ";
                cin >> co;
                cout << "Enter element: ";
                cin >> e;
                
                list[m - 1].setElement(e, ro - 1, co - 1);
                
                break;
                
            case 3:
                display(list.size());
                if(list.size() <= 0){
                    cout << "No matrices created!" << endl;
                }
                
                break;
                
            case 4:
                if(list.size() <= 0){
                    break;
                }
                cout << "Choose a matrix\n";
                display(list.size());
                int ma;
                do{
                    cout << "Matrix: ";
                    cin >> ma;
                } while (ma > list.size() || ma <= 0);
                
                
                list[ma - 1].printM();
                
                break; 
                
            case 5:
                if(list.size() < 2){
                    cout << "Not enough matrices" << endl;
                    break;
                }
                cout << "Choose a matrix\n";
                display(list.size());
                int m1;
                int m2;
                
                do{
                    cout << "Matrix 1: ";
                    cin >> m1;
                } while (m1 > list.size() || m1 <= 0);
                
                do{
                    cout << "Matrix 2: ";
                    cin >> m2;
                } while (m2 > list.size() || m2 <= 0);
                
                add = list[m1 - 1] + list[m2 - 1];
                list.push_back(add);
                cout << "Created new matrix " << list.size() << endl << endl;
                //add.printM();
                
                break;
                
            case 6:
                
                if(list.size() < 2){
                    cout << "Not enough matrices" << endl;
                    break;
                }
                cout << "Choose a matrix\n";
                display(list.size());
                int m11;
                int m22;
                
                do{
                    cout << "Matrix 1: ";
                    cin >> m11;
                } while (m11 > list.size() || m11 <= 0);
                
                do{
                    cout << "Matrix 2: ";
                    cin >> m22;
                } while (m22 > list.size() || m22 <= 0);
                
                add = list[m11 - 1] - list[m22 - 1];
                list.push_back(add);
                cout << "Created new matrix " << list.size() << endl << endl;
                //add.printM();
                
                break;
                
            case 7:
                if(list.size() < 2){
                    cout << "Not enough matrices" << endl;
                    break;
                }
                cout << "Choose a matrix\n";
                display(list.size());
                int m111;
                int m222;
                
                do{
                    cout << "Matrix 1: ";
                    cin >> m111;
                } while (m111 > list.size() || m111 <= 0);
                
                do{
                    cout << "Matrix 2: ";
                    cin >> m222;
                } while (m222 > list.size() || m222 <= 0);
                
                add = list[m111 - 1] * list[m222 - 1];
                list.push_back(add);
                cout << "Created new matrix " << list.size() << endl << endl;
                //add.printM();
                
                break;
                
            case 8:
                
                if(list.size() < 1){
                    cout << "Not enough matrices" << endl;
                    break;
                }
                cout << "Choose a matrix\n";
                display(list.size());
                int m1111, scalar;
                
                do{
                    cout << "Matrix: ";
                    cin >> m1111;
                } while (m1111 > list.size() || m1111 <= 0);
                
                cout << "Scalar: ";
                cin >> scalar;
                
                add = list[m1111 - 1] * scalar;
                list.push_back(add);
                cout << "Created new matrix " << list.size() << endl << endl;
                //add.printM();
                
                break;
        }
        
    }while(x != 9);
    
    return 0;
}
