/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/9/2016

File name: a3_1.cpp (assignment 3, part 1)

Description: This program makes use of control flow, more
			 specifically if-else statements. The area of
			 2 shapes are calculated, a square or a triangle.
			 The user is prompted to to input the character
			 that corresponds to the shape. The if statement
			 decision control flow decides which shape's area
			 formula should be used. Finally, the  cout statement
			 display the output with the area to 1 decimal place.
			 

*/
#include <iostream>
#include <iomanip>

using namespace std;


int main() {
	
	char figureType;
	double square_side;
	double triangle_base;
	double triangle_height;
	double area;
	
	
	cout << "Enter the type of figure (s or t): ";
	cin >> figureType;
	
	// double quotes wouldn't work in the if statement's condition, produced an error.
	if (figureType == 's') {
		cout << "Enter the length of a side: ";
		cin >> square_side;
		
		area = square_side * square_side;	
	}
	
	//Assuming only 2 options will ever be inputted.
	else {
		
		cout << "Enter the base: ";
		cin >> triangle_base;
		
		cout << "Enter the height: ";
		cin >> triangle_height;
		
		area = 0.5 * triangle_height * triangle_base;
		
	}
		 
	cout << fixed << setprecision(1) << "The area is " << area << endl;
	
	
	return 0;
}





/*

Sample output 1:

Enter the type of figure (s or t): s
Enter the length of a side: 5
The area is 25.0

Sample output 2: 

Enter the type of figure (s or t): t
Enter the base: 5
Enter the height: 2
The area is 5.0
*/
