/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/9/2016

File name: a3_3.cpp (assignment 3, part 3)

Description: This program acts as a simple calculator
			 that can only add, subtract, multiply and divide.
			 The user inputs two numbers and an operator.
			 The switch statement determines the equation
			 used to get the answer, using the chosernOperator
			 variable,  and assign it to the "answer" variable.
			 The cout statement then prints the answer out to 
			 2 decimal places.

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	
	double firstNumber;
	char chosenOperator;
	double secondNumber;
	double answer;
	
	cout << "Enter the first number: ";
	cin >> firstNumber;
	
	cout << "Enter the operator: ";
	cin >> chosenOperator;
	
	cout << "Enter the second number: ";
	cin >> secondNumber;
	
	
	switch (chosenOperator) {
		
		case '+' :
			answer = firstNumber + secondNumber;
			break;
		
		case '-' :
			answer = firstNumber - secondNumber;
			break;
		
		case 'x' : //lowercase 'x'
			answer = firstNumber * secondNumber;
			break;
		
		case '/' :
			answer = firstNumber / secondNumber;
			break;
			
	}
	
	cout << fixed << setprecision(2) << "The answer is " << answer << endl;

	return 0;
}



/*
Output:
Enter the first number: 5.5
Enter the operator: x
Enter the second number: 10.1
The answer is 55.55
*/
