g/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/12/2016

File name: a5_3.cpp (assignment 5, part 3)

Description: This program counts the words in files of several types.
			 The user is allowed to exit the program the first time
			 the user is asked for input and at the end of every
			 iteration. The first if statement displays an error message
			 if the file couldn't be opened, if it can be opened the else
			 statement contatins a while loop that will read every word
			 seperated by a space in the file and increment the count variable
			 at every iteration/word. The stream is then cleared and closed after
			 every iteration of the outter while loop so that other files can be read
			 from. 

*/

#include <iostream>
#include <fstream>

using namespace std;



int main() {
	
	
	int count;
	string fileName;
	string word;
	ifstream infile;
	
	cout << "Enter the name of a file (or enter \"quit\"): ";
	cin >> fileName;
	
	while (fileName != "quit") {
		
		infile.open((fileName).c_str());
		
		if (!infile) {
			cout << "couldn't open file." << endl;
		}
		
		else {

			count = 0;
		    infile >> word;    	
		    
		    while (infile){                    
		        infile >> word;
		        count++;
    		}	
		  }
	

		infile.clear();
		infile.close();
		
		cout << "The number of words in this file is " << count << endl;
		
		cout << "\nEnter the name of a file (or enter \"quit\"): ";
		cin >> fileName;
  }
}

/*
Output:

Enter the name of a file (or enter "quit"): file1.txt
The number of words in this file is 7

Enter the name of a file (or enter "quit"): file2.txt
The number of words in this file is 10

Enter the name of a file (or enter "quit"): file3.txt
The number of words in this file is 21

Enter the name of a file (or enter "quit"): file4.txt
The number of words in this file is 19

Enter the name of a file (or enter "quit"): file5.txt
The number of words in this file is 22

Enter the name of a file (or enter "quit"): quit


*/

