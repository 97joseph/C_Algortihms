/*
Name: Dillon Pinto
Class: CS 2C
*/

// --------------- main ---------------

// CS 2C  Simple Search Tree Client - Lazy Deletion, int data
#include <iostream>
#include "FHlazySearchTree.h"
#include <string>
#include <stack>
using namespace std;






template <typename Object>
class PrintObject
{
public:
   void operator()(Object obj)
   {
      cout << obj << " ";
   }
};





int main()
{

   int k;
   FHsearch_tree<int> searchTree;
   PrintObject<int> intPrinter;

   searchTree.traverse(intPrinter);

   cout << "\ninitial size: " << searchTree.size() << endl;
   searchTree.insert(50);
   searchTree.insert(20);
   searchTree.insert(30);
   searchTree.insert(70);
   searchTree.insert(90);
   searchTree.insert(30);//should not be added
   searchTree.insert(70);//should not be added
   searchTree.insert(10);
   searchTree.insert(40);
   searchTree.insert(50);//should not be added
   searchTree.insert(80);
   searchTree.insert(60);

   cout << "After populating -- traversal and sizes: \n";
   searchTree.traverse(intPrinter);
   cout << "\ntree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   cout << "Collecting garbage on new tree - should be no garbage." << endl;
   searchTree.collectGarbage();
   cout << "tree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   // test assignment operator
   FHsearch_tree<int> searchTree2 = searchTree;

   cout << "\n\nAttempting 1 removal: \n";
   if (searchTree.remove(20))
      cout << "removed " << 20 << endl;
   cout << "tree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   cout << "Collecting Garbage - should clean 1 item. " << endl;
   searchTree.collectGarbage();
   cout << "tree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   cout << "Collecting Garbage again - no change expected. " << endl;
   searchTree.collectGarbage();
   cout << "tree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   // test soft insertion and deletion:

   cout << "Adding 'hard' 22 - should see new sizes. " << endl;
   searchTree.insert(22);
   searchTree.traverse(intPrinter);
   cout << "\ntree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   cout << "\nAfter soft removal. " << endl;
   searchTree.remove(22);
   searchTree.traverse(intPrinter);
   cout << "\ntree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   cout << "Repeating soft removal. Should see no change. " << endl;
   searchTree.remove(22);
   searchTree.traverse(intPrinter);
   cout << "\ntree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   cout << "Soft insertion. Hard size should not change. " << endl;
   searchTree.insert(22);
   searchTree.traverse(intPrinter);
   cout << "\ntree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   cout << "\n\nAttempting 100 removals: \n";
   for (k = 100; k > 0; k--)
   {
      if (searchTree.remove(k))
         cout << "removed " << k << endl;
   }
   searchTree.collectGarbage();

   cout << "\nsearchTree now:\n";
   searchTree.traverse(intPrinter);
   cout << "\ntree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl;

   searchTree2.insert(500);
   searchTree2.insert(200);
   searchTree2.insert(300);
   searchTree2.insert(700);
   searchTree2.insert(100);
   searchTree2.insert(600);
   cout << "\nsearchTree2:\n";
   searchTree2.traverse(intPrinter);
   cout << "\ntree 2 size: " << searchTree2.size() 
      << "  Hard size: " << searchTree2.sizeHard() << endl;
      
	
	cout << "\n\nTests on tree 1 and tree 2 after initial tests.\n\n";
	
	cout << "Delete smallest and largest member of tree 2\n";
	searchTree2.remove(10);
	searchTree2.remove(600);
	
	cout << "\nsearchTree2:\n";
   searchTree2.traverse(intPrinter);
   cout << "\ntree 2 size: " << searchTree2.size() 
      << "  Hard size: " << searchTree2.sizeHard() << endl;
      
	cout << "Collect garbage from tree 2, hard size should reduce by 2 - \n\n";
	searchTree2.collectGarbage();
	searchTree2.traverse(intPrinter);
   	cout << "\ntree 2 size: " << searchTree2.size() 
      << "  Hard size: " << searchTree2.sizeHard() << endl;
	
	
	cout << "\n\nRemoving non-existing nodes from both trees\n";
	searchTree.remove(22);
	searchTree.remove(0);
	searchTree2.remove(923);
	searchTree.collectGarbage();
	searchTree2.collectGarbage();
	
	searchTree.traverse(intPrinter);
   cout << "\ntree 1 size: " << searchTree.size() 
      << "  Hard size: " << searchTree.sizeHard() << endl << endl;
      
	searchTree2.traverse(intPrinter);
   cout << "\ntree 2 size: " << searchTree2.size() 
      << "  Hard size: " << searchTree2.sizeHard() << endl;
	
	
	
	cout << "\n\nFind methods on both trees, for empty try and for tree with nodes:\n\n";
	
	try{
		searchTree.findMax();
	}
	catch(...){
		cout << "Empty tree exception caught.\n";
	}
	
	try{
		searchTree.findMin();
	}
	catch(...){
		cout << "Empty tree exception caught.\n";
	}
	
	try{
		searchTree2.find(923);//doesn't exist
	}
	
	catch(...){
		cout << "Exception caught for find on non-existant node.\n";
	}

	
	system("PAUSE");

}

/* ---------------------- Run --------------------------

initial size: 0
After populating -- traversal and sizes:
10 20 30 40 50 60 70 80 90
tree 1 size: 9  Hard size: 9
Collecting garbage on new tree - should be no garbage.
tree 1 size: 9  Hard size: 9


Attempting 1 removal:
removed 20
tree 1 size: 8  Hard size: 9
Collecting Garbage - should clean 1 item.
tree 1 size: 8  Hard size: 8
Collecting Garbage again - no change expected.
tree 1 size: 8  Hard size: 8
Adding 'hard' 22 - should see new sizes.
10 22 30 40 50 60 70 80 90
tree 1 size: 9  Hard size: 9

After soft removal.
10 30 40 50 60 70 80 90
tree 1 size: 8  Hard size: 9
Repeating soft removal. Should see no change.
10 30 40 50 60 70 80 90
tree 1 size: 8  Hard size: 9
Soft insertion. Hard size should not change.
10 22 30 40 50 60 70 80 90
tree 1 size: 9  Hard size: 9


Attempting 100 removals:
removed 90
removed 80
removed 70
removed 60
removed 50
removed 40
removed 30
removed 22
removed 10

searchTree now:

tree 1 size: 0  Hard size: 0

searchTree2:
10 20 30 40 50 60 70 80 90 100 200 300 500 600 700
tree 2 size: 15  Hard size: 15


Tests on tree 1 and tree 2 after initial tests.

Delete smallest and largest member of tree 2

searchTree2:
20 30 40 50 60 70 80 90 100 200 300 500 700
tree 2 size: 13  Hard size: 15
Collect garbage from tree 2, hard size should reduce by 2 -

20 30 40 50 60 70 80 90 100 200 300 500 700
tree 2 size: 13  Hard size: 13


Removing non-existing nodes from both trees

tree 1 size: 0  Hard size: 0

20 30 40 50 60 70 80 90 100 200 300 500 700
tree 2 size: 13  Hard size: 13


Find methods on both trees, for empty try and for tree with nodes:

Empty tree exception caught.
Empty tree exception caught.
Exception caught for find on non-existant node.
Press any key to continue . . .

---------------------------------------------------------------------- */
