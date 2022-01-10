// File FHsearch_tree.h
// Template definitions for FHsearchTrees, which are general trees

/*
Name: Dillon Pinto
Class: CS 2C
Assignment: 4
*/
#ifndef FHSEARCHTREE_H
#define FHSEARCHTREE_H
// ---------------------- FHs_treeNode Prototype --------------------------
template <class Comparable>
class FHs_treeNode {
	public:
		FHs_treeNode( const Comparable & d = Comparable(), FHs_treeNode *lt = 0,
		FHs_treeNode *rt = 0): lftChild(lt), rtChild(rt), data(d), deleted(false){}
		
		FHs_treeNode *lftChild, *rtChild;
		Comparable data;
	
	   // for use only with AVL Trees
		virtual int getHeight() const { return 0; }
		virtual bool setHeight(int height) { return true; }
	   
	   
		//Change insert,remove and find
		bool deleted;
}; 

// ---------------------- FHsearch_tree Prototype --------------------------
template <class Comparable>
class FHsearch_tree {
	protected:
		int mSize;
		int mSizeHard;
	    FHs_treeNode<Comparable> *mRoot;
	
	public:
		FHsearch_tree() { mSize = 0; mRoot = 0; mSizeHard = 0; }
		FHsearch_tree(const FHsearch_tree &rhs) 
		  { mRoot = 0; mSize = 0; mSizeHard = 0, *this = rhs; }
		~FHsearch_tree() { clear(); }
		
		const Comparable &findMin() const;
		const Comparable &findMax() const;
		const Comparable &findMinHard() const;
		const Comparable &find(const Comparable &x) const;
		
		bool empty() const { return (mSize == 0); }
		int size() const { return mSize; }
		void clear() { makeEmpty(mRoot); }
		const FHsearch_tree & operator=(const FHsearch_tree &rhs);
		
		//Accesses the mSizeHard member's value for the client.
		int sizeHard() { return mSizeHard;}
		bool insert(const Comparable &x);
		bool remove(const Comparable &x);
		bool contains(const Comparable &x) const { return find(mRoot, x) != 0; }
		void collectGarbage();
		
		template <class Processor>
		void traverse(Processor func) const { traverse(mRoot, func); }
		int showHeight() const { return findHeight(mRoot); }
	
	protected:
		FHs_treeNode<Comparable> *clone( FHs_treeNode<Comparable> *root) const;
		FHs_treeNode<Comparable> *findMin(FHs_treeNode<Comparable> *root) const;
		FHs_treeNode<Comparable> *findMax(FHs_treeNode<Comparable> *root) const;
		FHs_treeNode<Comparable> *findMinHard(FHs_treeNode<Comparable> *root) const;
		FHs_treeNode<Comparable> *find(FHs_treeNode<Comparable> *root,
		  const Comparable &x) const;
		bool insert(FHs_treeNode<Comparable> * &root,
		  const Comparable &x);
		bool remove(FHs_treeNode<Comparable> * &root, const Comparable &x);
		bool removeHard(FHs_treeNode<Comparable> * &root);
		void makeEmpty(FHs_treeNode<Comparable> * &subtreeToDelete);
		template <class Processor>
		void traverse(FHs_treeNode<Comparable> *treeNode, 
		  Processor func, int level = -1) const;
		int findHeight(FHs_treeNode<Comparable> *treeNode, int height = -1) const;
		void collectGarbage(FHs_treeNode<Comparable> * &root);
	public:
	   // for exception throwing
		class EmptyTreeException {};
		class NotFoundException {};
};

// FHsearch_tree public method definitions -----------------------------
template <class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMin() const {
   if (mRoot == 0)
      throw EmptyTreeException();
   return findMin(mRoot)->data;
}

template <class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMax() const {
   if (mRoot == 0)
      throw EmptyTreeException();
   return findMax(mRoot)->data;
}

