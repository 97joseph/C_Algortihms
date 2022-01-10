/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/9/2016

File name: a4_2.cpp (assignment 4, part 2)

Description: This program, uses a special-value-type loop that allows the user
 			 to repeatedly convert pounds to ounces. This program is identical
			 to the one in 4.1. But uses the special-value-type loop instead. This
			 allows the user to quit using a "special value" at any point without a
			 confirmation question asking if the user wants to continue. In this case
			 the special value is in the form of negative numbers. The user will need to
			 input a negative number to quit the program.
*/
#include <iostream>

using namespace std;


int main() {

	int num_of_pounds;
	int num_of_ounces;
	char response;
	
	cout << "Enter pounds (enter a negative number to quit): ";
	cin >> num_of_pounds;
	
	while (num_of_pounds > 0) {
	
		num_of_ounces= num_of_pounds * 16;
		
		cout << num_of_pounds << " pounds is "
			 << num_of_ounces << " ounces." << endl;
			 
		
		cout << "Enter pounds (enter a negative number to quit): ";
		cin >> num_of_pounds;
	
	}
	
	
	return 0;
}

/*
Enter pounds (enter a negative number to quit): 10
10 pounds is 160 ounces.
Enter pounds (enter a negative number to quit): -2
*/
