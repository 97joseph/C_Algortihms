/*

Name: Dillon Pinto
Date: 11/25/2016
Description: FHflowGraph and FHflowVertex are 2 classes that have
			 been modified from the original FHgraph and FHvertex
			 classes to fit the maximum flow problem which the client
			 to get the maximum flow of any network, which is based
			 of Dijkstra's algorithm.
*/
#ifndef FHFLOWGRAPH_H
#define FHFLOWGRAPH_H
#include <limits.h>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iostream>
#include <functional>
using namespace std;




// CostType is some numeric type that expresses cost of edges
// Object is the non-graph data for a vertex
template <class Object, typename CostType>
class FHflowVertex
{
   // internal typedefs to simplify syntax
   typedef FHflowVertex<Object, CostType>* VertPtr;
   typedef map<VertPtr, CostType> EdgePairList;

public:
   static int nSortKey;
   static stack<int> keyStack;
   static enum { SORT_BY_DATA, SORT_BY_DIST } eSortType;
   static bool setNSortType( int whichType );
   static void pushSortKey() { keyStack.push(nSortKey); }
   static void popSortKey() { nSortKey = keyStack.top(); keyStack.pop(); }

   static int const INFINITY_FH = INT_MAX;  // defined in limits.h
   EdgePairList flowAdjList, resAdjList;
   Object data;
   CostType dist;
   VertPtr nextInPath;  // used for client-specific info

   FHflowVertex( const Object & x = Object() );

   void addToFlowAdjList(VertPtr neighbor, CostType cost);
   void addToResAdjList(VertPtr neighbor, CostType cost);
   bool operator< ( const FHflowVertex<Object, CostType> & rhs) const;
   const FHflowVertex<Object, CostType> & operator=
      ( const FHflowVertex<Object, CostType> & rhs);
   void showFlowAdjList();
   void showResAdjList();
};

// static const initializations for Vertex --------------
template <class Object, typename CostType>
int FHflowVertex<Object, CostType>::nSortKey 
   = FHflowVertex<Object, CostType>::SORT_BY_DATA;

template <class Object, typename CostType>
stack<int> FHflowVertex<Object, CostType>::keyStack;
// ------------------------------------------------------







template <class Object, typename CostType>
bool FHflowVertex<Object, CostType>::setNSortType( int whichType )
{
   switch (whichType)
   {
   case SORT_BY_DATA:
   case SORT_BY_DIST:
      nSortKey = whichType;
      return true;
   default:
      return false;
   }
}








template <class Object, typename CostType>
FHflowVertex<Object, CostType>::FHflowVertex( const Object & x) 
   : data(x), dist(0), nextInPath(NULL) {
   // nothing to do
}









template <class Object, typename CostType>
void FHflowVertex<Object, CostType>::addToResAdjList
	 (FHflowVertex<Object, CostType> *neighbor, CostType cost){ 
	resAdjList[neighbor] = cost;
}









template <class Object, typename CostType>
void FHflowVertex<Object, CostType>::addToFlowAdjList
	 (FHflowVertex<Object, CostType> *neighbor, CostType cost){ 
	flowAdjList[neighbor] = cost;
}










template <class Object, typename CostType>
bool FHflowVertex<Object, CostType>::operator<(
   const FHflowVertex<Object, CostType> & rhs) const
{
   switch (nSortKey)
   {
   case SORT_BY_DIST:
      return (dist < rhs.dist);
   case SORT_BY_DATA:
      return (data < rhs.data);
   default:
      return false;
   }
}










template <class Object, typename CostType>
const FHflowVertex<Object, CostType> & FHflowVertex<Object, CostType>::operator=(
   const FHflowVertex<Object, CostType> & rhs)
{
   flowAdjList = rhs.flowAdjList;
   resAdjList = rhs.resAdjList;
   data = rhs.data;
   dist = rhs.dist;
   nextInPath = rhs.nextInPath;;
   return *this;
}