/*
The public method for findMinHard calls on the private method which
starts a recursion process if the root node is not empty.
The value of the Hard min node is returned after the private method's
recursion process has completed.
*/
template <class Comparable>
const Comparable & FHsearch_tree<Comparable>::findMinHard() const {
   if (mRoot == 0)
      throw EmptyTreeException();
   return findMinHard(mRoot)->data;
}



template <class Comparable>
const Comparable &FHsearch_tree<Comparable>::find(
   const Comparable &x) const { 
   FHs_treeNode<Comparable> *resultNode;
   
   resultNode = find(mRoot, x);
   if (resultNode == 0)
      throw NotFoundException();
    return resultNode->data;
}

//Calls the collectGarbage private method which begins a recursion
//process to clean up all stale nodes in the tree.
template <class Comparable>
void FHsearch_tree<Comparable>::collectGarbage() {
		collectGarbage(mRoot);
}





template <class Comparable>
const FHsearch_tree<Comparable> &FHsearch_tree<Comparable>::operator=(const FHsearch_tree &rhs){
   
   if (&rhs != this){
		clear();
		mRoot = clone(rhs.mRoot);
		mSize = rhs.size();
		mSizeHard = rhs.mSizeHard;
   }
   return *this;
}



template <class Comparable>
bool FHsearch_tree<Comparable>::insert(const Comparable &x) {
	if (insert(mRoot, x))
	{
		mSize++;
		return true;
	}
	return false;
}

template <class Comparable>
bool FHsearch_tree<Comparable>::remove(const Comparable &x) {
   if (remove(mRoot, x))
   {
      mSize--;
      return true;
   }
   return false;
}

template <class Comparable>
template <class Processor>
void FHsearch_tree<Comparable>::traverse( FHs_treeNode<Comparable> *treeNode,
   Processor func, int level) const {
	if (treeNode == 0)
		return;
	// we're not doing anything with level but its there in case we want it
	traverse(treeNode->lftChild, func, level + 1);
	if (!treeNode->deleted){
		func(treeNode->data);
	}
	
	traverse(treeNode->rtChild, func, level + 1);
}


// FHsearch_tree private method definitions -----------------------------
template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::clone(
   FHs_treeNode<Comparable> *root) const {
   FHs_treeNode<Comparable> *newNode;
   if (root == 0)
      return 0;

	//newNode has deleted attribute by default
	newNode =  new FHs_treeNode<Comparable>(root->data, clone(root->lftChild), clone(root->rtChild));
  	return newNode;
}

template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMin(
   FHs_treeNode<Comparable> *root) const {
   	
   if (root == 0)
      return 0;
      
   if (root->lftChild == 0 and !root->deleted)
      return root;
      
   return findMin(root->lftChild);
}

template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMax(
   FHs_treeNode<Comparable> *root) const {
   if (root == 0)
      return 0;
   if (root->rtChild == 0 and !root->deleted)
      return root;
   return findMax(root->rtChild);
}

/*
This function is almost the same as the findMin method
except this function counts nodes that have been marked
as deleted.
First the node is checked to find if it's a NULL node.
It then starts recursing along the left-most side of the sub-tree
to find the smallest value.
*/
template <class Comparable>
FHs_treeNode<Comparable> *FHsearch_tree<Comparable>::findMinHard(
   FHs_treeNode<Comparable> *root) const {
   	
   if (root == 0)
      return 0;
      
   if (root->lftChild == 0)
      return root;
      
   return findMinHard(root->lftChild);
}


template <class Comparable>
FHs_treeNode<Comparable>* FHsearch_tree<Comparable>::find(
   FHs_treeNode<Comparable> *root, const Comparable &x) const
{
   if (root == 0)
      return 0;

   if (x < root->data)
      return find(root->lftChild, x);
      
   if (root->data < x)
      return find(root->rtChild, x);
    
    if (root->deleted){
    	return 0;
	}
   return root;
}

