#include <iostream>
#include <vector>
/* Author: Daniel Weitman
 * Description: program that finds and displays the permutation of an 
 * ordered integer list with user defined size.
 * Creation Date: 11/07/18
 * Last Update: 11/07/18
 */
using namespace std;

void displayVec(vector<int> vec){
    for(unsigned int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void permute(vector<int> permList, int index){
    
    int temp;
    
    if(index == permList.size() - 1){
        displayVec(permList);//Display one permute
    } else {
        
       for(int i = index; i <= permList.size() - 1; i++){
            //Swap for first half of permute of 2
            temp = permList[index];
            permList[index] = permList[i];
            permList[i] = temp;
            
            //Recursive to find more ALL permutes
            permute(permList, index + 1);
            
            //Swap for second half of permute of 2
            temp = permList[index];
            permList[index] = permList[i];
            permList[i] = temp;
       }
       
    }
}

int main(){
    
    int size;
    cout << "Enter the size of permutation list: ";
    cin >> size;
    
    vector<int> list;
    
    //Fills vector with list between 1-size.
    for(int i = 1; i <= size; i++){
        list.push_back(i);
        
    }
    
    permute(list, 0);

    return 0;
}
