/* Author: Daniel Weitman
 * Instructor: Lu
 * Date: 9/18/19
 * 
 */

#include "d_tnode.h"
#include "d_tnode1.h"

template <typename T>
void countInterior (tnode<T> *t, int& count)
{
   if (t != NULL)
   {
      // check if t is aninterior node (one child).
      // if so, increment count
      if (t->left != NULL && t->right == NULL){
        count++;
         
      }
      else if (t->left == NULL && t->right != NULL){
        count++;
        
      }

		countInterior(t->left, count);		// descend left
		countInterior(t->right, count);	// descend right
   }
}