template <class Comparable>
bool FHsearch_tree<Comparable>::insert(FHs_treeNode<Comparable> * &root, const Comparable &x){
	if (root == 0) {
		
		//Needed to be debugged so mSizeHard++ removed from public insert to this position
		mSizeHard++;
		root = new FHs_treeNode<Comparable>(x, 0, 0);
		return true;
	}
	else if (x < root->data)
	  return insert(root->lftChild, x);
	  
	else if (root->data < x)
	  return insert(root->rtChild, x);
	
	else if (root-> deleted){
		//After the node has been reached
		//As mentioned in section 4B.5.1
		root-> deleted = false;
		return (!root->deleted);
	}
	
	return false; // duplicate
}



template <class Comparable>
bool FHsearch_tree<Comparable>::remove(
   FHs_treeNode<Comparable> * &root, const Comparable &x) {
    if (root == 0){
   		return false;
   }

	if (x < root->data){
		return remove(root->lftChild, x);
	}
	
	if (root->data < x){
		return remove(root->rtChild, x);
	}
	


	if (root->deleted){
		return false;//Checks if the node is already deleted and returns false if it is.
	}
	
	//changes the value of the node's deleted member variable to true if lazy delete
	//is successful.
	root->deleted = true;
	return 	root->deleted;
}




/*
This function firsthecks if the root node is null at the start of the function 
in which case it returns false.
It then checks if the root node to be deleted has 2 child nodes, if so another
recursion progression is started by calling the findMinHard function from the
root node. The data and is then swapped between the root node and the values
of the deleted member variables are swapped and then the function recurses again
by calling removeHard. This will happen until a leaf node is reached.
This is handled by the else a non-NULL leaf node is then deleted within the else
statement and the hard size is reduced.
*/
template <class Comparable>
bool FHsearch_tree<Comparable>::removeHard(
   FHs_treeNode<Comparable> * &root)
{
   if (root == 0)
      return false;



   if (root->lftChild != 0 && root->rtChild != 0)
   {
      FHs_treeNode<Comparable> *minNode = findMinHard(root->rtChild);
      root->data = minNode->data;
      minNode->deleted = true;
      root->deleted = !minNode->deleted;
      removeHard(root->rtChild);
   }
   else
   {
      FHs_treeNode<Comparable> *nodeToRemove = root;
      root = (root->lftChild != 0) ? root->lftChild : root->rtChild;
      delete nodeToRemove;
      mSizeHard--;//Reduces hard size after hard remove
   }
   

   return true;
}



template <class Comparable>
void FHsearch_tree<Comparable>::makeEmpty(
   FHs_treeNode<Comparable> * &subtreeToDelete)
{
   if (subtreeToDelete == 0)
      return;

   
   makeEmpty(subtreeToDelete->lftChild);
   makeEmpty(subtreeToDelete->rtChild);

   delete subtreeToDelete;
   subtreeToDelete = 0;
   if (!subtreeToDelete->deleted){
		mSize--;
   }
   mSizeHard--;
}

template <class Comparable>
int FHsearch_tree<Comparable>::findHeight( FHs_treeNode<Comparable> *treeNode,
   int height ) const
{
   int leftHeight, rightHeight;

   if (treeNode == 0)
      return height;
   height++;
   leftHeight = findHeight(treeNode->lftChild, height);
   rightHeight = findHeight(treeNode->rtChild, height);
   return (leftHeight > rightHeight)? leftHeight : rightHeight;
}



/*
The private collectGarbage function first checks if the root node is null.
Then the recursion begins to collect garbage/stale nodes. Once a node that is marked
for deletion is found, it is hard removed by calling the function removeHard on the
node.
*/
template <class Comparable>
void FHsearch_tree<Comparable>::collectGarbage(FHs_treeNode<Comparable> * &root){
	
	if (root == 0){
		return;
	}
	
	//Traverses the tree
	collectGarbage(root->lftChild);
   	collectGarbage(root->rtChild);
   
   //Hard-deletes nodes that are marked deleted (deleted == true)
   if (root->deleted) {
		removeHard(root);
   }
}

#endif
