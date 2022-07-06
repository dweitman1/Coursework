#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <math.h>
/*
Author: Daniel Weitman
Created: 09/22/18
Last Updated: 09/23/18
Description: Header file for complex class
*/

using namespace std;

class Complex{
    
    private:
        double realPart;
        double imagPart;
        
    public:
        Complex();//Default constructor
        Complex(double, double);//Constructor real & imag Parts
        Complex(double);//Constructor real Part
        ~Complex();//Destructos
        void setReal(double);//Set real Part
        void setImag(double);//Set imag Part
        void set(double a, double b);//Set real & imag Parts
        double getReal();//Access real Part
        double getImag();//Access imag Part
        
        //ADDITION OVERLOADS
        Complex operator +(const Complex &);//obj1 + obj2
        Complex operator +(double);//obj + double
        friend Complex operator +(double, const Complex &);//double +obj
        
        //SUBTRACTION OVERLOADS
        Complex operator -(const Complex &);//obj1 - obj2
        Complex operator -(double);//obj - double
        friend Complex operator -(double, const Complex &);//double - obj
        
        //MULTIPLICATION OVERLOADS
        Complex operator *(const Complex &);//obj1 * obj2
        Complex operator *(double);//obj * double
        friend Complex operator *(double, const Complex &);//double * obj
        //DIVISION OVERLOADS
        Complex operator /(const Complex &);//obj1 / obj2
        Complex operator /(double);//obj / double
        friend Complex operator /(double, const Complex &);//double / obj
        
        //INCREMENTER-DECREMENTER OVERLOADS
        Complex operator +=(Complex &);//obj1 = obj1 + obj2
        Complex operator -=(Complex &);//obj1 = obj1 + obj2
        
        //EXPONENT OVERLOAD
        Complex operator ^(int);
        
        //EQUIVALENCE OVERLOADS
        bool operator ==(Complex &);//Is obj1 == obj2
        bool operator !=(Complex &);//Is obj1 != obj2
        
        //ASSIGNMENT OVERLOAD
        Complex operator =(Complex &);//obj = obj
        
        //Functions
        double mod();
        
        //STREAM OVERLOADS
        friend ostream &operator << (ostream &, const Complex &);//cout << obj
        friend istream &operator >> (istream &, Complex &);//cin >> obj
};

#endif
