#ifndef FHSPLAYTREE_H
#define FHSPLAYTREE_H

#include <iostream>
#include "FHsearch_Tree.h"
using namespace std;


/*
Name: Dillon Pinto
Assignment 5

Description: This header file with implementation is a derived/sub class of
			 the base class "FHsearch_tree. Member functions in the derived
			 class have been either overriden or overloaded for the splay tree
			 imnplementation. The binary search tree class was used as a base 
			 class since a splay tree is a type of binary search tree and would
			 use its methods.
*/



/*

Header comment:
This class is a derived class from the FHsearch_tree base class that creates
a splay tree instead of a binary search tree. Methods/member functions have
been overriden or overloaded in the derived class so the splay tree can be inmplemented.


FHsplayTree() : FHsearch_tree<Comparable>(){}	
post-conditions: Instantiates a FHsplayTree class to be
				 used by the client program



bool insert(const Comparable &x)
pre-conditions: A generic object of type "Comparable" (any type) should
				be passed into the function.
post-conditions: The functions will either return a boolean value
				 true or false depending on whether the function 
				 was able to insert an object x of any type
				 (generic class Comparable).

bool remove(const Comparable &x)
pre-conditions: A generic object of type "Comparable" (any type) should
				be passed into the function.
post-conditions: The function will return a boolean value of
				 true or false depending on whether the functions
				  was able to remove an object of any type 'x'
				 (generic class Comparable).

bool contains(const Comparable &x)
pre-conditions:A generic object of type "Comparable" (any type) should
				be passed into the function.
post-conditions: The function will return a boolean value of 

const Comparable & find(const Comparable &x)
pre-conditions:A generic object of type "Comparable" (any type) should
				be passed into the function.
post-conditions: The class will return the data held by the node if
				 successful or will throw an  exception if the object
				 wasn't found.

const Comparable &showRoot()
pre-conditions: Root node is not NULL
post-conditions: Displays data from root node.



--------------------Private member functions-----------------------------------

void splay(FHs_treeNode<Comparable> * & root, const Comparable & x)
pre-conditions: A tree that is not empty/null. A node of tree to be splayed
				should be passed in - of type FHs_treeNode.
				
post-conditions: The tree with root node "root" will be splayed and reassembled.


void rotateWithLeftChild(FHs_treeNode<Comparable> * & k2)
pre-conditions: Requires a FHs_treeNode in a tree, to be passed in of generic
				type "Comparable".
post-conditions: Performs a left rotation using the node k2,

void rotateWithRightChild(FHs_treeNode<Comparable> * & k2)
pre-conditions: Requires a FHs_treeNode in a tree, to be passed in of generic
				type "Comparable".
post-conditions: Performs a right rotation using the node k2,



*/

template <class Comparable>
class FHsplayTree: public FHsearch_tree <Comparable> {
	
	
	protected:
		
		void splay(FHs_treeNode<Comparable> * & root, const Comparable & x);
		void rotateWithLeftChild(FHs_treeNode<Comparable> * & k2);
		void rotateWithRightChild(FHs_treeNode<Comparable> * & k2);
		
	public:
		
		//As in FHavlTree
		FHsplayTree() : FHsearch_tree<Comparable>(){}		
		bool insert(const Comparable &x);
		bool remove(const Comparable &x);
		bool contains(const Comparable &x);
		const Comparable & find(const Comparable &x);
		const Comparable &showRoot();
		
	
  
};


//Private methods/member functions

