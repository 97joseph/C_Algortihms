/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/9/2016

File name: a4_1.cpp (assignment 4, part 1)

Description: This program, uses a question-type loop that allows the user to repeatedly
			 convert pounds to ounces. The user is allowed to
			 not enter any weights to convert and quit the program
			 from the first input. The user can do this by not inputting "Y"
			 when asked if they want to convert at the start of the program since
			 this is the condition for the while loop. The user can choose to convert
			 weights at the end of every iteration, since the prompt is at the end
			 of the loop. This ensures no other tasks are carried out if the user
			 doesn't want to continue and won't give any output.
			 
			 

*/
#include <iostream>

using namespace std;


int main() {

	int num_of_pounds;
	int num_of_ounces;
	char response;
	
	cout << "Do you want to convert an object\'s weight from pounds to ounces (Y/N)?";
    cin >> response;
	
	while (response == 'Y') {
	
		cout << "Enter pounds: ";
		cin >> num_of_pounds;
		
		num_of_ounces = num_of_pounds * 16;
		
		cout << num_of_pounds << " pounds is "
			 << num_of_ounces << " ounces." << endl;
			 
		
		cout << "\nDo you want to convert another weight from pounds to ounces (Y/N)?";    
	    cin >> response;
	
	}
	
	
	return 0;
}


/*
Do you want to convert an object's weight from pounds to ounces (Y/N)?Y
Enter pounds: 10
10 pounds is 160 ounces.

Do you want to convert another weight from pounds to ounces (Y/N)?N

*/

