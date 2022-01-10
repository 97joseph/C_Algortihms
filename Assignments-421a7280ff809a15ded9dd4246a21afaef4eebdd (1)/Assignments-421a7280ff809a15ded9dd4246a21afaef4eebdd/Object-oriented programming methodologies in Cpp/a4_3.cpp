/*
Name: Dillon Pinto

Class: CS 2A

Date: 6/9/2016

File name: a4_1.cpp (assignment 4, part 3)

Description: This program is a simple user statistics system for a
			 movie theater. It takes in customers' ages and and food peferences
			 and summarizes it in a final output statement once the user is done
			 inputting the customers' ages and food preferences. Some variables
			 are set to increase or be summed together on every iteration. After
			 the user stops inputting customer details, the program will produce
			 a summary tallying ages, food preferences, average age, etc.
			 
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Constants decloared globally.
const int AGE_GROUP1 = 18;// age groups show upper age limit for each group
const int AGE_GROUP2 = 30;
const int AGE_GROUP3 = 40;
const int AGE_GROUP4 = 60; //a fifth age group is not required, see if statement below


int main() {

	
	int age_of_attendee;
	char food_preference;
	int popcorn_preference = 0; // The preference variables show how many people
	int soda_preference = 0; //    prefer either popcorn, soda or both.
	int both_popcorn_and_soda = 0;
	int sum_of_ages = 0;
	int total_number_of_attendees = 0;
	int oldest_attendee;
	int youngest_attendee;
	int attendees_in_group1 = 0; // Assigned to zero since it would add one to the age group.
	int attendees_in_group2 = 0; // All the "attendees in.." counter variables had undefined
	int attendees_in_group3 = 0; // behavior until they were initialized to 0.
	int attendees_in_group4 = 0 ;
	int attendees_in_senior_group = 0;



	cout << "Enter age of attendee (enter a negative number to quit): ";
	cin >> age_of_attendee;
	
	
	
	while (age_of_attendee >= 0) {
	
	
		cout << "Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): ";
		cin >> food_preference;
		
		if (total_number_of_attendees == 0) {
			oldest_attendee = age_of_attendee;
			youngest_attendee = age_of_attendee;
		}
		
		sum_of_ages += age_of_attendee;
		total_number_of_attendees++;
		
		if (age_of_attendee < youngest_attendee){
			youngest_attendee = age_of_attendee;
		}
		
		if (age_of_attendee > oldest_attendee){
			oldest_attendee = age_of_attendee;
		}
		
		
		
		
		// A greater than 0 condition was not required since the while statment's
		// condition handles that.
		if (age_of_attendee <= AGE_GROUP1) {
			attendees_in_group1++;
		}
		
		else if ( (age_of_attendee > AGE_GROUP1) and (age_of_attendee <= AGE_GROUP2) ) {
			attendees_in_group2++;
		}
		
		else if ( (age_of_attendee > AGE_GROUP2) and  (age_of_attendee <= AGE_GROUP3) ) {
			attendees_in_group3++;
		}
		
		else if ( (age_of_attendee > AGE_GROUP3) and (age_of_attendee <= AGE_GROUP4) ) {
			attendees_in_group4++;
		}
		
		/*
		Since the program will break if anything other than a number is inputted
		the else statement serves as the condition that doesn't meet any of the
		above conditions, i.e any number over 60.
		*/
		else {
			attendees_in_senior_group++;
		}
		
		
		//Assuming only any of the three options will ever be inputted.
		if (food_preference == 'p') { 
			popcorn_preference++;
		}
		
		else if (food_preference == 's') {
			soda_preference++;
		}
		
		else {
			both_popcorn_and_soda++;
		}

		cout << "Enter age of attendee (enter a negative number to quit): ";
		cin >> age_of_attendee;
	
	}
	
	//Prints if the user didn't quit the program on start up and entered attendees' info.
	if (total_number_of_attendees > 0){
	
		cout << "\nage 0  to 18: " << attendees_in_group1
			 << "\nage 19 to 30: " << attendees_in_group2
			 << "\nage 31 to 40: " << attendees_in_group3
			 << "\nage 41 to 60: " << attendees_in_group4
			 << "\nover 60: " << attendees_in_senior_group << endl;
		
		
		cout << fixed << setprecision(1)
			 << "\nfood preference popcorn: " << popcorn_preference
			 << "\nfood preference soda: " << soda_preference
			 << "\nfood preference both: " << both_popcorn_and_soda
			 << "\nThe average age was " << (double)sum_of_ages / total_number_of_attendees
			 << "\nThe youngest person in attendance was " << youngest_attendee
			 << "\nThe oldest person in attendance was " << oldest_attendee << endl;
	}
	
	else {
		
		cout << "There were no attendees so there are no statistics!" << endl;
	}
		 	 
		 
	return 0;
}


/*

Output: 
Enter age of attendee (enter a negative number to quit): 32
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): p
Enter age of attendee (enter a negative number to quit): 12
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
Enter age of attendee (enter a negative number to quit): 18
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
Enter age of attendee (enter a negative number to quit): 63
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
Enter age of attendee (enter a negative number to quit): 36
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
Enter age of attendee (enter a negative number to quit): 20
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): p
Enter age of attendee (enter a negative number to quit): 40
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
Enter age of attendee (enter a negative number to quit): 19
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): p
Enter age of attendee (enter a negative number to quit): -1

age 0  to 18: 2
age 19 to 30: 2
age 31 to 40: 3
age 41 to 60: 0
over 60: 1

food preference popcorn: 3
food preference soda: 2
food preference both: 3
The average age was 30.0
The youngest person in attendance was 12
The oldest person in attendance was 63
*/
