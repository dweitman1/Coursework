// The program solves the 8-Queens problem for all possible solutions.
// Backtracking function queens() determines if there is a solution.
// if there is a solution, then it prints out the row numbers of the 
// solution and then counts the solution to total the solutions
// This is an update from the textbook of Ford and Topp.

// Edited: Daniel Weitman
// Last update: 11/7/18

#include <iostream>
#include <vector>

using namespace std;

// Can a queen at (row,col) be attacked by any of the
// non-attacking queens in columns 0 to col-1 ?
bool safeLocation(int row, int col, const vector<int>& queenList)
{
    for (int qCol = 0; qCol < col; qCol++)
    {
        int qRow = queenList[qCol];
        if (qRow == row)
            return false;
        else if (qCol == col)
            return false;
        else if (qCol - qRow == col - row || qCol + qRow == col + row)
            return false;
    }
    return true;
}

// Place a queen in columns col through 7
bool placeQueens(vector<int>& queenList, int col, int &numSol)
{
    int row;
    bool foundLocation = false;

    if (col == 8){	// stopping condition
        numSol++; //Solution incrementation
    for (unsigned int i = 0; i < queenList.size(); i++)
			cout << queenList[i] << " ";

		cout << endl;
        
    } else {
        row = 0;

        while (row < 8 && !foundLocation)
        {
            if (safeLocation(row, col, queenList))
            {
                queenList[col] = row;
                foundLocation = placeQueens(queenList, col + 1, numSol);
                if (!foundLocation)
                    row++;
            }
            else
                row++;
        }
    }

    // pass success or failure back to previous col
    
    return foundLocation;
}

int main()
{
    //int row;
    int numSol = 0;
    vector<int> queenList(8);

    cout << "Enter row for queen in column 0: ";
    //cin >> row;
    cout << endl;

	queenList[0] = 0;

    if (!placeQueens(queenList, 0, numSol))
        cout << "There are " << numSol << " solutions." << endl;
    
    return 0;
}