template <class Object, typename CostType>
void FHflowVertex<Object, CostType>::showFlowAdjList()
{
   typename EdgePairList::iterator iter;

   cout << "Adj List for " << data << ": ";
   for (iter = flowAdjList.begin(); iter != flowAdjList.end(); ++iter)
      cout << iter->first->data << "(" << iter->second << ") ";
   cout << endl;
}









template <class Object, typename CostType>
void FHflowVertex<Object, CostType>::showResAdjList()
{
   typename EdgePairList::iterator iter;

   cout << "Adj List for " << data << ": ";
   for (iter = resAdjList.begin(); iter != resAdjList.end(); ++iter)
      cout << iter->first->data << "(" << iter->second << ") ";
   cout << endl;
}











//----------------------------------------------------------------------------------------
template <class Object, typename CostType>
class FHflowGraph
{
   // internal typedefs to simplify syntax
   typedef FHflowVertex<Object, CostType> Vertex;
   typedef FHflowVertex<Object, CostType>* VertPtr;
   typedef map<VertPtr, CostType> EdgePairList;
   typedef set<VertPtr> VertPtrSet;
   typedef set<Vertex> VertexSet;
	
	private:
		VertPtrSet vertPtrSet;
		VertPtr startVertPtr, endVertPtr;
		VertexSet vertexSet;
	
	public:
		FHflowGraph () {}
		void addEdge(const Object &source, const Object &dest, CostType cost);
		VertPtr addToVertexSet(const Object & object);
		void showFlowAdjTable();
		void showResAdjTable();
		void clear();
		bool setStartVert(const Object &x);
		bool setEndVert(const Object &x);
		
		CostType findMaxFlow();
		bool establishNextFlowPath();
		CostType getLimitingFlowOnResPath();
		bool adjustPathByCost(CostType cost);
		CostType getCostOfResEdge(VertPtr src, VertPtr dst);
		bool addCostToResEdge(VertPtr src, VertPtr dst, CostType cost);
		bool addCostToFlowEdge(VertPtr src, VertPtr dst, CostType cost);
		
		
		
		
	
	private:
	   VertPtr getVertexWithThisData(const Object & x);
	};











template <class Object, typename CostType>
FHflowVertex<Object, CostType>* FHflowGraph<Object, CostType>::addToVertexSet(
   const Object & object)
{
   pair<typename VertexSet::iterator, bool> retVal;
   VertPtr vPtr;

   // save sort key for client
   Vertex::pushSortKey();
   Vertex::setNSortType(Vertex::SORT_BY_DATA);

   // build and insert vertex into master list
   retVal = vertexSet.insert( Vertex(object) );

   // get pointer to this vertex and put into vert pointer list
   vPtr = (VertPtr)&*retVal.first;
   vertPtrSet.insert(vPtr);

   Vertex::popSortKey();  // restore client sort key
   return vPtr;
}







template <class Object, typename CostType>
void FHflowGraph<Object, CostType>::clear()
{
   vertexSet.clear();
   vertPtrSet.clear();
}









template <class Object, typename CostType>
void FHflowGraph<Object, CostType>::addEdge(
   const Object &source, const Object &dest, CostType cost ){
	VertPtr src, dst;

	src = addToVertexSet(source);
	dst = addToVertexSet(dest);
	src->addToFlowAdjList(dst, 0);
	src->addToResAdjList(dst, cost);//forward edge
	dst->addToResAdjList(src, 0);//reverse edge, cost = 0

	
}








template <class Object, typename CostType>
void FHflowGraph<Object, CostType>::showFlowAdjTable()
{
   typename VertPtrSet::iterator iter;

   cout << "------------------------ \n";
   for (iter = vertPtrSet.begin(); iter != vertPtrSet.end(); ++iter)
      (*iter)->showFlowAdjList();
   cout << endl;
}










