/* Author: Daniel Weitman
 * Course: COSC-320
 * Instructor: Anderson
 * Due: 2/7/19
 * Description: Program that allows the user to test sorting algorithm
 * efficiency/time complexity on different sized arrays. Bubble, 
 * insertion, and selection.
 * 
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

template <class T>
void bubbleSort(T *arr, int);
template <class T>
void insertionSort(T *arr, int);
template <class T>
void selectionSort(T *arr, int);

template <class T>
void bubbleTime(T *arr, int);
template <class T>
void insertionTime(T *arr, int);
template <class T>
void selectionTime(T *arr, int);

template <class T>
T* dupArr(T *arr1, int);
template <class T>
void printArr(T *arr, int);

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

/* Description: Runs bubble sort algorithm on array of size, size
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void bubbleSort(T *arr, int size){
    int swaps = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    cout << "Num of swaps: " << swaps << endl;
}

/* Description: Runs insertion sort algorithm on array of size, size
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void insertionSort(T *arr, int size){
    int swaps = 0;
    for (int i = 0; i < size; i++)
    {
        int j = 0;
        T val = arr[i];
        for (j = i; j > 0 && arr[j - 1] > val; j--){
            arr[j] = arr[j - 1];
        }
        
        arr[j] = val;
        swaps++;
    }
    cout << "Num of swaps: " << swaps << endl;
}

/* Description: Runs selection sort algorithm on array of size, size
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void selectionSort(T *arr, int size){
    int min;
    int swaps = 0;
    
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i; j < size; j++)
            if (arr[j] < arr[min]){
                min = j;
            }
        T val = arr[i];
        arr[i] = arr[min];
        arr[min] = val;
        swaps++;
    }
    cout << "Num of swaps: " << swaps << endl;
}

/* Description: Calls bubbleSort and times it
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void bubbleTime(T *arr, int size){
    cout << "|Bubble Sort|" << endl;
    auto start = std::chrono::system_clock::now();
    bubbleSort(arr, size); 
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
/* Description: Calls insertionSort and times it
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void insertionTime(T *arr, int size){
    cout << "|Insertion Sort|" << endl;
    auto start = std::chrono::system_clock::now();
    insertionSort(arr, size); 
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

/* Description: Calls selectionSort and times it
 * Parameters: T *arr, int size
 * Return Type: void
 */
template <class T>
void selectionTime(T *arr, int size){
    cout << "|Selection Sort|" << endl;
    auto start = std::chrono::system_clock::now();
    selectionSort(arr, size);
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
    int *list2 = dupArr(list1, n);//Creates array for insertionSort
    int *list3 = dupArr(list2, n);//Creates array for selectionSort
    
    //cout << "Random order\nSize: 100,000\n" << endl;
    
    bubbleTime(list1, n);//Sorts and times list1
    insertionTime(list2, n);//Sorts and times list2
    selectionTime(list3, n);//Sorts and times list3
    
   //Deletes dynamic arrays from memory to prevent memory leaks
    delete [] list1;
    delete [] list2;
    delete [] list3;
}


