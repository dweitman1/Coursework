#ifndef MATRIX_H
#define MATRIX_H

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
    
    void printM();
    void populateMI();
    void populateME(int e);
    void populateMR(int l, int u);
    void setDim(int r, int c);
    void setElement(int e, int r, int c);
    int getElement(int, int);
    
    matrix operator =(const matrix& obj);
    matrix operator +(matrix& obj);
    matrix operator -(matrix& obj);
    matrix operator *(const matrix &obj);//obj * obj
    matrix operator *(double s);//obj * s
    
};

#endif
