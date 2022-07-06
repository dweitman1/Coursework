#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "int.h"
using namespace std;

/*
    Templated binary search tree.
    Author: Maliak Green Dan Weitman
    Created: 11/19/2018
    Updated: 10/3/2019
*/

template <class T>
class BinaryTree
{
  private:

    class TreeNode
    {
      public:
        T value;           // Node value
        TreeNode *left;    // Pointer to left child node
        TreeNode *right;   // Pointer to right child node

        // Constructor
        TreeNode(T nodeValue)
        {
            value = nodeValue;
            left = nullptr;
            right = nullptr;
        }
    };

    TreeNode *root;       // Pointer to the root node

    // Private member functions
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
    void PrintTree(TreeNode *t, int Indent, int Level);
    void loadInOrderRec(TreeNode *nodePtr, T A[], int &pos);
    

  public:
    // Constructor
    BinaryTree()
    {
        root = nullptr;
    }

    // Destructor
    ~BinaryTree()
    {
        destroySubTree(root);
    }

    void displayInOrder() const
    {
        displayInOrder(root);
    }

    void displayPreOrder() const
    {
        displayPreOrder(root);
    }

    void displayPostOrder() const
    {
        displayPostOrder(root);
    }

    void PrintTree(int Indent = 10)
    {
        PrintTree(root, Indent, 0);
    }

    void clear()
    {
        destroySubTree(root);
		root = nullptr;
    }

    // Binary tree operations
    void insertNode(T);
    bool searchNode(T);
    void remove(T);
    void loadInOrder(T A[]);
};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr){
        nodePtr = newNode;                  // Insert the node.
    } else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);     // Search the left branch
    else
        insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************
template <class T>
void BinaryTree<T>::insertNode(T item)
{
    TreeNode *newNode = new TreeNode(item);
    insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
template <class T>
bool BinaryTree<T>::searchNode(T item)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == item){
            nodePtr->value.incCount();
            return true;
        }
        else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************
template <class T>
void BinaryTree<T>::remove(T item)
{
    deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
    if (item < nodePtr->value)
        deleteNode(item, nodePtr->left);
    else if (item > nodePtr->value)
        deleteNode(item, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    // Define a temporary pointer to use in reattaching
    // the left subtree. while
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;   // Reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;  // Reattach the right child
        delete tempNodePtr;
    }
    // If the node has two children.
    else
    {
        // Move one node the right.
        tempNodePtr = nodePtr->right; 
        // Go to the end left node.
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    { cout << nodePtr->value << endl;
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

//********************************************************************
// Subtree printer recursive function for sideways printing the tree *
//********************************************************************

template <class T>
void BinaryTree<T>::PrintTree(TreeNode *t, int Indent, int Level)
{
    if (t)
    {
        PrintTree(t->right, Indent, Level + 1);

        for (int i = 0; i < Indent * Level; i++)
            cout << " ";

        cout << t->value << "\n";
        PrintTree(t->left, Indent, Level + 1);
    }
}
//****************************************************************
// The loadInOrderRec function takes in an array and sorts it with 
//in order member function recursively.
//****************************************************************

template <class T>
void BinaryTree<T>::loadInOrderRec(TreeNode *nodePtr, T A[], int &pos){
 
    if (nodePtr)
    {
	
        loadInOrderRec(nodePtr->left, A, pos);
	A[pos] = nodePtr->value;
	 pos++;
        loadInOrderRec(nodePtr->right, A, pos);
 
    }
}
//****************************************************************
// The loadInOrder function publicly calls private function.
//****************************************************************


template <class T>
void BinaryTree<T>::loadInOrder(T A[]){
  int pos = 0;
  
    loadInOrderRec(root, A, pos); 
}

#endif
