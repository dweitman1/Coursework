#include "d_tnode.h"
#include "d_tnode1.h"

int maxVal(tnode<int> *t, int &max){
    if(t){
        if((t->nodeValue) > max){
            max = t->nodeValue;
        }
    
        maxVal(t->left, max);
        maxVal(t->right, max);
    }
}