template <class Object, typename CostType>
void FHflowGraph<Object, CostType>::showResAdjTable()
{
   typename VertPtrSet::iterator iter;

   cout << "------------------------ \n";
   for (iter = vertPtrSet.begin(); iter != vertPtrSet.end(); ++iter)
      (*iter)->showResAdjList();
   cout << endl;
}









template <class Object, typename CostType>
FHflowVertex<Object, CostType>* FHflowGraph<Object, CostType>::getVertexWithThisData(
   const Object & x)
{
	typename VertexSet::iterator findResult;
	Vertex vert(x);
	
	Vertex::pushSortKey();  // save client sort key
	Vertex::setNSortType(Vertex::SORT_BY_DATA);
	findResult = vertexSet.find(vert);
	Vertex::popSortKey();  // restore client value
	
	if ( findResult == vertexSet.end() )
		return NULL;
	return  (VertPtr)&*findResult;     // the address of the vertex in the set of originals
}





template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::setStartVert(const Object &x){
	return ((startVertPtr = getVertexWithThisData(x)) != NULL);
}
   
   
   
   
   
   
template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::setEndVert(const Object &x){
	return ((endVertPtr = getVertexWithThisData(x)) != NULL);
}




//-----------------------------------------------------------------------------------







template <class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::findMaxFlow(){
	
	typename EdgePairList::iterator iter;
	CostType maxFlow  = 0;
	CostType limitingFlow;
	while ( establishNextFlowPath() ){
		limitingFlow = getLimitingFlowOnResPath();
		adjustPathByCost(limitingFlow);
	}
	if (startVertPtr == NULL){
		return (CostType)0;
	}

	for (iter = startVertPtr->flowAdjList.begin(); 
		 iter != startVertPtr->flowAdjList.end(); ++iter){
    	maxFlow += iter->second;
	}
      
	return maxFlow;
	
	
}












template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::establishNextFlowPath(){
	VertPtr wPtr, vPtr;
	VertPtr sPtr = startVertPtr;
	CostType costVW;
	typename VertPtrSet::iterator vIter;
	typename EdgePairList::iterator edgePrIter;
	queue<VertPtr> partiallyProcessedVerts;
	
	
	if (sPtr == NULL)
		return false;
	
	// initialize the vertex list and place the starting vert in p_p_v queue
	for (vIter = vertPtrSet.begin(); vIter != vertPtrSet.end(); ++vIter)
	{
		(*vIter)->dist = Vertex::INFINITY_FH;
		(*vIter)->nextInPath = NULL;
	}
	
	sPtr->dist = 0;
	partiallyProcessedVerts.push( sPtr ); // or, FHbinHeap::insert(), e.g.
	while( !partiallyProcessedVerts.empty() ){
		vPtr = partiallyProcessedVerts.front(); 
		partiallyProcessedVerts.pop();
		
		// inner dijkstra loop: for each vert adj to v, lower its dist to s if you can
		for (edgePrIter = vPtr->resAdjList.begin();edgePrIter != vPtr->resAdjList.end(); edgePrIter++){	
			wPtr = edgePrIter->first;
			costVW = edgePrIter->second;
			if ((costVW != 0) and ( vPtr->dist + costVW < wPtr->dist )){
			    wPtr->dist = vPtr->dist + costVW;
			    wPtr->nextInPath = vPtr; 
			    
			    // *wPtr now has improved distance, so add wPtr to p_p_v queue
				partiallyProcessedVerts.push(wPtr); 
			}
			if (vPtr == endVertPtr){
				return true;
			}
		}
	}
	return false;
	
}





template <class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::getCostOfResEdge(VertPtr src, VertPtr dst){

	if (dst == NULL or src == NULL){
		return 0;
	}
	typename EdgePairList::iterator iter;
	iter = src->resAdjList.find(dst);
	if (iter == src->resAdjList.end()){
		return 0;
	}
	else {
		return iter->second;
	}
   
}







