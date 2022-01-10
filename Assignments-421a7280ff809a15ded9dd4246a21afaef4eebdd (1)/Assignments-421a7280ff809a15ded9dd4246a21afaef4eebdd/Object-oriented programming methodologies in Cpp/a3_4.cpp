/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/9/2016

File name: a3_4.cpp (assignment 3, part 4)

Description: This program finds the Net cost of
			 a phone call using a specific rate structure.
			 Constants for the rate per minute and the discount
			 start and end times are declared globally. The user is 
			 prompted to enter the start time and call length. The is used
			 to determine the gross cost of the call. The netCost variable is also
			 assigned to the value of the gross cost so the value can be modified
			 after discounts to find the true net cost. if statements are used to
			 determine if the user gets a 50% and 15% discount. Finally, the tax is
			 always added so no if statement is required. Then the net cost is displayed.

*/
#include <iostream>
#include <iomanip>

using namespace std;

const double RATE_PER_MINUTE = 0.4;
const int DISCOUNT_START_TIME = 1800;
const int DISCOUNT_END_TIME = 800;



int main() {
	
	int callStartTime;
	int callLength;
	double grossCost;
	double netCost;
	
	cout << "Enter start time: ";
	cin >> callStartTime;
	
	cout << "Enter length of call in minutes: ";
	cin >> callLength;

	netCost = grossCost = callLength * RATE_PER_MINUTE;
	cout << fixed << setprecision(2) << "Gross cost: $" << grossCost << endl;
	
	//Nesting has been avoided in order to not repeat code.
	if ((callStartTime >= DISCOUNT_START_TIME) or (callStartTime < DISCOUNT_END_TIME)) {
		
		netCost *= 0.5;
	}
	
	if (callLength > 60) {
		
		netCost *= 0.85;
	}
	
	
	netCost *= 1.04;
	cout << fixed << setprecision(2) << "Net cost: $" << netCost << endl;


	return 0;
}

/*
Sample output 1 (as in example):
Enter start time: 1300
Enter length of call in minutes: 100    
gross cost: $40.00
net cost: $35.36

Sample output 2:
Enter start time: 2000
Enter length of call in minutes: 20
Gross cost: $8.00
Net cost: $4.16

Sample output 3:
Enter start time: 1900
Enter length of call in minutes: 59
Gross cost: $23.60
Net cost: $12.27

Sample output 4:
Enter start time: 1200
Enter length of call in minutes: 67
Gross cost: $26.80
Net cost: $23.69

*/
