#ifndef FRACTION_H
#define FRACTION_H

/*
This class is used to create fractions by storing
a numerator and denominator as private data members. The fraction
class also lets arithmetic be performed on the calling object with
another object like multiplication, division, addition and subtraction
and allows the user to view the fraction or check if the fractions are
equal. The class also has a private member function that simplifies the calling
objects data members (explained in the implementation file).



fraction();
pre-conditions: No arguments must be given to the default constructor,
if 2 are given (2 integers) the non-default constructor will be used instead.
post-conditions: The object will store a numerator value of 0 and denominator
value of 1 giving the fraction an overall value of 0.



fraction(int frac_numerator, int frac_denominator);
pre-conditions: Two arguments will be passed into the non-default constructor
both of which are integers, the frac_numerator and frac_denominator. This is
used to create a fraction with a numerator and a denominator. The denominator
should not be a value of 0.
post-conditions:The object will store a simplified pair of integers if possible
to represent the numerator and denominator of the fraction.



fraction addedTo(fraction second_fraction) const;
pre-conditions: A fraction object should be passed into this
member function to add the calling object's numerator and denominator
to the numerator and denominator  of the object in the aegument/parameter.
post-conditions: The member function wil return an object which consists
of a simplified fraction of the addition of the fractions represented by
the calling object and the object passed to the function.



fraction subtract(fraction second_fraction) const;
pre-conditions: A fraction object should be passed into this
member function to subtract the calling object's numerator and denominator
from the numerator and denominator of the object in the aegument/parameter.
post-conditions: The member function wil return an object which consists
of a simplified fraction of the subtraction of the fractions represented by
the calling object and the object passed to the function.




fraction multipliedBy(fraction second_fraction) const;
pre-conditions: A fraction object should be passed into this
member function to multiply the calling object's numerator and denominator
by the numerator and denominator  of the object in the argument/parameter.
post-conditions: The member function wil return an object which consists
of a simplified fraction of the multiplication of the fractions represented by
the calling object and the object passed to the function.




fraction dividedBy(fraction second_fraction) const;
pre-conditions: A fraction object should be passed into this
member function to divide  the calling object's numerator and denominator
by the numerator and denominator  of the object in the aegument/parameter.
post-conditions: The member function wil return an object which consists
of a simplified fraction of the division of the fractions represented by
the calling object and the object passed to the function.




void print() const;
pre-conditions: The numerator and denominator should
always be integer values.
post-conditions: The program will print out a fraction
created by printing out the numerator and deonminator with
a slash in between.




bool isEqualTo(fraction second_fraction) const;
pre-conditions: A fraction object should be passed
into the member function.
post-conditions: This boolean member function will return
whether or not the 2 fractions, the calling object fraction
and the fraction (object) passed in are equal.


*/


class fraction {
	
	private:
		int numerator;
		int denominator;
		void simplify();
	
	public:
		fraction();
		fraction(int frac_numerator, int frac_denominator);
		fraction addedTo(fraction second_fraction) const;
		fraction subtract(fraction second_fraction) const;
		fraction multipliedBy(fraction second_fraction) const;
		fraction dividedBy(fraction second_fraction) const;
		void print() const;
		bool isEqualTo(fraction second_fraction) const;
		
		
};

#endif
