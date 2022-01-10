// Assignment #5 Instructor Solution
// CS 2C, Foothill College, Michael Loceff

// Client / Splay Tree ----------------------------------------------

#include <iostream>
#include "FHsplayTree.h"
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
   FHsplayTree<int> searchTree;
   //FHsearch_tree<int> searchTree;
   PrintObject<int> intPrinter;

   searchTree.traverse(intPrinter);
   //cout << searchTree.showRoot() << endl;

   cout << "Initial size: " << searchTree.size() << endl;
   for (k = 1; k <= 32; k++)
      searchTree.insert(k);
   cout << "New size: " << searchTree.size() << endl;

   cout << "\nTraversal: \n";
   searchTree.traverse(intPrinter);
   cout << endl << endl;

   for (k = -1; k < 10; k++)
   {
      // searchTree.contains(k);  // alt to find() - different error return
      try
      {
          searchTree.find(k);
      }
      catch( ... )
      {
         cout << " oops ";
      }
         cout << "splay " << k << " --> root: " << searchTree.showRoot() 
            << " height: " << searchTree.showHeight() << endl;
   }

   return 0;
}
