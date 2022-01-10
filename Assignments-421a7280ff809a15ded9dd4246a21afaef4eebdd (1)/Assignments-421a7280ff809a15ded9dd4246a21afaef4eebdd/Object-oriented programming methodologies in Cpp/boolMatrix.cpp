#include <cassert>
#include "boolMatrix.h"
#include <iostream>
using namespace std;


boolMatrix::boolMatrix() {
	int row;
	int column;
	
	for(row = 0; row < NUM_ROWS; row++){
		for(column = 0; column < NUM_COLS; column++){
			gridMatrix[row][column] = false;
		}
	}
}





bool boolMatrix::get(int row, int column) const  {
	assert((row >= 0 and row < NUM_ROWS) and (column >= 0 and column < NUM_COLS));
	return  gridMatrix[row][column];
	
}





void boolMatrix::set(int row, int column, bool element_value) {
	assert((row >= 0 and row < NUM_ROWS) and (column >= 0 and column < NUM_COLS));
	gridMatrix[row][column] = element_value;
}






int boolMatrix::rowCount(int row) const {
	int column;
	int count;
	
	assert(row >= 0 and row < NUM_ROWS);
	count = 0;
	for(column = 0; column < NUM_COLS; column++) {
		if (gridMatrix[row][column]) {
			count++;
		}
	}
	return count;
}






int boolMatrix::colCount(int column) const {
	int row;
	int count;
	
	assert(column >= 0 and column < NUM_COLS);
	count = 0;
	for(row = 0; row < NUM_ROWS; row++) {
		if (gridMatrix[row][column]) {
			count++;
		}
	}
	return count;
}






int boolMatrix::totalCount() const {
	int row;
	int column;
	int count;
	
	count = 0;
	for(row = 0; row < NUM_ROWS; row++) {
		for(column = 0; column < NUM_COLS; column++){
		
			if (gridMatrix[row][column]) {
				count++;
			}
		}
	}	
	return count;
}





void boolMatrix::print() const {
	int row;
	int column;
	int count;
	cout << "  ";
	for (count = 0; count < boolMatrix::NUM_COLS;count++){
		cout << count % 10;
	}
	cout<< endl;
	count = 0;
	for(row = 0; row < NUM_ROWS; row++) {
		if (row < 10){
			cout << " ";
		}
		cout << row;
		for(column = 0; column < NUM_COLS; column++){
		
			if (gridMatrix[row][column]) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
	cout << endl;
	}
}
