// Program name: 2.1
// 
// Author: Dillon Pinto 
// Date:    2/4/16
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

int int_number,hundreds,twenties,tens,ones,fives,quarters,dimes,nickels,pennies;
float float_number,decimal;
printf("Calculate change\n");
printf("Enter a number>");
scanf("%f", &float_number);
int_number=float_number;
decimal=float_number-int_number;
hundreds=int_number/100;
int_number=int_number%100;
twenties=int_number/20;
int_number=int_number%20;
tens=int_number/10;
int_number=int_number%10;
fives=int_number/5;
int_number=int_number%5;
ones=int_number/1;
quarters=(int)(decimal/.25);
decimal=decimal-(quarters*.25);
dimes=(int)(decimal/.1);
decimal=decimal-(dimes*.1);
nickels=(int)(decimal/.05);
decimal=decimal-(nickels*.05);
pennies=(int)(decimal/.01);
printf("\n\nThe number of hundreds %i\n",hundreds);
printf("The number of twenties %i\n",twenties);
printf("The number of tens %i \n",tens);
printf("The number of fives %i \n",fives);
printf("The number of ones %i \n",ones);
printf("The number of quarters %i \n",quarters);
printf("The number of dimes %i \n",dimes);
printf("The number of nickels %i \n",nickels);;
printf("The number of pennies %i \n",pennies);
	
return 0;
}
