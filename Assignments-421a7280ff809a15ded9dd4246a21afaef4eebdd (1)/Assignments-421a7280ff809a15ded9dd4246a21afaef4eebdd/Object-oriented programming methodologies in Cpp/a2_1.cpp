/*

Name: Dillon Pinto

Class: CS 2A

Date: 6/8/2016

File name: a2_1.cpp (assignment 2, part 1)

Description: This program splits a certain amount of money,
             in cents, into quarters, dimes, nicekls and pennies.
			 This is generally done by using integer division to
			 truncate numbers and the modulus operator to find
			 the amount in cents remaining.
			 The cout/print statement asks the user to input an
			 amount in cents and the cin statement stores the input
			 in the total_amount_in_cents variable.
			 The first part of the amount to be split is into
			 quarters. Done by integer-dividing the total amount
			 by 25, the remaining amount in cents is found by using
			 the modulus operator by 25. The same is done for finding
			 the number of dimes, but uses a variable that holds the
			 remaining amount in cents, rather than the total amount.
			 To find the remaining amount after finding the amount of
			 dimes, the remaining_amount_in_cents variable is assigned
			 to the modulus by 10. Nickels are found by integer division
			 by 5 and the number of pennies is found by the modulus by 5
			 since the number of pennies can is never greater than 5.
			 The final output cout/print statement displays the amount
			 of each coin needed to split the total amount.

*/

#include <iostream>

using namespace std;

const int quarter = 25;
const int dime = 10;
const int nickel = 5;

int main() {

	//Variable declarations
	int total_amount_in_cents;
	int num_of_pennies;
	int num_of_nickels;
	int num_of_dimes;
	int num_of_quarters;
	int remaining_amount_in_cents;
		
	
	cout << "Enter the number of cents: ";
	cin >> total_amount_in_cents;
	
	
	num_of_quarters = total_amount_in_cents / quarter;
	remaining_amount_in_cents = total_amount_in_cents % quarter;
	
	
	num_of_dimes = remaining_amount_in_cents / dime;
	remaining_amount_in_cents = remaining_amount_in_cents % dime;
	
	
	num_of_nickels = remaining_amount_in_cents / nickel;
	
	num_of_pennies = remaining_amount_in_cents % nickel;
	
	cout << "pennies: " << num_of_pennies
		 << "\nnickels: " << num_of_nickels
		 << "\ndimes: " << num_of_dimes
		 << "\nquarters: " << num_of_quarters << endl;
	

	return 0;
}


/*
Enter the number of cents: 141
pennies: 1
nickels: 1
dimes: 1
quarters: 5

*/
