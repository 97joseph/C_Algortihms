#ifndef FHSPARSEMAT_H
#define FHSPARSEMAT_H
#include "FHvector.h"
#include "FHlist.h"
#include <iomanip>

/*
Name: Dillon Pinto

Class: CS 2C

Date: 10/3/2016////////

File name: a2_2.cpp (assignment 2, part 2)

Description: The SparseMat class contains a FHlist
			 inside a FHvector and a MatNode object
			 for every non-zero node in the list.
			 The sparse matrix shows values in a
			 large matrix that have a few non-zero values.
			 The SparseMat matrix doesn't hold every value
			 (zero and non-zero) in a very large M X M matrix.
			 Each list in the vector may hold no values (usually)
			 or hold MatNode objects which represent the non-zero
			 values in the matrix.

*/

const int SIZE_OF_SUB_SQUARE_SPACING = 2;


/*
The MatNode class acts as a node in the matrix that does not
contain the default value.

Object data;
the "data" object of generic type should contain a value that
is not the default value.


MatNode(int cl = 0, Object dt = Object()) : col(cl), data(dt) {}
pre-conditions: cl is a non-zero value less than colSize
			    and dt holds a value not equal to the default value
post-conditions: A MatNode object is initialized with a col attribute
				 of cl and data "dt".

int getCol() const { return col; }
post-conditions: returns the the column coordinate the node is
				 located in,
				 

col is protected and not private in anticipation of a future sub class.
It holds a non-negative value of the col coordinate less than colSize.

*/
template <class Object>
class MatNode {
	protected:
		int col;
	
	public:
		Object data;
		// we need a default constructor for lists
		MatNode(int cl = 0, Object dt = Object()) : col(cl), data(dt) {}
		int getCol() const { return col; }
};








/*
The SparseMat class is a data structure made up of FHlist(s) of MatNode objects (if any)
in a FHvector. This creates a sparse M x M matrix that doesn't need to take nearly as many
values as in a very large M x M matrix. This allows the data structure to save a lot of 
space.

SparseMat(int r, int c, const Object & defaultVal);
pre-condition: the int variables r and c have to be
			   non-negative values. defaultVal can be
			   an object of any type or primitive data types.
post-condition: A SparseMat object (sparse matrix) is initialized.
				All FHlists in the vector are empty to show that they
				contain only the "defaultVal" values.
				

const Object & get(int r, int c) const;
pre-condition: The int variables r and c have to be non-zero
			   and less than member variables rowSize and colSize.
post-condition:The value of the corresponding row/value pair will be
			   returned. If the row/value pair contains no value that
			   has been set, the "defaultVal" will be returned.

bool set(int r, int c, const Object &x);
pre-condition:The int variables r and c have to be non-zero
			  and less than member variables rowSize and colSize.

post-condition:The row/value pair associated with r and c will be
			   set to the value x.
			   If x is the default value then
			   the node won't be replaced after being deleted.
			   So a get function call for the row/value pair r and c
			   will return defaultVal in that case.
			   Returns true if a value has been set or reverted to the
			   default value, returns false if bounds have been violated.


void clear();
pre-condition: A SparseMat object exists. Optionally with values in some of
			  the lists.
post-condition: All lists will be cleared setting the SparseMat object to
			    defaultVal.

void showSubSquare(int start, int size);
pre-condition: start and size variables should be non-zero values
			   less than the rowSize and colSize.
post-condition: Displays a sub-square/sub-set of the matrix from
				start to start+size.
				

The data memberse in the SparseMat class are protected, not private.
In anticipation of a future sub/derived/child class.
MasterCol is a FHvector object made up of FHlists objects that will
hold MatNode objects. MatNode objects will hold data of any type in the
"data" member variable.

rowSize and Colsize are always non-zero values that hold the size of the rows
and columns in the matrix

defaultVal of type generic type "Object" can be of any type and will be the
default value of the sparse matrix i.e the value that is supposed to be held
in a certain row/column pair if a value hasn't been assigned to it.

The "rows" object is of type MasterCol.


*/








template <class Object>
class SparseMat {
	protected:
		typedef FHlist<MatNode<Object> > MatRow;
		typedef FHvector<MatRow> MasterCol;
		int rowSize, colSize;
		Object defaultVal;
		MasterCol rows;
	
	public:
		
		SparseMat(int r, int c, const Object & defaultVal);
		const Object & get(int r, int c) const;
		bool set(int r, int c, const Object &x);
		void clear();
		void showSubSquare(int start, int size);
};







template <class Object>
SparseMat<Object>::SparseMat(int r, int c, const Object & defaultVal):
				  rowSize(r), colSize(c),defaultVal(defaultVal),
				  rows(MasterCol(rowSize)){}









template <class Object>
bool SparseMat<Object>::set(int r, int c, const Object &x) {
	
	
	//To check that bounds haven't been violated.
	if ( (r < 0) or (c < 0) or ( r >= rowSize) or (c >= colSize)){
		return false;
	}
	
	typename MatRow::iterator iter, endOfList = rows[r].end();
	
	for (iter = rows[r].begin(); iter != endOfList; iter++) {
		
		if ((*iter).getCol() > c) {
			break;
		}
		else if ((*iter).getCol() == c){
			rows[r].erase(iter);
		}
	}
	
	if (x != defaultVal) {
		rows[r].insert(iter, MatNode<Object>(c, x));
	}

	return true;
}







template <class Object>
const Object& SparseMat<Object>::get(int r, int c) const{
	
	if ( (r < 0) or (c < 0) or ( r >= rowSize) or (c >= colSize)){
		throw 0;
	}
	
	typename MatRow::const_iterator iter, endOfList = rows[r].end();
	
	for(iter = rows[r].begin(); iter != endOfList; iter++){
		if ((*iter).getCol() == c){
			return (*iter).data;
		}
	}
	
	return defaultVal;
	
}









template <class Object>
void SparseMat<Object>::clear(){
	
	for(int i=0; i<rowSize; i++){
		rows[i].clear();
	}
}











template <class Object>
void SparseMat<Object>::showSubSquare(int start, int size) {
	
	for (int row = start; row < (start + size); row++){
		for (int col = start; col < (start + size) ; col++){
			cout << right << setw(SIZE_OF_SUB_SQUARE_SPACING)
			     << get(row,col) << "  ";
		}
		cout << "\n";
	}
	
	cout << "\n\n";
}
#endif









/*
Test run:
0
35
21
oops
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0  35   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0  21   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0  21   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0


 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
 0   0   0   0   0   0   0   0   0   0   0   0   0   0  99



*/
