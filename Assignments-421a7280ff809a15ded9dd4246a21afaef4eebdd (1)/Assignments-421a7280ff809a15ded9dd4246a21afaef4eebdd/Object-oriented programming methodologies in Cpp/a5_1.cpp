/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/12/2016

File name: a5_1.cpp (assignment 5, part 1)

Description: This program makes use of for loops and
			  other control flow to find the first and last
			 position of a specific number that's inputted
			 in a list of other numbers. The first and last instance
			 position variables are set to -1 for use later in the 
			 program to check if the first and last 7 has been found.
			 The for loop will iterate the amount of times that the user inputs.
			 And accepts as many numbers in a list. If the number has been found,
			 the first instance variable will be checked, if the number -1 has been
			 assigned to them. If so, the first instance variable will be assigned
			 the possition, and if not, the second variable will be assigned that
			 position. The last branch of if statements check if any instances of
			 the number have been found and outputs where or that there were no
			 instances.

*/
#include <iostream>

using namespace std;

const int NUMBER_TO_FIND = 7;


int main() {

	int number_of_iterations;
	int count;
	int number_input;
	int first_instance_position = -1;
	int last_instance_position = -1;
	
	cout << "How many numbers will be entered? ";
	cin >> number_of_iterations;
	
	for (count = 0; count < number_of_iterations; count++){
		cout << "Enter num: ";
		cin >> number_input;
		
		if (number_input == NUMBER_TO_FIND) {
			if (first_instance_position ==
			 -1) {
				first_instance_position = count + 1;
			}
			
			else {
				last_instance_position = count + 1;  
			}
		}	
	}
	
	
	if (first_instance_position != -1) {
		cout << "The first 7 was in position " << first_instance_position << endl;
		
		if (last_instance_position != -1) {
			cout << "The last 7 was in position " << last_instance_position << endl;
		}
		
		else {
			cout << "The last 7 was in position " << first_instance_position << endl;
		}
	}
	
	else {
		cout << "Sorry, no 7's were entered." << endl;
	}
	

	
	return 0;
}


/*
Output 1:
How many numbers will be entered? 8
Enter num: 5
Enter num: 7
Enter num: 6
Enter num: 7
Enter num: 7
Enter num: 3
Enter num: 8
Enter num: 6
The first 7 was in position 2
The last 7 was in position 5

Output 2:
How many numbers will be entered? 8
Enter num: 5
Enter num: 2
Enter num: 6
Enter num: 7
Enter num: 1
Enter num: 3
Enter num: 8
Enter num: 6
The first 7 was in position 4
The last 7 was in position 4

Output 3:
How many numbers will be entered? 8
Enter num: 5
Enter num: 1
Enter num: 6
Enter num: 5
Enter num: 9
Enter num: 3
Enter num: 8
Enter num: 6
Sorry, no 7's were entered.

*/

