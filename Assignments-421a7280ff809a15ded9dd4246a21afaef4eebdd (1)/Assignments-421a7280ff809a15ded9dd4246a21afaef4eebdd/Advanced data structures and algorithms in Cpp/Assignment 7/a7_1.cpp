#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h> 
#include <time.h>
#include "FHvector.h"


using namespace std;

#define ARRAY_SIZE 100000
#define SEDGEWICK_ARRAY_SIZE 30
#define OWN_GAP_SEQUENCE_ARRAY_SIZE 30

/*
Name: Dillon Pinto
Assignment: a7_1
date: 11/16/2016

Description: This program evaluates the performance of
			 different gap sequences on shell sort functions.
			 There are 2 global functions, shellSort1 and 
			 shellSortX that are used to implicitly and
			 explicitly test different gap sequences.
			 In this case 4 gap sequences are being tested.



*/




   

// shellSort #1 -- using shell's outer loop
template <typename Comparable>
void shellSort1( FHvector<Comparable> & a ) {
	
   int k, pos, arraySize, gap;
   Comparable tmp;
    
   arraySize = a.size();
   for (gap = arraySize/2;  gap > 0;  gap /= 2)  // outer gap loop
      for( pos = gap ; pos < arraySize; pos++ )  // middle loop (outer of "insertion-sort")
      {
         tmp = a[pos];
         for(k = pos; k >= gap && tmp < a[k - gap]; k -= gap )   // inner loop
            a[k] = a[k - gap];
         a[k] = tmp;
   }
}


// shellSortX
/*
This is a modified version of shellSort1 that accomodates a pre-calculated gap sequence
and gap size as opposed to shellSort1's implicit gap sequence that divides by 2 on each
pass.
*/
template <typename Comparable>
void shellSortX(FHvector<Comparable>& SortArray, unsigned int gapSequence[], int gapSequenceSize){
	
	unsigned int i, k, pos, arraySize, gap;
	Comparable tmp;
	
	arraySize = SortArray.size();
	
	for ( i =0 ;  i < gapSequenceSize;  i++){  // outer gap loop
		gap = gapSequence[gapSequenceSize-1-i];
		
		for( pos = gap ; pos < arraySize; pos++ ){  // middle loop (outer of "insertion-sort")
		
			tmp = SortArray[pos];
			for(k = pos; k >= gap && tmp < SortArray[k - gap]; k -= gap ){  
				SortArray[k] = SortArray[k - gap];
			}
			
		SortArray[k] = tmp;
		}
	}
}


