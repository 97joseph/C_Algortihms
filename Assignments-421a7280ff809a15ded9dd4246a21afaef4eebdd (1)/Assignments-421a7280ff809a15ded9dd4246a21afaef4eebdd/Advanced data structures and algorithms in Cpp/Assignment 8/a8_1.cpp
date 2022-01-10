#include <iostream>
#include "FHsort.h"
#include "FHvector.h"
#include <cstdlib>
#include <time.h>


using namespace std;

/*
Name: Dillon Pinto
Description: This program tests a function, quickSortX
			 and investigates the use of recursion limits
			 and time complexity of the function.
*/


// quickSort internal
template <typename Comparable>
void quickSortX(FHvector<Comparable> & a, int left, int right, int recursion_limit)
{
   Comparable pivot;
   int i, j;

   if( left + recursion_limit <= right )
   {
      pivot = median3(a, left, right);
      for( i = left, j = right - 1; ; )
      {
         while( a[++i] < pivot )
            ;
         while( pivot < a[--j] )
            ;
         if( i < j )
            mySwapFH(a[i], a[j]);
         else
            break;
      }

      mySwapFH(a[i], a[right - 1]);  // restore pivot

      // recursive calls on smaller sub-groups
      quickSortX(a, left, i - 1, recursion_limit);     
      quickSortX(a, i + 1, right,recursion_limit);    
   }
   else
      // non-recursive escape valve - insertionSort
      insertionSort(a, left, right);
}




// quickSort public driver
template <typename Comparable>
void quickSortX( FHvector<Comparable> & Sort_Array, int rec_limit )
{
	if(rec_limit < 2){
		rec_limit = 2;
	}
    quickSortX(Sort_Array, 0, Sort_Array.size() - 1, rec_limit);
}






/*
This function clears and fills up the vector to the current
array size on a particular iteration.
*/
template <typename Comparable>
void fillVector( FHvector<Comparable> & vec, int array_size)
{
	vec.clear();
    for(int i=0; i < array_size; i++){
	vec.push_back(rand() % array_size);
	}
}








int main(){
	
	
	
	FHvector<int> fhVectorOfInts;
	int i;
	clock_t startTime, endTime;
	srand(time(NULL)); 
	
	
	
	for(int displayArraySize=50000; displayArraySize <= 250000; displayArraySize+=50000){
		cout << "\nArray size: " << displayArraySize 
			 << "\nRecursion limit | Sort-time" << endl;
		for(i=2; i <= 300; i+=8){
			
			fillVector(fhVectorOfInts, displayArraySize);
			
			startTime = clock();
			quickSortX(fhVectorOfInts, i);
			endTime = clock();
		
		
			cout << "    "<< i<< "\t\t   "
				 << (double)(endTime - startTime) / (double)CLOCKS_PER_SEC
				 << " s" << endl;
		
		
		}
	}
	
}


