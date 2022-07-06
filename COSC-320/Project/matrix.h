#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>

using namespace std;

class matrix{
    
private:
    int** mat;
    int rows;
    int columns;
    int elements;
    
public: 
    matrix();
    matrix(int n);
    matrix(int r, int c);
    matrix(int r, int c, int e);
    matrix(const matrix& obj);
    ~matrix();
    
    void populateMI();
    void populateME(int e);
    void populateMR(int lower, int upper);
    void setDim(int r, int c);
    void setElement(int e, int r, int c);
    int getElement(int r, int c);
    
    friend ostream& operator <<(ostream&, const matrix&);
    
    matrix operator =(const matrix& obj);
    matrix operator +(matrix& obj);
    matrix operator -(matrix& obj);
    matrix operator *(double s);//obj * s
    matrix operator *(const matrix &obj);//obj * obj
    
    
};

#endif
