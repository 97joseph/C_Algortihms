// Program name: Exercise 3
// 
// Author: Dillon Pinto
// Date:  2/25/16
// Course:  Computer Science 217
// 
// 
// Description: 
//               

 

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	

float fresult;
int no1,no2, frac_whole, frac_remainder, frac_denominator;

printf("Divide two whole numbers");
printf("\nEnter number1>");
scanf("%i",&no1);
printf("\nEnter number2>");
scanf("%i",&no2);

fresult=(float)no1/(float)no2;
frac_whole=no1/no2;
frac_remainder=no1%no2;
frac_denominator=no2;

printf("\nThe floating point result is %f",fresult);
printf("\nThe fractional result is %i and %i/%i\n",frac_whole,frac_remainder,frac_denominator);



system("PAUSE");
return 0;
}
