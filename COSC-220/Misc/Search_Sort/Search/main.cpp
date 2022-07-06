#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Quick Sort, needed for the binary search

template <class T>
void quickSort(T A[], int left, int right)
{
    int i = left;
    int j = right;
    int mid = (left + right) / 2;

    T pivot = A[mid];

    while (i <= j)
    {
        while (A[i] < pivot)
            i++;

        while (A[j] > pivot)
            j--;

        if (i <= j)
        {
            T tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(A, left, j);

    if (i < right)
        quickSort(A, i, right);
}

template <class T>
void quickSort(T A[], int size)
{
    quickSort(A, 0, size - 1);
}

///////////////////////////////////////////////////////////

//  Search Algorithms

template <class T>
int binarySearch(T A[], int left, int right, T target)
{
    if (right >= left)
    {
        int mid = (right + left) / 2;

        if (A[mid] == target)
            return mid;
        else if (A[mid] > target)
            return binarySearch(A, left, mid - 1, target);
        else
            return binarySearch(A, mid + 1, right, target);
    }

    return -1;
}

///////////////////////////////////////////////////////////

template <class T>
int linearSearch(T A[], int size, T target)
{
	for (int i = 0; i < size; i++)
        if (A[i] == target)
            return i;

    return -1;
}

///////////////////////////////////////////////////////////

//  Support functions

template <class T>
bool sorted(T A[], int size)
{
    for (int i = 0; i < size - 1; i++)
        if (A[i] > A[i + 1])
            return false;

    return true;
}

template <class T>
void print(T A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";

    cout << endl;
}

template <class T>
void outputSorted(T A[], int size)
{
    if (sorted(A, size))
        cout << "Sorted" << endl;
    else
        cout << "Not Sorted" << endl;
}

int main()
{
    int size = 0;
	int target = 0;
    cout << "Input Array Size: ";
    cin >> size;

    cout << "Input Target: ";
    cin >> target;

    int A[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++)
        A[i] = rand() % size;

	int pos = linearSearch(A, size, target);
	if (pos > -1)
		cout << A[pos] << " is in position " << pos << endl;
	else
		cout << target << " was not found." << pos << endl;

    quickSort(A, size);
	pos = binarySearch(A, 0, size - 1, target);
	if (pos > -1)
		cout << A[pos] << " is in position " << pos << endl;
	else
		cout << target << " was not found." << pos << endl;

    return 0;
}