template <class Comparable>
void FHsplayTree<Comparable>::splay(FHs_treeNode<Comparable> * & root, const Comparable & x){
	
	//Initialize trees to NULL
	FHs_treeNode<Comparable> * leftTree = NULL;
	FHs_treeNode<Comparable> * rightTree = NULL;
	FHs_treeNode<Comparable> * leftTreeMin = NULL;
	FHs_treeNode<Comparable> * rightTreeMin = NULL;

	
	while(root!=NULL){
		
		
		if(x < root->data){
			
			
			if(root->lftChild == NULL){
				//x is not in the tree
				break;
			}
			
			
			
			if(x < root->lftChild->data){
				
				rotateWithLeftChild(root);
				if(root->lftChild==NULL){
					//x is not in the tree
					break;
				}
			}
			
			
			
			//add root to rightTree at its minimum node - update the rightTreeMin to point to this node
			
			if (rightTree!=NULL) {//If not first addition to right tree
			
				rightTreeMin->lftChild = root;
			
			}
			else {
				
				rightTree = root;
			}
			
			rightTreeMin = root;
			
			//update the new working root:  set root to root's left child
			root = root->lftChild;
		}
		
		
		
		
		
		
		else if(x > root->data){
		
			if(root->rtChild == NULL){
				break;
			}
			
			if(x > root->rtChild->data){
				
				rotateWithRightChild(root);
				if(root->rtChild==NULL){
					//x is not in the tree
					break;
				}
			}
			
			//add root to leftTree at its maximum node - update the leftTreeMax to point to this node
			if (leftTree!=NULL) {//If not first addition to right tree
				leftTreeMin->rtChild = root;
			}
			
			else {
				leftTree = root;
			}
			
			leftTreeMin = root;
			
			//update the new working root:  set root to root's left child
			root = root->rtChild;
			
		}
		
		
		else{
			break;
		}
		
	}
		
		
		
		
	if (leftTree != NULL) {
		
    	leftTreeMin->rtChild = root->lftChild;
    	root->lftChild = leftTree;
	}
   if (rightTree != NULL) {
   	
    	rightTreeMin->lftChild = root->rtChild;
    	root->rtChild = rightTree;
    	
	}
		
		
		
	
	
}





template <class Comparable>
void FHsplayTree<Comparable>::rotateWithLeftChild(FHs_treeNode<Comparable> * & k2){
	
	//From lesson 5.4. H
	FHs_treeNode<Comparable> *k1 = k2->lftChild;
    k2->lftChild = k1->rtChild;
    k1->rtChild = k2;
    k2 = k1;
    
}





template <class Comparable>
void FHsplayTree<Comparable>::rotateWithRightChild(FHs_treeNode<Comparable> * & k2){
	
	FHs_treeNode<Comparable> *k1 = k2->rtChild;
	k2->rtChild = k1->lftChild;
	k1->lftChild = k2;
	k2 = k1;
	
}

//Public methods/member functions


template <class Comparable>
bool FHsplayTree<Comparable>::insert(const Comparable &x){
	if (this->mRoot == NULL){
		
		this->mRoot = new FHs_treeNode<Comparable>(x,NULL,NULL);
		this->mSize++;
		return true;
	}
	
	else{
		splay(this->mRoot, x);
	}
	
	
	
	if(x < this->mRoot->data){
		FHs_treeNode<Comparable> * newNode = new FHs_treeNode<Comparable>(x,this->mRoot->lftChild, this->mRoot);
		
		this->mRoot = newNode;
		this->mSize++;
		return true;
	}
	
	else if (x > this->mRoot->data){
		FHs_treeNode<Comparable> * newNode = new FHs_treeNode<Comparable>(x, this->mRoot, this->mRoot->rtChild);
		
		this->mRoot = newNode;
		this->mSize++;
		return true;
	}
	
	
	return false;
	
}


template <class Comparable>
bool FHsplayTree<Comparable>::remove(const Comparable &x){
	
	if (this->mRoot == NULL){
		return false;
	}
	
	else{
		splay(this->mRoot, x);
	}
	
	
	
	if((x < this->mRoot->data) or (this->mRoot->data < x)){
		return false;
	}
	
	
	
	FHs_treeNode<Comparable> * newRoot = NULL;
	if(this->mRoot->lftChild == NULL){
		newRoot = this->mRoot->rtChild;
	}
	
	else{
		
		newRoot = this->mRoot->lftChild;
		splay(newRoot, x);
		newRoot->rtChild =this->mRoot->rtChild;
		
	}
	
	
	delete this->mRoot;
	this->mRoot = newRoot;
	return true;
	
	
	
}


template <class Comparable>
const Comparable & FHsplayTree<Comparable>::find(const Comparable &x){
	
	
	splay(this->mRoot, x);
	
	
	
	//If not found then throw error, since == operator is not allowed.
	if ((x < this->mRoot->data) or (this->mRoot->data < x)) {
		
		//As required in the spec
		throw (typename FHsearch_tree<Comparable>::NotFoundException());
    }
	else {
    	return this->mRoot->data;
    }
	
}


template <class Comparable>
bool FHsplayTree<Comparable>::contains(const Comparable &x){
	bool isContained;
	try{
		isContained = (find(x) != NULL);
		return isContained;
	}
	
	catch(...){
		return false;
	}
	
}




template <class Comparable>
const Comparable & FHsplayTree<Comparable>::showRoot(){
	
	if (this->mRoot != NULL){
		return this->mRoot->data;
	}
}

#endif
