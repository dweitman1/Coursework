#include <iostream>
#include <cstdlib>
#include "Complex.h"
/*
Author: Daniel Weitman
Created: 09/22/18
Last Updated: 09/23/18
Description: Implementation for complex functions
*/

using namespace std;

Complex :: Complex(){
    realPart = 0;
    imagPart = 0;
}
Complex :: Complex(double a, double b){
    realPart = a;
    imagPart = b;
}
Complex :: Complex(double a){
    realPart = a;
    imagPart = 0;
}
Complex :: ~Complex(){
    
}
void Complex :: setReal(double a){
    realPart = a;

}
void Complex :: setImag(double b){
    imagPart = b;
}
void Complex :: set(double a, double b){
    realPart = a;
    imagPart = b;
}
double Complex :: getReal(){
    return realPart;
}
double Complex :: getImag(){
    return imagPart;
}
//ADDITION OVERLOADS
Complex Complex :: operator +(const Complex &y){
    
    Complex temp;
    
    temp.setReal(realPart + y.realPart);
    temp.setImag(imagPart + y.imagPart);
    return temp;    
}
Complex Complex :: operator +(double x){
    
    Complex temp;
    
    temp.setReal(realPart + x);
    temp.setImag(imagPart);
    return temp;
}
Complex operator +(double x, const Complex &y){
    
    Complex temp;
    
    temp.setReal(y.realPart + x);
    temp.setImag(y.imagPart);
    return temp;
}
//SUBTRACTION OVERLOADS
Complex Complex :: operator -(const Complex &y){
    
    Complex temp;
    
    temp.setReal(realPart - y.realPart);
    temp.setImag(imagPart - y.imagPart);
    return temp;    
}
Complex Complex :: operator -(double x){
    
    Complex temp;
    
    temp.setReal(realPart - x);
    temp.setImag(imagPart);
    return temp;
}
Complex operator -(double x, const Complex &y){
    
    Complex temp;
    
    temp.setReal(x - y.realPart);
    temp.setImag(-1 * y.imagPart);
    return temp;
}
//MULTIPLICATION OVERLOADS
Complex Complex :: operator *(const Complex &y){
    
    Complex temp;
    
    temp.setReal((realPart * y.realPart) - (imagPart * y.imagPart));
    temp.setImag((imagPart * y.realPart) + (realPart * y.imagPart));
    return temp;    
}
Complex Complex :: operator *(double x){
    
    Complex temp;
    
    temp.setReal(x * realPart);
    temp.setImag(x * imagPart);
    return temp;
}
Complex operator *(double x, const Complex &y){
    
    Complex temp;
    
    temp.setReal(x * y.realPart);
    temp.setImag(x * y.imagPart);
    return temp;
}
//DIVISION OVERLOADS
Complex Complex :: operator /(const Complex &y){
    
    Complex temp;
    
    temp.setReal(((realPart)*(y.realPart)+(imagPart)*(y.imagPart))/((y.realPart)*(y.realPart)+(y.imagPart)*(y.imagPart)));
    temp.setImag(((imagPart)*(y.realPart)-(realPart)*(y.imagPart))/((y.realPart)*(y.realPart)+(y.imagPart)*(y.imagPart)));
    return temp;    
}
Complex Complex :: operator /(double x){
    
    Complex temp;
    
    temp.setReal(realPart / x);
    temp.setImag(imagPart / x);
    return temp;
}
Complex operator /(double x, const Complex &y){
    
    Complex temp;
    
    temp.setReal(((4)*(y.realPart))/((y.realPart)*(y.realPart)+(y.imagPart)*(y.imagPart)));
    temp.setImag(((4)*(y.imagPart))/((y.realPart)*(y.realPart)+(y.imagPart)*(y.imagPart)));
    return temp;
    return temp;
}
//INCREMENTER-DECREMENTER OVERLOADS
Complex Complex :: operator +=(Complex &y){
    realPart = realPart + y.realPart;
    imagPart = imagPart + y.imagPart;
    return *this;
}
Complex Complex :: operator -=(Complex &y){
    realPart = realPart - y.realPart;
    imagPart = imagPart - y.imagPart;
    return *this;
}
//EXPONENT OVERLOAD
Complex Complex :: operator ^(int e){
    
    Complex temp;
    
    for(int i = 0; i < e; i++){
        temp = temp * (*this);
    }
    return temp;
}
//EQUIVALENCE OVERLOADS
bool Complex :: operator ==(Complex &y){
    if(realPart == y.realPart && imagPart == y.imagPart){
        return true;
    } else {
        return false;
    }
}
bool Complex :: operator !=(Complex &y){
    if(realPart == y.realPart && imagPart == y.imagPart){
        return false;
    } else {
        return true;
    }
}
//ASSIGNMENT OVERLOAD
Complex Complex :: operator =(const Complex &y){
    realPart = y.realPart;
    imagPart = y.imagPart;
    return *this;
}
 //Functions
double Complex :: mod(){
    
    return sqrt((realPart * realPart) + (imagPart * imagPart));
}
//STREAM OVERLOADS
ostream &operator << (ostream &strm, const Complex &com){
    if(com.imagPart > 0 && com.realPart != 0){
        strm << com.realPart << " + " << com.imagPart << "i";
    } else if (com.imagPart < 0){
        strm << com.realPart << " - " << -1 * com.imagPart << "i";
    } else if(com.imagPart == 0) {
        strm << com.realPart;
    } else {
        strm << com.imagPart << "i";
    } 
    return strm;
}
istream &operator >> (istream &strm, Complex &com){
    strm >> com.realPart;
    strm >> com.imagPart;
    return strm;
}
