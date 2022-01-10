// Program name: Exercise 5B
// 
// Author: Dillon Pinto 

// Course:  Computer Science 217
// 
// 
// Description: 
//               
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(void) 
{

float x1,x2,b,a,c;


printf("Quadratic equation root calculator aX^2 + bX + c");	
printf("\nEnter a >");
scanf("%f",&a);
printf("Enter b >");
scanf("%f",&b);
printf("Enter c >");
scanf("%f",&c);

if (a==0){
	printf("\nInput a cannot be 0");
	return 1;
}
if((b*b)<(4*a*c)){
	
	float a_suggestion,b_suggestion,c_suggestion;
	a_suggestion= (b*b)/(4*c);
	b_suggestion=2*sqrt(a*c);
	c_suggestion=(b*b)/(4*a);
	
	printf("\nModify one of the following:\n");
	printf("Input a must be less than or equal to %.2f",a_suggestion);
	printf("\nInput b must be greater than or equal to %.2f",b_suggestion);
	printf("\nInput c must be less than or equal to %.2f",c_suggestion);
	return 1;
}
x1=((-b)+sqrt((b*b)-(4*a*c)))/(2*a);
x2=((-b)-sqrt((b*b)-(4*a*c)))/(2*a);

printf("\nThe roots are x = %f and %f",x1,x2);
return 0;
}
