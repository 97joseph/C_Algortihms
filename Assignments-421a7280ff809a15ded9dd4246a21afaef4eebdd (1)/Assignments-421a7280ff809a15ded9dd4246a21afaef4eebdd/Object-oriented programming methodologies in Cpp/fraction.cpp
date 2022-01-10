#include <iostream>
#include "fraction.h"
using namespace std;


//Class invariant:
/*
There are 2 private data members in this class "numerator and 
denominator. These 2 data members make up the fraction in each
fraction object. 0 and 1 are assigned to them in case of a default
constructor but the default constructor isn't used in the client program
so the non-default constructor is used to assign values to the data members.
Since the simplpfy function is in the default constructor, fraction objects
will always be in their lowest terms. Divide by 0 errors won't occur using
the default constructor.
*/



/*
Default constructor that assigns 0 to the numerator and 1 to the
denominator so the fraction equals 0 without causing a divide by
0 error.
*/
fraction::fraction() {
	numerator = 0;
	denominator = 1;
}





/*
Non-default constructor that takes 2 parameters/arguments "frac_numerator" and
"frac_denominator" of type int. The "frac_numerator" parameter is assigned to
the "numerator" data member and the "frac_denominator" parameter is assigned to
the "denominator" data member. Then as soon as those values are assigned,
the "this" pointer calls the simplify function. This ensures that fractions
are simplified everytime a non-default fraction object is created. Fractions
created with the non-default constructor will always be simplified.
*/
fraction::fraction(int frac_numerator, int frac_denominator) {
	numerator = frac_numerator;
	denominator = frac_denominator;
	this->simplify();
}






/*
This function is called in the non-default constructor to simplify fractions in
every non-default fraction object. This function finds the GCF by first finding
the greatest number between the numerator and the deonminator and assigning this
value to the "count" variable so the while loop will iterate until the GCF is found
and then the numerator and denominator are both divided by the GCF.

*/
void fraction::simplify() {
	
	int greatest_number;
	int count;
	int greatest_common_factor = -1;
	
	if (numerator > denominator){
		greatest_number = numerator;
	}
	else {
		greatest_number = denominator;
	}
	
	count = greatest_number;
	
	while (greatest_common_factor == -1){
		if ((numerator % count==0) and (denominator % count==0)) {
			greatest_common_factor = count;
		}
		count--;//Not used again so it doesn't matter that the variable
				//is reduced by one after the GCF is found.
	}
	
	if (greatest_common_factor != -1){
		numerator /= greatest_common_factor;
		denominator /= greatest_common_factor;
	}
}



//Functions after this point are not complex so are not provided with
//detailed comments explaining how they work.


fraction fraction::addedTo(fraction second_fraction) const {
	
	int answer_numerator;
	int answer_denominator;
	
	answer_numerator = ( (numerator * second_fraction.denominator) +
						(second_fraction.numerator * denominator));
	answer_denominator = denominator * second_fraction.denominator;
	
	fraction answer(answer_numerator, answer_denominator);
	
	return answer;
}






fraction fraction::multipliedBy(fraction second_fraction) const {
	
	int answer_numerator;
	int answer_denominator;

	
	answer_numerator = numerator * second_fraction.numerator;
	answer_denominator = denominator * second_fraction.denominator;
	
	fraction answer(answer_numerator, answer_denominator);
	
	return answer;
}






fraction fraction::subtract(fraction second_fraction) const {
	
	int answer_numerator;
	int answer_denominator;
	
	answer_numerator = ((numerator * second_fraction.denominator) -
						(second_fraction.numerator * denominator));
	answer_denominator = denominator * second_fraction.denominator;
	
	fraction answer(answer_numerator, answer_denominator);
	
	return answer;
}






fraction fraction::dividedBy(fraction second_fraction) const {
	
	int answer_numerator;
	int answer_denominator;
	
	answer_numerator = numerator * second_fraction.denominator;
	answer_denominator = denominator * second_fraction.numerator;
	
	fraction answer(answer_numerator, answer_denominator);
	
	return answer;
}






void fraction::print() const {
	cout << numerator << "/" << denominator;
}






bool fraction::isEqualTo(fraction second_fraction) const {
	return ((numerator * second_fraction.denominator) ==
		(denominator * second_fraction.numerator));
}
