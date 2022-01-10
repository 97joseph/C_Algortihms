/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/16/2016

File name: a6_1.cpp (assignment 6, part 1)

Description: This program draws rockets of different
			 heights and widths. It is composed of 
			 several functions that draw different parts
			 of each stage of the program and the cones
			 at the top and bottom of the rocket.

*/

#include <iostream>
#include <fstream>

using namespace std;

//Function prototypes
int getDimensions(int &stage_height, int &stage_width,
				  int &number_of_stages);
void drawRocket( int stage_height, int stage_width, int number_of_stages);


/*
The main function calls the getDimensions
function to receive user input on the dimensions of
the rocket and then uses these dimensions to create
the rocket accordingly by passing them as arguments to
the drawRocket function.
*/
int main() {
	
	int stage_height;
	int stage_width;
	int number_of_stages;
	
	
	getDimensions(stage_height, stage_width, number_of_stages);
    drawRocket(stage_height, stage_width, number_of_stages);
}






/*
This function draws the odd version of the cone
shape using nested for loops and a formulaic method
to drawing it.
*/
void drawOddCone(int width, int midpoint){
	int row;
	int column;
	
	for (row = 0; row < midpoint; row++) {
		for (column = 0; column < width; column++) {
			
			if (column == midpoint - 1 and row == 0) {
            cout << "*";
        	}
	        else if (row > 0  and column == midpoint-row-1) {
	            cout << "*";
	    	}
	        else if (row > 0 and column == midpoint+row-1){
	            cout << "*";
			}
	        else {
	            cout << " ";
	    	}
		}
		cout << endl;
	}
}






/*
This function draws the even version of the cone shape
and makes use of almost identical formulas and a double asterisk
shaped tip for the cone. This is also drawn using nested for loops.
*/
void drawEvenCone(int width, int midpoint){
	int row;
	int column;
	
	
	for (row = 0; row < midpoint; row++) {
		for (column = 0; column < width; column++) {
			
			if (column == midpoint - 1 and row == 0) {
            cout << "**";
        	}
	        else if (row > 0 and column == midpoint-row-1) {
	            cout << "*";
	    	}
	        else if (row > 0 and column == midpoint+row){
	            cout << "*";
			}
	        else {
	            cout << " ";
	    	}
		}
		cout << endl;
	}
}




/*
This function calls both odd and even
versions of the drawCone function depending
on the user input. This solves the problem of the cone
not fitting in the original code description for the rocket.
The cone now fits on top and below the rocket regardless of
the width of its stages.
*/
void drawCone(int numSpaces) {
	
	int width;
	int midpoint;//Horizontal midpoint which is equal to the height.
	
	width = numSpaces;
	
	if (width % 2 == 0) {
		midpoint = (width / 2); 
		drawEvenCone(width,midpoint);
	}
	
	else {
		midpoint = (width / 2) + 1;
		drawOddCone(width, midpoint);
	}
	
}






/*
This function draws one one row in the each
of the stages of the rocket. This function can be called
multiple times to increase the stage height.
*/
void drawOneRow(int numSpaces) {
    int spaceCount;

    cout << "*";
    for (spaceCount = 0; spaceCount < numSpaces; spaceCount++){    
        cout << " ";
    }
    cout << "*" << endl;
}






/*
This function draws the horizontal lines at the
top and bottom of each stage and needs to be called
both times. The width of the horizontal line is user
defined.
*/
void drawHorizontalLine(int numXs) {               
        int count;

        for (count = 0; count < numXs; count++){
            cout << "*";
        }
        cout << endl;
}






/*
This function calls on the drawOneRow function
as many times as many times as appropriate for the user
defined height, to draw the vertical lines that make up
the two sides of each stage.
*/
void draw2VerticalLines(int numSpaces, int numRows) {                          
    int rowCount;

    for (rowCount = 0; rowCount < numRows; rowCount++){
        drawOneRow(numSpaces);
    }
}






/*
This function calls on 2 functions
to draw a box/stage of the rocket.
The drawHorizontalLine function is used
twice to draw the top and bottom horizontal lines
that makes up the stage borders, and the vertical lines function
is called in between the horizontal lines function to make up the
sides and height of the stage.
*/
void drawBox(int width, int height) {
	
	drawHorizontalLine(width);
    draw2VerticalLines(width - 2, height -2);
    drawHorizontalLine(width);
    
}






/*
This function calls on both drawBox and drawCone
functions to make up the rocket. The user inputs
the stage height and width and the number of stages.
The for loop generates as many stages as the user defines
for the height and width that the user defined.
The drawCone functions are called before and after the for loop
to form the top and the bottom of the rocket and also depend on
the user defined width.
*/
void drawRocket( int stage_height, int stage_width, int number_of_stages) {
	
	int count_stages;
	
	drawCone(stage_width);
	for (count_stages = 0; count_stages < number_of_stages; count_stages++) {
		drawBox(stage_width, stage_height);
	}
    drawCone(stage_width);
}






/*
This function collects user defined values for the 
stage height and width and the number of stages.
The arguments, when called are passed by reference so
they can be used in the drawRocket function.
*/
int getDimensions(int &stage_height, int &stage_width,
				  int &number_of_stages) {
	
	
	cout << "Enter the height of each stage: ";
	cin >> stage_height;
	
	cout << "Enter the width of each stage: ";
	cin >> stage_width;
	
	cout << "Enter the number of stages: ";
	cin >> number_of_stages;
}






/*
Output - odd width:
Enter the height of each stage: 6
Enter the width of each stage: 7
Enter the number of stages: 2
   *
  * *
 *   *
*     *
*******
*     *
*     *
*     *
*     *
*******
*******
*     *
*     *
*     *
*     *
*******
   *
  * *
 *   *
*     *

output - even width:
Enter the height of each stage: 6
Enter the width of each stage: 6
Enter the number of stages: 2
  **
 *  *
*    *
******
*    *
*    *
*    *
*    *
******
******
*    *
*    *
*    *
*    *
******
  **
 *  *
*    *

*/
