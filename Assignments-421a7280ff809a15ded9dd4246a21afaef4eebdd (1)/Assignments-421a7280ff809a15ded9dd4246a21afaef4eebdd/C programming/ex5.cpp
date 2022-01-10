// Program name: exercise 5
// Author: Dillon Pinto
// Date:  2/11/16
// Course:  Computer Science 217
// Description: 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(void) 
{

int students;
float efficiency_coefficient,efficiency_factor,lec_hours, lab_hours, percent_efficiency;
char quit;
#define OPTIMUM_EFFICIENT_FACTOR 15

printf("This program calculates a Cuesta class efficientcy factor where 15 and above is considered efficient\n\n");


TOP:
printf("Enter the number of weekly lecture hours>");
scanf("%f",&lec_hours);
printf("Enter the number of weekly lab hours>");
scanf("%f", &lab_hours);
printf("Enter the number of students in the class>");
scanf("%i", &students);
printf("\n");

if (lec_hours==0 and lab_hours==0){
	printf("Lecture hours and Lab hours cannot both be 0\n");
	goto TOP;
	
}

efficiency_coefficient=((0.5*lec_hours)+(((float)2/(float)3)* lab_hours))/(lec_hours+lab_hours);
efficiency_factor=efficiency_coefficient*students;
percent_efficiency=(efficiency_factor/OPTIMUM_EFFICIENT_FACTOR)*100;


printf("Course efficiency coefficient = %.2f\n", efficiency_coefficient);
printf("Course efficiency factor = %.2f\n", efficiency_factor);
printf("Course Percent efficiency = %.2f\n", percent_efficiency);

printf("\nTo quit enter Y>");
scanf(" %c",&quit);


quit=tolower(quit);

if (quit=='y'){
	return 0;
}
else{
	goto TOP;}
}
