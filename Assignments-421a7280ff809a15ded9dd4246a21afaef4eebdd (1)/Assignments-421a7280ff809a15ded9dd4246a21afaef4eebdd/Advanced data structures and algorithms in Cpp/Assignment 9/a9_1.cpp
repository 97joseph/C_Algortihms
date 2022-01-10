
// client file --------------------------------------------------
// FHflowGraph client
// CS 2C Foothill College
#include <iostream>
#include <string>
using namespace std;
#include "FHflowGraph.h"

// --------------- main ---------------
int main()
{
   int finalFlow;

   // build graph
   FHflowGraph<string, int> myG;

   myG.addEdge("s","a", 3);    myG.addEdge("s","b", 2); 
   myG.addEdge("a","b", 1);    myG.addEdge("a","c", 3); myG.addEdge("a","d", 4); 
   myG.addEdge("b","d", 2);
   myG.addEdge("c","t", 2); 
   myG.addEdge("d","t", 3);  

   // show the original flow graph
   myG.showResAdjTable();
   myG.showFlowAdjTable();

   myG.setStartVert("s");
   myG.setEndVert("t");
   finalFlow = myG.findMaxFlow();

   cout << "Final flow: " << finalFlow << endl;

   myG.showResAdjTable();
   myG.showFlowAdjTable();

   return 0;  
}

/* --------- output -----------
---------- Residual Adjacency Table ----------
Adj Res List for s: a(3) b(2)
Adj Res List for a: s(0) b(1) c(3) d(4)
Adj Res List for b: s(0) a(0) d(2)
Adj Res List for c: a(0) t(2)
Adj Res List for d: a(0) b(0) t(3)
Adj Res List for t: c(0) d(0)

---------- Flow Adjacency Table ----------
Adj Flow List for s: a(0) b(0)
Adj Flow List for a: b(0) c(0) d(0)
Adj Flow List for b: d(0)
Adj Flow List for c: t(0)
Adj Flow List for d: t(0)
Adj Flow List for t:

Final flow: 5
---------- Residual Adjacency Table ----------
Adj Res List for s: a(0) b(0)
Adj Res List for a: s(3) b(1) c(1) d(3)
Adj Res List for b: s(2) a(0) d(0)
Adj Res List for c: a(2) t(0)
Adj Res List for d: a(1) b(2) t(0)
Adj Res List for t: c(2) d(3)

---------- Flow Adjacency Table ----------
Adj Flow List for s: a(3) b(2)
Adj Flow List for a: b(0) c(2) d(1)
Adj Flow List for b: d(2)
Adj Flow List for c: t(2)
Adj Flow List for d: t(3)
Adj Flow List for t:

Press any key to continue . . .
----------------------------- */
