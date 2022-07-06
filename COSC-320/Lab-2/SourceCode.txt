/* Author: Daniel Weitman
 * Course: COSC-320
 * Instructor: Anderson
 * Due: 2/14/19
 * Description: Program that allows the user to test sorting algorithm
 * efficiency/time complexity on different sized arrays. Quick and Merge. 
 * 
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

template <class T>
void quickSort(T *arr, int);
template <class T>
void quickSort(T *arr, int, int);
template <class T>
int partition(T *arr, int, int);

template <class T>
void mergeSort(T *arr, int);
template <class T>
void mergeSort(T *arr, T *temp, int, int, int&);
template <class T>
void merge(T *arr, T *temp, int, int, int, int&);

template <class T>
void quickTime(T *arr, int);
template <class T>
void mergeTime(T *arr, int);

template <class T>
T* dupArr(T *arr1, int);
template <class T>
void printArr(T *arr, int);
template <class T>
void swap(T *, T *);

template <class T>
void popRand1(T *arr, int);
template <class T>
void popRand2(T *arr, int);
template <class T>
void popAscend(T *arr, int);
template <class T>
void popDescend(T *arr, int);
template <class T>
bool isSorted(T *arr, int);

void run();

int main(){
    
    srand(time(0));//Seed time to current for 'random' populates each run
    
    int flag = 1;//Flag for program repeats.
    
    //Loop to run tests as long as users wants
    while(flag == 1){
        //Calls function for running main section of program
        run();
        cout << "Run again? \n(1) Yes \n(2) No" << endl;
        cin >> flag;
        cout << endl;
    } 
    
    return 0;  
}

/* Description: calls quick sort algorithm with correct parameters
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void quickSort(T *arr, int size){
    quickSort(arr, 0, size - 1);
}

/* Description: calls quick sort algorithm on array type T
 * Parameters: T *arr, int start, int end
 * Return Type: void
 */
