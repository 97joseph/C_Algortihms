/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/8/2016

File name: a2_2.cpp (assignment 2, part 2)

Description: This program converts the temperature from Celsius to
			 Farenheit. The output variable will always be a truncated
			 value. For the sake of accuracy, it is allowed to
			 enter the temperature in Celsius as a double/number with decimals.
			 This ensures that an accurate value is calculated and the accurate
			 value will be truncated. As opposed to truncating the input variable and
			 the output variable.
			 The fraction 9/5 will be truncated to the value of 1 since it doesn't
			 imply floating point division, this is why the double keyword is added
			 next to it, making it a float/doubble expression.
			 The final output cout statement outputs the temperature in Farenheit.
*/

#include <iostream>

using namespace std;


int main() {

	int tempFarenheit;
	double tempCelsius;
	
	cout << "enter degrees Celsius: ";
	cin >> tempCelsius;
	
	//The temperature in farenheit will be truncated.
	tempFarenheit = ( ( (double) 9 / 5) * tempCelsius) + 32;
	
	
	cout << tempCelsius << " degrees Celsius is "
		 << tempFarenheit << " degrees Farenheit." << endl;
	
	
	return 0;
}



/*
Output:
enter degrees Celsius: 32.3
32.3 degrees  Celsius is 90 degrees Farenheit.

*/

//Note: Without truncation, the answer is 90.14 (2 d.p)