template <class Object, typename CostType>
CostType FHflowGraph<Object, CostType>::getLimitingFlowOnResPath(){
	CostType limiting_flow;//The limiting flow value to be returned
	VertPtr vp, start, stop;
	stack<VertPtr> pathStack;

	start = startVertPtr;
	stop = endVertPtr;
	
	if (start == NULL or stop == NULL){
		return false;
	}
	
	limiting_flow = stop->INFINITY_FH;
	
	for (vp = stop; vp != start;vp=vp->nextInPath){
		if ( vp->nextInPath == NULL ){
	    	cout << "No path found to from " << start
	    		 << " to " << stop  << endl;
	    	return 0;
		}
		if (getCostOfResEdge(vp->nextInPath, vp) < limiting_flow){
			
        	limiting_flow = getCostOfResEdge( vp->nextInPath ,vp );
		}	
	}
	return 	limiting_flow;
}











template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::addCostToResEdge(VertPtr src, VertPtr dst, CostType cost){
	
	
	if (src == NULL or dst == NULL){
		return NULL;
	}
	typename EdgePairList::iterator iter;
	iter = src->resAdjList.find(dst);
	if (iter == src->resAdjList.end()){
    	return false;
	}
	else{
		iter->second += cost;
		return true;	
	}
}









template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::adjustPathByCost(CostType cost){
	VertPtr vrtPtr;
	VertPtr start = startVertPtr;
	VertPtr stop = endVertPtr;
	if (start == NULL or stop == NULL){
   		return false;
	}
	
	for (vrtPtr  = stop; vrtPtr  != start; vrtPtr  = vrtPtr ->nextInPath){
    	if (vrtPtr ->nextInPath == NULL){
    		return false;
    	}

    	if (!addCostToResEdge(vrtPtr ->nextInPath, vrtPtr , -cost) or !addCostToResEdge(vrtPtr , vrtPtr ->nextInPath, cost)
    	    or !addCostToFlowEdge(vrtPtr ->nextInPath, vrtPtr , cost)){
        	return false;
      }
	}
	
	return true;
}
	










template <class Object, typename CostType>
bool FHflowGraph<Object, CostType>::addCostToFlowEdge(VertPtr src, VertPtr dst, CostType cost){
	
	//
	if (src == NULL or dst == NULL){
		return NULL;
	}
   
	typename EdgePairList::iterator iter;
	iter = src->flowAdjList.find(dst);
	if (iter == src->flowAdjList.end()){
    	iter = dst->flowAdjList.find(src);
    	cost = -1 * cost;//Will result in a subtraction below to avoid redundancy
	}
   
   //Can result in either an addition or subtraction, without turning values negative
	iter->second += cost;
	return true;
}

/*
Output from client:



------------------------
Adj List for s: a(3) b(2)
Adj List for a: s(0) b(1) c(3) d(4)
Adj List for b: s(0) a(0) d(2)
Adj List for c: a(0) t(2)
Adj List for d: a(0) b(0) t(3)
Adj List for t: c(0) d(0)

------------------------
Adj List for s: a(0) b(0)
Adj List for a: b(0) c(0) d(0)
Adj List for b: d(0)
Adj List for c: t(0)
Adj List for d: t(0)
Adj List for t:

Final flow: 5
------------------------
Adj List for s: a(0) b(0)
Adj List for a: s(3) b(1) c(1) d(3)
Adj List for b: s(2) a(0) d(0)
Adj List for c: a(2) t(0)
Adj List for d: a(1) b(2) t(0)
Adj List for t: c(2) d(3)

------------------------
Adj List for s: a(3) b(2)
Adj List for a: b(0) c(2) d(1)
Adj List for b: d(2)
Adj List for c: t(2)
Adj List for d: t(3)
Adj List for t:


--------------------------------
Process exited after 0.0625 seconds with return value 0
Press any key to continue . . .




*/


#endif
