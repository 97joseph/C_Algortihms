/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/9/2016

File name: a3_2.cpp (assignment 3, part 2)

Description: This program uses decsision
			 control flow including else-if
			 statements to handle several cases of 
			 decsision making. The objective is to determine what
			 stage of education the user has completed depending on
			 the number of years spent in school. The "and" logic
			 gate is used in the if statements to describe joint
			 conditions for the upper and lower bounds of education
			 levels.

*/
#include <iostream>
#include <iomanip>

using namespace std;

const int LOWER_ELEMENTARY = 1;
const int UPPER_ELEMENTARY = 6;
const int LOWER_MIDDLE_SCHOOL = 7;
const int UPPER_MIDDLE_SCHOOL = 8;
const int LOWER_HIGH_SCHOOL = 9;
const int UPPER_HIGH_SCHOOL = 12;

int main() {
	
	int years_of_school;
	
	
	cout << "Enter the years of school: ";
	cin >> years_of_school;
	
	if (years_of_school < 0) {
		
		cout << "Years of school must be a non-negative integer." << endl;
	}
	
	else if (years_of_school == 0) {
		
		cout << "No school" << endl;
	}
	
	else if ((years_of_school >= LOWER_ELEMENTARY) and
	(years_of_school <= UPPER_ELEMENTARY )) {
		
		cout << "Elementary school" << endl;
	}
	
	else if ((years_of_school >= LOWER_MIDDLE_SCHOOL) and
	(years_of_school <= UPPER_MIDDLE_SCHOOL )) {
	 	
		cout << "Middle school" << endl;
	}
	
	else if ((years_of_school >= LOWER_HIGH_SCHOOL) and
	(years_of_school <= UPPER_HIGH_SCHOOL )) {
		
		cout << "High school" << endl;
	}
	
	//Assuming only numbers will be entered.
	else  {
		cout << "College" << endl;
	}


	return 0;
}


/*
Output:
Enter the years of school: 9
High school
*/
