#include <omp.h>
#include <time.h>
#include <math.h>
#include "matrix.h"

using namespace std;

/* Description: Default constructor
 * Parameters: none
 * Return: n/a
 */
matrix::matrix(){
    rows = 2;
    columns = 2;
    elements = 4;
    
    mat = new int*[rows];
    
    for(int i = 0; i < rows; i++){
        mat[i]= new int[columns];
    }
    
    populateMI();
}

/* Description: Constructor for nxn matrix
 * Parameters: int n
 * Return: n/a
 */
matrix::matrix(int n){
    rows = n;
    columns = n;
    elements = n * n;
    
    if(rows < 0){
        cout << "Invalid rows... defaulting to 1" << endl;
        rows = 1;
    }
    if(columns < 0){
        cout << "Invalid columns... defaulting to 1" << endl;
        columns = 1;
    }
    
    mat = new int*[rows];
    
    for(int i = 0; i < rows; i++){
        mat[i]= new int[columns];
    }
    
    populateMI();
}

/* Description: Constructor for rxc matrix
 * Parameters: int r, int c
 * Return: n/a
 */
matrix::matrix(int r, int c){
    rows = r;
    columns = c;
    elements = r * c;
    
    if(rows < 0){
        cout << "Invalid rows... defaulting to 1" << endl;
        rows = 1;
    }
    if(columns < 0){
        cout << "Invalid columns... defaulting to 1" << endl;
        columns = 1;
    }
    
    mat = new int*[rows];
    
    for(int i = 0; i < rows; i++){
        mat[i]= new int[columns];
    }
    
    populateMI();
}

/* Description: Constructor for rxc matrix
 * Parameters: int r, int c, int e
 * Return: n/a
 */
matrix::matrix(int r, int c, int e){
    rows = r;
    columns = c;
    elements = r * c;
    
    if(r < 0){
        cout << "Invalid rows... defaulting to 1" << endl;
        rows = 1;
    }
    if(c < 0){
        cout << "Invalid columns... defaulting to 1" << endl;
        columns = 1;
    }
    
    mat = new int*[rows];
    
    for(int i = 0; i < rows; i++){
        mat[i]= new int[columns];
    }
    
    populateME(e);
}

/* Description: Copy constructor for matrix object
 * Parameters: const matrix &obj
 * Return: n/a
 */
matrix::matrix(const matrix &obj){
    rows = obj.rows;
    columns = obj.columns;
    elements = obj.elements;
    
    mat = new int*[rows];
    for(int i = 0; i < rows; i++){
        mat[i]= new int[columns];
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            mat[i][j] = obj.mat[i][j];
        }
    }
}

/* Description: Destructor for matrix object
 * Parameters: none
 * Return: n/a
 */
matrix::~matrix(){
    
    for(int i = 0; i < rows; i++){
        delete [] mat[i];
    }
    delete [] mat;
    
}

/* Description: Function to populate matrix with ID
 * Parameters: none
 * Return: void
 */
void matrix::populateMI(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(i != j){
                mat[i][j] = 0;
            } else {
                mat[i][j] = 1;
            }
        }
    }
}

/* Description: Function to populate matrix with e
 * Parameters: int e
 * Return: void
 */
void matrix::populateME(int e){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            mat[i][j] = e;
        }
    }
}

/* Description: Function to populate matrix with rand
 * Parameters: int l, int u
 * Return: void
 */
void matrix::populateMR(int lower, int upper){
    if(upper < lower){
        int t = lower;
        lower = upper;
        upper = t;
    }
    int range = (upper - lower) + 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            mat[i][j] = (rand() % range) + lower;
        }
    }
}

/* Description: Function to set new dimensions of a matrix
 * Parameters: int r, int c
 * Return: void
 */
void matrix::setDim(int r, int c){
    matrix a(r, c);
    *this = a;
    
}

/* Description: Function to set elements 
 * Parameters: int e, int r, int c
 * Return: void
 */  
void matrix::setElement(int e, int r, int c){
    if(r > rows || c > columns){
        cout << "Invalid dimensions!" << endl;
        return;
    }
    mat[r][c] = e;
}

/* Description: Function to get element of matrix
 * Parameters: int r, int c
 * Return: int
 */
int matrix::getElement(int r, int c){
    return mat[r][c];
}

/* Description: Overloaded insertion operator
 * Parameters: ostream obj, const matrix& obj
 * Return: matrix
 */
