// Program name: Exercise 5B
// Author: Dillon Pinto 
// Course:  Computer Science 217
// Description: 
float quadratic_f(float a, float b, float c, int root_select);
#define ERROR_CODE 99999999
#define POS_ROOT 1
#define NEG_ROOT 0             
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float quadratic(float a, float b, float c, int root_select){
	if((b*b)<(4*a*c)){
		return ERROR_CODE;}
	if (root_select==1){
	return ((-b)+sqrt((b*b)-(4*a*c)))/(2*a);}
	if (root_select==0){
	 return ((-b)-sqrt((b*b)-(4*a*c)))/(2*a);}}
	 
int main(void) 
{
	float x1,x2,b,a,c;
	printf("Quadratic equation root calculator aX^2 + bX + c");	
	
	while(true){
	printf("\n\nEnter a >");
	scanf("%f",&a);
	printf("Enter b >");
	scanf("%f",&b);
	printf("Enter c >");
	scanf("%f",&c);
	
	if (a==0){
		printf("\nInput a cannot be 0\n");
		continue;}
		
	
	x1=quadratic(a,b,c,POS_ROOT);
	if (x1==ERROR_CODE){
		float a_suggestion,b_suggestion,c_suggestion;
		a_suggestion= (b*b)/(4*c);
		b_suggestion=2*sqrt(a*c);
		c_suggestion=(b*b)/(4*a);
		printf("\nModify one of the following:\n");
		printf("Input a must be less than or equal to %.2f",a_suggestion);
		printf("\nInput b must be greater than or equal to %.2f",b_suggestion);
		printf("\nInput c must be less than or equal to %.2f",c_suggestion);
		continue;}
		
	x2=quadratic(a,b,c,NEG_ROOT);
	printf("\nThe roots are x = %f and %f\n",x1,x2);}
}
