#include <iostream>
#include <string>
using namespace std;

/*
 * Author: Maliak Green Dan Weitman
 * Description: This program will check if a given string is a palindrome.
 * Creation Date: 11/05/18
 * Last Update: 11/05/18
 */


/*
 * Description: Function to recurse through the string and check for plaindrome.
 * Parameters: Constant string, integer start, integer end.
 * Return: Boolean.
 * Notes: None.
 */

bool isPal(const string &str, int start, int end)
{
  //Base Case.
  if(str.length() == 1)
  return true;
  
  if(str[start] == str[end] && end > start)
    return isPal(str, start + 1, end - 1);
  
  else if(str[start] == str[end] && end <= start ) // If the position is in the middle.
    return true;

  else
    return false;
  
  
  
}

int main()
{
  string phrase;
  cout << "Enter your phrase: ";
  cin >> phrase;
  
  int s = 0;
  int e = phrase.length() - 1;
  bool res = isPal(phrase, s, e);
  
  if(res)
    cout << phrase << " is a palindrome.";
  
  else
    cout << phrase << " is not a palindrome.";
  
  
  
  
 return 0; 
}