ostream& operator <<(ostream& out, const matrix& obj){
    for(int i = 0; i < obj.rows; i++){
        out << "|";
        for(int j = 0; j < obj.columns; j++){
            out << setw(4) << obj.mat[i][j] << " ";
        }
        out << "|" << endl;
    }
    return out;
}
    
/* Description: Overloaded assignment operator
 * Parameters: const matrix& obj
 * Return: matrix
 */
matrix matrix::operator =(const matrix &obj){
    
    for(int i = 0; i < rows; i++){
        delete [] mat[i];
    }
    delete [] mat;
    
    rows = obj.rows;
    columns = obj.columns;
    elements = obj.elements;
    
    mat = new int*[rows];
    for(int i = 0; i < rows; i++){
        mat[i]= new int[columns];
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            mat[i][j] = obj.mat[i][j];
        }
    }
    
    return *this;
}

/* Description: Overloaded + operator
 * Parameters: matrix& obj
 * Return: matrix
 */
matrix matrix::operator +(matrix &obj){
    if(rows != obj.rows || columns != obj.columns){
        cout << "Invalid addition dimensions...\nReturning 2x2 ID" << endl;
        matrix c;
        return c;
    }
    matrix c(rows, columns);
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            c.setElement((getElement(i, j) + obj.getElement(i, j)), i, j);
            
        }  
    }
    return c;
}

/* Description: Overloaded - operator
 * Parameters: matrix& obj
 * Return: matrix
 */
matrix matrix::operator -(matrix &obj){
    if(rows != obj.rows || columns != obj.columns){
        cout << "Invalid subtraction dimensions...\nReturning 2x2 ID" << endl;
        matrix c;
        return c;
    }
    matrix c(rows, columns);
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            c.setElement((getElement(i, j) - obj.getElement(i, j)), i, j);
            
        }  
    }
    return c;
}

/* Description: Overloaded * operator
 * Parameters: double s
 * Return: matrix
 */
matrix matrix::operator *(double s){
    matrix c(rows, columns);
    c = *this;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            c.mat[i][j]*=s;
            
        }
    }
    return c;
}

/* Description: Overloaded * operator
 * Parameters: const matrix& obj
 * Return: matrix
 */
matrix matrix::operator *(const matrix &obj){
    
    //Define product matrix and timing variables
    matrix product(rows, obj.columns);
    double start, fin;
    double time[4];
    
    //Start serial MM algorithm
    start = omp_get_wtime();
    for(int i = 0; i < product.rows; i++){
        for(int j = 0; j < product.columns; j++){
            product.setElement(0, i, j);
            for(int k = 0; k < columns; k++){
                product.setElement((product.mat[i][j]+=(mat[i][k]*obj.mat[k][j])), i, j); 
                    
            }
        }  
    }
    fin = omp_get_wtime();
    //Finish serial MM algorithm
    time[0] = fin - start;
    
    static bool flag = true;
    if(flag){
        cout << "|  n  |     S     |";
    }
    
    //return c;
    
    ///////////////////////////////////////
    
    
    
    int iterations = 4; 
    int nthreads;
    int chunk = 10;
    for(int i = 0; i < iterations; i++){
        nthreads = pow(2, i+1);
        if(flag){
            cout << setw(6) << nthreads << setw(6) << "|";
        }
        omp_set_num_threads(nthreads);
        product.populateMI();
        
        start = omp_get_wtime();
        #pragma omp parallel shared(product)//Share instance variables
        {
            #pragma omp for schedule (static, chunk)//Divide work of loop
                for(int i = 0; i < product.rows; i++){
                    for(int j = 0; j < product.columns; j++){
                        product.setElement(0, i, j);
                        for(int k = 0; k < columns; k++){
                            product.setElement
                            ((product.mat[i][j]+=(mat[i][k]*obj.mat[k][j])), i, j); 
                    
                        }
                    }  
                }//End of matrix multiplication
        
        }//Threads combine
    
    fin = omp_get_wtime();
    time[i+1] = fin - start;
    
    }//Matrix multiply w more threads
    
    if(flag){
        cout << endl;
    }
    cout << "|" << setw(5) << rows << "|";
    for(int i = 0; i < iterations + 1; i++){ 
        cout << setw(11) << fixed << setprecision(6) << time[i] << "|";
    }
    cout << endl;
    if(flag){
        flag = false;
    }
    return product;
    
    
}
