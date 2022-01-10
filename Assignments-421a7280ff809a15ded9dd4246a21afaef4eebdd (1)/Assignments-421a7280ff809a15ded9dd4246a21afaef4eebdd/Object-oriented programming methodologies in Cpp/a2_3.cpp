/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/8/2016

File name: a2_3.cpp (assignment 2, part 3)

Description: This program manipulates strings.
			 The cin statement in this program
			 takes the original inputted string and puts
			 each name string in its own variable.
			 The fullName variable consists of all 3
			 name strings concatenated with single spaces
			 between them.
			 In the cout statement, the first 3 lines print
			 out all 3 names. The 4th line prints the initials.
			 Single character substrings of the first letter of 
			 all 3 names are concatenated and printed. This is also
			 done in part 4, finding the 8th character/7th string index position.
			 The 8th character is a single character substring of the full name
			 at position 7 in the string (character array). The 3 letters of the
			 middle name is a 3 character long substring that's printed out.

*/
#include <iostream>

using namespace std;


int main() {
	
	string fullName;
	string firstName;
	string middleName;
	string lastName; 

	
	cout << "Enter a name in the format First Middle Last: ";
	cin >> firstName >> middleName >> lastName;
	
	fullName = firstName +  " " + middleName + " " + lastName;
	

	cout << firstName << endl
		 << middleName << endl
		 << lastName << endl
		 << firstName.substr(0,1) + middleName.substr(0,1) + lastName.substr(0,1) << endl
		 << middleName.substr(0,3) << endl
		 << fullName.substr(7,1) << endl
		 << fullName.length() << endl;
		 
	

	return 0;
}




/*
Output: 
Enter a name in the format First Middle Last: Jean Luc Picard
Jean
Luc
Picard
JLP
Luc
c
15

*/