/*
The tables below show a test run for array sizes from 50,000 to 250,000
integers in an "array".
The general trend in the data shows a slow but steady increase in sort times
as the recursion limit increases, thus showing a directly proportional relationship
between Recursion limits and sort times.

For recursion limits with a difference of 8 as shown below, sort times stayed
relatively close from limits that ranged between 2-42, 50-82, 90-154 and then
steadily increased from recursion limits greater than 154.
Sort times remained flatest with recursion limits less than 50, showing not a
large, if any, difference in sort times.

Array size: 50000
Recursion limit | Sort-time
    2              0.008 s
    10             0.009 s
    18             0.009 s
    26             0.009 s
    34             0.009 s
    42             0.009 s
    50             0.01 s
    58             0.011 s
    66             0.011 s
    74             0.012 s
    82             0.013 s
    90             0.014 s
    98             0.031 s
    106            0.014 s
    114            0.015 s
    122            0.015 s
    130            0.016 s
    138            0.017 s
    146            0.017 s
    154            0.017 s
    162            0.018 s
    170            0.021 s
    178            0.02 s
    186            0.02 s
    194            0.021 s
    202            0.022 s
    210            0.023 s
    218            0.023 s
    226            0.024 s
    234            0.024 s
    242            0.025 s
    250            0.026 s
    258            0.027 s
    266            0.027 s
    274            0.027 s
    282            0.028 s
    290            0.028 s
    298            0.029 s

Array size: 100000
Recursion limit | Sort-time
    2              0.018 s
    10             0.017 s
    18             0.018 s
    26             0.019 s
    34             0.019 s
    42             0.021 s
    50             0.021 s
    58             0.022 s
    66             0.024 s
    74             0.024 s
    82             0.025 s
    90             0.027 s
    98             0.028 s
    106            0.029 s
    114            0.03 s
    122            0.032 s
    130            0.033 s
    138            0.034 s
    146            0.035 s
    154            0.036 s
    162            0.037 s
    170            0.041 s
    178            0.04 s
    186            0.041 s
    194            0.042 s
    202            0.044 s
    210            0.045 s
    218            0.047 s
    226            0.048 s
    234            0.049 s
    242            0.049 s
    250            0.05 s
    258            0.053 s
    266            0.055 s
    274            0.055 s
    282            0.056 s
    290            0.059 s
    298            0.059 s

Array size: 150000
Recursion limit | Sort-time
    2              0.028 s
    10             0.027 s
    18             0.028 s
    26             0.028 s
    34             0.029 s
    42             0.031 s
    50             0.032 s
    58             0.033 s
    66             0.036 s
    74             0.037 s
    82             0.038 s
    90             0.04 s
    98             0.043 s
    106            0.044 s
    114            0.046 s
    122            0.049 s
    130            0.049 s
    138            0.051 s
    146            0.053 s
    154            0.055 s
    162            0.057 s
    170            0.059 s
    178            0.06 s
    186            0.062 s
    194            0.064 s
    202            0.066 s
    210            0.068 s
    218            0.069 s
    226            0.072 s
    234            0.073 s
    242            0.075 s
    250            0.077 s
    258            0.079 s
    266            0.081 s
    274            0.083 s
    282            0.085 s
    290            0.087 s
    298            0.087 s

Array size: 200000
Recursion limit | Sort-time
    2              0.038 s
    10             0.036 s
    18             0.036 s
    26             0.037 s
    34             0.039 s
    42             0.042 s
    50             0.044 s
    58             0.046 s
    66             0.047 s
    74             0.05 s
    82             0.052 s
    90             0.054 s
    98             0.056 s
    106            0.059 s
    114            0.061 s
    122            0.063 s
    130            0.066 s
    138            0.068 s
    146            0.071 s
    154            0.074 s
    162            0.076 s
    170            0.078 s
    178            0.081 s
    186            0.083 s
    194            0.086 s
    202            0.088 s
    210            0.092 s
    218            0.093 s
    226            0.096 s
    234            0.097 s
    242            0.1 s
    250            0.103 s
    258            0.105 s
    266            0.108 s
    274            0.111 s
    282            0.113 s
    290            0.116 s
    298            0.118 s

Array size: 250000
Recursion limit | Sort-time
    2              0.047 s
    10             0.046 s
    18             0.046 s
    26             0.048 s
    34             0.05 s
    42             0.051 s
    50             0.054 s
    58             0.057 s
    66             0.059 s
    74             0.062 s
    82             0.065 s
    90             0.067 s
    98             0.071 s
    106            0.074 s
    114            0.077 s
    122            0.079 s
    130            0.084 s
    138            0.086 s
    146            0.089 s
    154            0.091 s
    162            0.095 s
    170            0.097 s
    178            0.102 s
    186            0.104 s
    194            0.107 s
    202            0.109 s
    210            0.112 s
    218            0.117 s
    226            0.119 s
    234            0.123 s
    242            0.125 s
    250            0.129 s
    258            0.133 s
    266            0.134 s
    274            0.138 s
    282            0.14 s
    290            0.145 s
    298            0.149 s

--------------------------------
*/