int main(){
	
	//One array of random ints for each sort
	FHvector<int> fhVectorOfInts1;
	FHvector<int> fhVectorOfInts2;
	FHvector<int> fhVectorOfInts3;
	FHvector<int> fhVectorOfInts4;
	int i;
	int randomNumber;
	int k1=0;
	int k2=0;
	srand(time(NULL));
	
	clock_t startTime, endTime;
	
	
	//------------------------Gap sequences---------------------------------------
	
	unsigned int gapArray[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
	  2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288,
	  1048576};
	int gapArraySize = (sizeof(gapArray)/sizeof(*gapArray));
	  
	  
	  
	  
	
	
	  
	unsigned int sedgewickArray[SEDGEWICK_ARRAY_SIZE];

	
	for(i = 0; i < SEDGEWICK_ARRAY_SIZE; i++){
		
		if(i % 2 == 0){
			
			sedgewickArray[i] = 9*(pow(4,k1) - pow(2,k1)) + 1;
			k1++;
		}
		else{
			sedgewickArray[i] = pow(2,k2 + 2)*(pow(2,k2 + 2) -3) + 1;
			k2++;
		}
		cout << sedgewickArray[i] << endl;
}
	
	
	
	
	
	unsigned int ownGapArray[OWN_GAP_SEQUENCE_ARRAY_SIZE];
	for(i=0; i < OWN_GAP_SEQUENCE_ARRAY_SIZE; i++){
		ownGapArray[i] =  (pow(i,4)) + pow(3,i) + 1;//From trial and error, I've found that the plus 1 is needed as a gap size to sort smaller
		//numbers when i=0
	}

	
	
	//----------------------------------------------------------------------------------
	
	
	
	
	
	
	//Random values in each array to be sorted.
	for(i=0; i < ARRAY_SIZE; i++){
		randomNumber = rand() % ARRAY_SIZE;
		fhVectorOfInts1.push_back(randomNumber);
		fhVectorOfInts2.push_back(randomNumber);
		fhVectorOfInts3.push_back(randomNumber);
		fhVectorOfInts4.push_back(randomNumber);
		
	}
	
	
	
	
	
	
	
	
	//Implicit Shell Sort
	startTime = clock();
	shellSort1(fhVectorOfInts1);
	endTime = clock();
	  
	cout << "Total sort-time(Implicit): "
		 << ((double)endTime - (double)startTime) / (double)CLOCKS_PER_SEC
		 << " s\n" << endl;
	
	

	  
	  
	 
	 
	//Explicit shell sort
	startTime = clock();
	shellSortX(fhVectorOfInts2, gapArray, gapArraySize);  
	endTime = clock();
	
	cout << "Total sort-time(Explicit): "
		 << (double)(endTime - startTime) / (double)CLOCKS_PER_SEC
		 << " s\n" << endl;
	

	
	
	
	
	
	
	
	
	//Sedgewick gap sequence
	startTime = clock();
	shellSortX(fhVectorOfInts3, sedgewickArray, SEDGEWICK_ARRAY_SIZE ); 
	endTime = clock();
	
	
	cout << "Total sort-time(Sedgewick): "
		 << (double)(endTime - startTime) / (double)CLOCKS_PER_SEC
		 << " s\n" << endl;
	
	
	
	
	
	
	
	
	//Own/made up gap sequence - shell sort
	startTime = clock();
	shellSortX(fhVectorOfInts4, ownGapArray, OWN_GAP_SEQUENCE_ARRAY_SIZE);  
	endTime = clock();
	
	cout << "Total sort-time(Own gap sequence): "
		 << (double)(endTime - startTime) / (double)CLOCKS_PER_SEC
		 << " s\n" << endl;
	
	

}


/*

	Array size| Implpicit shellSort | Explicit shellSort | Sedgewick shellsort | Own(made up gap sequence) shellSort
1)	10,000			0.004s					0.008s				0.004s					0.003s
2)	20,000			0.008s					0.02 s				0.008s					0.006s	
3)	50,000			0.028s					0.065s				0.021s					0.019s
4)	100,000			0.06s					0.181s				0.041s					0.038s
5)	150,000			0.083s					0.36s				0.061s					0.058s
6)	200,000			0.122s					0.67s				0.082s					0.079s
	
	500,000			0.339s					1.646s				0.217s					0.211s
	^To show difference in made up gap sequence vs Sedgewick's for larger data sets
	^^Formula for gap sequence found from trial and error.




Answer:
Implict shellSort is shown to be much faster than the explicit shellSortX.
The explicit shellSortX runs slower than the implict shellSort1 because
the explicit sort would decrement gaps by powers of 2(i.e ...16, 8, 4, 2, 1) on each pass
therefore the last pass would be the only odd pass in the entire sort so odd
and even positions don't mix until then. Whereas in the implict shellSort1, there are
odd and even gaps throughout the sequence which means that odd and even positions can be
sorted/"mixed" before the final pass.







Test run ARRAY_SIZE = 500,000 :

Total sort-time(Implicit): 0.339 s

Total sort-time(Explicit): 1.646 s

Total sort-time(Sedgewick): 0.217 s

Total sort-time(Own gap sequence): 0.211 s


--------------------------------
Process exited after 2.479 seconds with return value 0
Press any key to continue . . .



*/