template <class T>
void quickSort(T *arr, int start, int end){
    int pivot;

    if(start < end) {
        pivot = partition(arr, start, end); 
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

/* Description: Function to do work in quick sort algorithm
 * Parameters: T *arr, int start, int end
 * Return Type: int
 */
template <class T>
int partition(T *arr, int start, int end){
  int pivot = arr[start];
  int loc = start;
  
  for(int i = start + 1; i <= end; i++){
    if(arr[i] <= pivot){
        loc++;
        swap(arr[loc], arr[i]); 
    }
  }
  swap(arr[loc], arr[start]);
  
  return loc;
}

/* Description: calls merge sort algorithm with correct parameters
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void mergeSort(T *arr, int size){
    T temp[size];
    int comp = 0;
    mergeSort(arr, temp, 0, size -1, comp);
    cout << "Merge sort used " << comp << " comparisons to sort the array." << endl;
}

/* Description: calls quick sort algorithm on array type T
 * Parameters: T *arr, T *temp, int start, int end, int comp
 * Return Type: void
 */
template <class T>
void mergeSort(T *arr, T *temp, int start, int end, int &comp){
    if(start < end){
        comp++;
        int mid = (start + end) / 2;
        mergeSort(arr, temp, start, mid, comp);
        mergeSort(arr, temp, mid + 1, end, comp);
        merge(arr, temp, start, mid + 1, end, comp);
    }
}

/* Description: merges two arrays based on values contained
 * Parameters: T *arr, T *temp, int start1, int start2, int end, int comp
 * Return Type: void
 */
template <class T>
void merge(T *arr, T *temp, int start1, int start2, int end, int &comp){
    int i = start1;
    int a = start1;
    int b = start2;
    
    while(a < start2 && b <= end){
        comp += 2;
        if(arr[a] < arr[b]){
            comp++;
            temp[i++] = arr[a++];
        } else {
            temp[i++] = arr[b++];
        }
    }
    
    while(a < start2){
        comp++;
        temp[i++] = arr[a++];
    }
    
    while(b <= end){
        comp++;
        temp[i++] = arr[b++];
    }
    
    for(int i = start1; i <= end; i++){
        comp++;
        arr[i] = temp[i];
    }
    
        
}

/* Description: Calls quickSort and times it
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void quickTime(T *arr, int size){
    cout << "|Quick Sort|" << endl;
    auto start = std::chrono::system_clock::now();
    quickSort(arr, size); 
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished at " << std::ctime(&end_time)
    << "elapsed time: " << elapsed_seconds.count() << "s\n";
    cout << "Sorted: ";
    if(isSorted(arr, size)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << endl;
}

/* Description: Calls quickSort and times it
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void mergeTime(T *arr, int size){
    cout << "|Merge Sort|" << endl;
    auto start = std::chrono::system_clock::now();
    mergeSort(arr, size); 
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished at " << std::ctime(&end_time)
    << "elapsed time: " << elapsed_seconds.count() << "s\n";
    cout << "Sorted: ";
    if(isSorted(arr, size)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << endl;
}
/* Description: Copies array and makes a duplicate
 * Parameters: T *arr, int size
 * Return Type: T* array
 */
template <class T>
T* dupArr(T *arr, int size){
    T *temp = new T[size];
    for(int i = 0; i < size; i ++){
        temp[i] = arr[i];
    }
    
    return temp;
}

/* Description: Prints an array
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void printArr(T *arr, int size){
    for(int i = 0; i < size; i++){
        if(i % 25 == 0)
            cout << endl;
        
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Description: Swaps two elements of type T
 * Parameters: T *a, T *b
 * Return Type: void
 */
template <class T>
void swap(T *a, T *b){
  T *temp;
  temp = a;
  a = b;
  b = temp; 
}
/* Description: Populates an array randomly between 1-100
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void popRand1(T *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = (rand() % 100) + 1;
    }
}

/* Description: Populates an array randomly between 1-3
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void popRand2(T *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = (rand() % 3) + 1;
    }
}

/* Description: Populates an array in ascending order
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void popAscend(T *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = i + 1;
    }
}

/* Description: Populates an array in descending order
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void popDescend(T *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = size - i;
    }
}

/* Description: Checks to see if an array is sorted in ascending order
 * Parameters: T *arr, int size
 * Return Type: bool sorted?
 */
template <class T>
bool isSorted(T *arr, int size){
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i + 1]){
            return false;
        }
    }
    return true;
}

/* Description: Asks user for input about what arrays
 * they want to test and calls the corresponding functions
 * Parameters: none
 * Return Type: void
 */
void run(){
    
    int n;
    cout << "Enter size of testing array: ";
    cin >> n;
    
    choice:int choice;
    cout << endl;
    cout << "Enter how you would like to populate the array..." << endl;
    cout << "(1) Random {1-100} \n(2) Random {1-3} \n(3) Ascending {Start: 1, Index: 1, End: n} \n(4) Descending {Start: n, Index: 1, End: 1}" << endl;
    
    cout << "(1-4): ";
    cin >> choice;
    cout << endl << endl;
    
    int *list1 = new int[n];//Create first copy of testing array
    
    //Populates array based on user specification
    switch(choice){
        case 1:
            popRand1(list1, n);
            //printArr(list1, n);
            break;
        case 2:
            popRand2(list1, n);
            //printArr(list1, n);
            break;
        case 3:
            popAscend(list1, n);
            //printArr(list1, n);
            break;
        case 4:
            popDescend(list1, n);
            //printArr(list1, n);
            break;
        //If they enter choice out of range of options given
        default:
            delete [] list1;
            goto choice;
    }
    //popRand1(list1, n);
    int *list2 = dupArr(list1, n);//Creates array for mergeSort
    
    //cout << "Random order\nSize: 100,000\n" << endl;
    
    quickTime(list1, n);//Sorts and times list1
    mergeTime(list2, n);//Sorts and times list2
    
   //Deletes dynamic arrays from memory to prevent memory leaks
    delete [] list1;
    delete [] list2;
}


