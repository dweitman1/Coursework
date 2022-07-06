#include <iostream>
using namespace std;

/*
 * Author: Maliak Green Dan Weitman
 * Description: This program will find the number of possible ways to select k objects
 * from n objects.
 * Creation Date: 11/05/18
 * Last Update: 11/05/18
 */


/*
 * Description: Function to recurse to obtain value of n given n and k.
 * Parameters: Intger n; Integer k.
 * Return: Integer.
 * Notes: None.
 */

int calcN(int n, int k)
{
 
  // Base cases.
  if(n == 0 || k == 0)
    return 1;
  
  else if( n == k)
    return 1;
  
  else if(n < 0 || k < 0)
    return 0;
  
  return calcN(n-1, k) + calcN(n-1, k-1);
}



int main()
{
  int n, k;

  cout << "Enter n and k (integer) with a space between them: ";
  cin >> n >> k;
  int result = calcN(n, k);
  cout << "n is equal to: " << result << endl;
  
 return 0; 
}