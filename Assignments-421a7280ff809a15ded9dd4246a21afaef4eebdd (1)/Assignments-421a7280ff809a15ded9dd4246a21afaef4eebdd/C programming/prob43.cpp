#include <stdio.h>
#include <math.h>

int main ()
{
	int first_angle,second_angle,new_angle;
	float lift_coefficient1,lift_coefficient2, new_lc;

	printf("This program uses linear interpolation to compute the coefficient of life for an angle from a wind tunnel test\n\nUse degrees for all angle measurements.\n\n");
	
	printf("Enter first angle and lift coefficient with a space between them> ");
	scanf("%d %f",&first_angle,&lift_coefficient1);
	
	printf("Enter second angle and lift coefficient with a space between them> ");
	scanf("%d %f",&second_angle,&lift_coefficient2);
	
	printf("Enter new angle> ");
	scanf("%d",&new_angle);
	
	new_lc=lift_coefficient1+(((float)(new_angle-first_angle)*lift_coefficient2-lift_coefficient1)/  (float)(second_angle-first_angle));
	printf("New lift coefficient: %.3f",new_lc);
	
	
	
	return 0;
   
}
