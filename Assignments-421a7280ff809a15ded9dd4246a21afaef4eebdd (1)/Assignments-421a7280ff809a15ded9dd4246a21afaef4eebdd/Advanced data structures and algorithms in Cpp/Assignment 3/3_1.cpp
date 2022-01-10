
/*
Name: Dillon Pinto

Class: CS 2C

Date: 10/17/2016////////

File name: a3_1.cpp (assignment 3)

Description: This program creates a sparse matrix of size
			 MAT_SIZE * MAT_SIZE. In this program only 5%
			 of the matrix consists of non-default values.
			 Matrix multiplication functionality has also
			 been added and is used in the program to
			 square the sparse matrix of a certain MAT_SIZE


1) M = 99 gave the smallest non-zero time (0.01s)

2)     M  | Time
       99 | 0.01s 
       198| 0.03s
       297| 0.12s
       396| 0.28s
       495| 0.57s
       594| 1.00s
       693| 1.65s
       792| 2.50
       891| 3.38s
       990| 6.68s
3) M=10,000 till you can't wait (would take an estimated 1.5-3 hours), M=129,874 till program crash
4) The data agreed as it was close to O(N^3) but lower than it, making it a
   good time complexity upper bound estimate.
       
*/

#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;


#define MAT_SIZE 99

typedef float* DynMat[MAT_SIZE];
const int SIZE_OF_SUB_SQUARE_SPACING = 2;


void matMultDyn(const DynMat & matA, const DynMat & matB,
   DynMat & matC, int size);

void matShowDyn(const DynMat & matA, int start, int size);




int main(){
   int r, c;
   srand(time(NULL)); 
   clock_t startTime, stopTime;
   float randFrac;
   int randRow, randCol, smallPercent;

   // non-sparse dynamic matrix
   DynMat matDyn, matDynAns;


   // allocate rows and initialize to 0
   for (r = 0; r < MAT_SIZE; r++)
   {
    	matDyn[r] = new float[MAT_SIZE];
		matDynAns[r] = new float[MAT_SIZE];
    	for (c = 0; c < MAT_SIZE; c++)
      {
	        matDynAns[r][c] = 0;
			matDyn[r][c] = 0;
      }
   }
	
   // generate small% non-default values bet .1 and 10
   smallPercent = MAT_SIZE/20. * MAT_SIZE;  // div by 20. means 5%, of course
   for (r = 0; r < smallPercent; r++)
   {	
   
		//range between 0.1 and 1.0 formula:
		//(lower bound + (random % (upperbound - lowerbound +1 )) / 100
		randFrac = (10.0 + (rand() % (91)) ) / 100.0;
		randCol = rand() % MAT_SIZE;
		randRow = rand() % MAT_SIZE;
		matDyn[randRow][randCol] = randFrac;
		
		
   }

   // 15x15 submatrix in lower right
   matShowDyn(matDyn, MAT_SIZE - 15, 15);

   startTime = clock();  // ------------------ start
		matMultDyn(matDyn, matDyn, matDynAns, MAT_SIZE);
   stopTime = clock();  // ---------------------- stop

   matShowDyn(matDynAns, MAT_SIZE - 15, 15);
   cout << "\nSize = " <<  MAT_SIZE << " Dyn Array Mult Elapsed Time: " 
      << (double)(stopTime - startTime)/(double)CLOCKS_PER_SEC 
      << " seconds." << endl << endl;

   // clean up
	for (r = 0; r < MAT_SIZE; r++){
		delete matDyn[r];
		delete matDynAns[r];
	}
	

   
   cout << endl;
}










/*
This function has 3 for loops, 2 nested inside the outermost loop. These serve to
multiply floating point integers within the matrix and summing them and then assigning
the sum to an index in the output matrix, which cannot be done in 2 for loops.
*/
void matMultDyn(const DynMat & matA, const DynMat & matB,DynMat & matC, int size){
		
	//O(N^3) time complexity
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++ ){
			for(int k = 0; k < size; k++){
				matC[i][j] += ( matA[i][k] * matB[k][j] );
			}
		}
	}
}









/*
This function prints out a square sub-matrix of a matrix, from
the start position to the intended size of indices away from the start position
*/
void matShowDyn(const DynMat & matA, int start, int size){

	
	for (int row = start; row < (start + size); row++){
		for (int col = start; col < (start + size) ; col++){
			cout << setprecision(2) << fixed << matA[row][col] << "  ";
		}
		cout << "\n";
	}
	
	cout << "\n\n";
}


/*
Test run:

0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.15  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.28  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.41  0.00  0.00  0.00  0.26  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.98  0.00  0.00  0.00  0.00  0.83  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.42  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.35  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.81  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00


0.00  0.05  0.00  0.00  0.29  0.06  0.00  0.00  0.00  0.04  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.10  0.05  0.00  0.00  0.05  0.00  0.00  0.00  1.44  0.05  0.00  0.35  0.46
0.00  0.00  0.00  0.00  0.37  0.77  0.00  0.00  0.30  0.10  0.56  0.39  0.00  0.20  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.26  0.00  0.34  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.08  0.00  0.00  0.00  0.00  0.37  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.45  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.17  0.00  0.09  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.11  0.00  0.00
0.00  0.41  0.00  0.00  0.00  0.12  0.00  0.56  0.00  0.00  0.10  0.00  0.00  0.00  0.38
0.00  0.00  0.00  0.62  0.34  0.00  0.00  0.00  0.00  0.05  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.20  0.00  0.00  0.14  0.11  0.93  0.00  0.09  0.00  0.00  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.49  0.38  0.00  0.00  0.00  0.18  0.00  0.07  0.56  0.00
0.00  0.00  0.00  0.26  0.00  0.00  0.25  1.25  0.00  0.00  0.73  0.00  0.00  0.39  0.47
0.00  0.00  0.00  0.00  0.00  0.47  0.00  0.00  0.18  0.00  0.00  0.23  0.00  0.00  0.00
0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00  0.00



Size = 99 Dyn Array Mult Elapsed Time: 0.01 seconds.

*/
