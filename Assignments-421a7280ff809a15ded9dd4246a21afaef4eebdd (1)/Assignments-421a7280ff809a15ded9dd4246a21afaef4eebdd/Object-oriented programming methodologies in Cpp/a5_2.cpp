/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/12/2016

File name: a5_2.cpp (assignment 5, part 2)

Description: This program calculates the sum of squares for numbers
			 grater than or equal to 1 and makes the use of both
			 for and while loops. The while loop used is a special-value type
			 loop used to keep asking the user to enter a number to calculate
			 the value of the sum of squares. If a number less than 1 is entered
			 the loop breaks/stops iterating. The sun_of_sqaures variable is set to 0
			 in every iteration of the while loop to make sure values from previous
			 iterations are not added in. The for loop uses the control variable
			 names "count", the value of count is squared and added to the sum_of_squares
			 variable on every iteration of the for loop. The answer is then outputted.
			 At the end of the while loop the user is asked again if they want to enter
			 more numbers, and if so, the while loop keeps iterating. The user also has
			 the option to quit at the start before entering any numbers to calculate,
			 this is done by asking the user for input immediately before the while loop.
			 

*/
#include <iostream>

using namespace std;



int main() {
	
	int upper_bound;
	int count;
	int sum_of_squares;
	
	
	cout << "Enter a number greater than 0 (less than 1 to quit): ";
	cin >> upper_bound;
	
	while (upper_bound > 0) {
	
		sum_of_squares = 0;
		
		for (count = 1; count <= upper_bound; count++){
			sum_of_squares += count * count;
		}
		
		cout << "The sum of the squares from 1 to "
			 << upper_bound << " is "
			 << sum_of_squares << endl;
			 
		
		cout << "Enter a number greater than 0 (less than 1 to quit): ";
		cin >> upper_bound;
		 
	}

	
	return 0;
}


/*
Output:
Enter a number greater than 0 (less than 1 to quit): 5
The sum of the squares from 1 to 5 is 55
Enter a number greater than 0 (less than 1 to quit): 2
The sum of the squares from 1 to 2 is 5
Enter a number greater than 0 (less than 1 to quit): 0

*/
