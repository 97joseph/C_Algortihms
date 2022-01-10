zz#include <iostream>
using namespace std;



class fraction {
	
	private:
		int numerator;
		int denominator;
	
	public:
		void set(int frac_numerator, int frac_denominator);
		fraction addedTo(fraction second_fraction) const;
		fraction subtract(fraction second_fraction) const;
		fraction multipliedBy(fraction second_fraction) const;
		fraction dividedBy(fraction second_fraction) const;
		void print() const;
		bool isEqualTo(fraction second_fraction) const;
		
};






void fraction::set(int frac_numerator, int frac_denominator) {
	numerator = frac_numerator;
	denominator = frac_denominator;
}






fraction fraction::addedTo(fraction second_fraction) const {
	
	int answer_numerator;
	int answer_denominator;
	fraction answer;
	
	answer_numerator = ( (numerator * second_fraction.denominator) +
						(second_fraction.numerator * denominator));
	answer_denominator = denominator * second_fraction.denominator;
	
	answer.set(answer_numerator, answer_denominator);
	
	return answer;
}






fraction fraction::multipliedBy(fraction second_fraction) const {
	
	int answer_numerator;
	int answer_denominator;
	fraction answer;
	
	answer_numerator = numerator * second_fraction.numerator;
	answer_denominator = denominator * second_fraction.denominator;
	
	answer.set(answer_numerator, answer_denominator);
	
	return answer;
}






fraction fraction::subtract(fraction second_fraction) const {
	
	int answer_numerator;
	int answer_denominator;
	fraction answer;
	
	answer_numerator = ((numerator * second_fraction.denominator) -
						(second_fraction.numerator * denominator));
	answer_denominator = denominator * second_fraction.denominator;
	
	answer.set(answer_numerator, answer_denominator);
	
	return answer;
}






fraction fraction::dividedBy(fraction second_fraction) const {
	
	int answer_numerator;
	int answer_denominator;
	fraction answer;
	
	answer_numerator = numerator * second_fraction.denominator;
	answer_denominator = denominator * second_fraction.numerator;
	
	answer.set(answer_numerator, answer_denominator);
	
	return answer;
}






void fraction::print() const {
	cout << numerator << "/" << denominator;
}






bool fraction::isEqualTo(fraction second_fraction) const {
	
	return ((numerator * second_fraction.denominator) ==
			(denominator * second_fraction.numerator));
}






int main() {
    fraction f1;
    fraction f2;
    fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two fractions are equal." << endl;
    } else {
        cout << "The two fractions are not equal." << endl;
    }
}

/*
Output:
The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two fractions are not equal.

*/
