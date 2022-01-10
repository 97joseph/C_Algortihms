// Program name: Exercise 8
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
	
int choice;
float C,F,K,R,temp;

#define FOREVER 1



while (FOREVER){
	printf("\nTemperature conversions\n"\
			"1.\tFahrenheit -> Celsius\n"\
			"2.\tCelsius -> Farenheit\n"\
			"3.\tCelsius -> Kelvin\n"\
			"4.\tKelvin -> Celsius\n"\
			"5.\tKelvin -> Rankine\n"\
			"6.\tRankin -> Kelvin\n"\
			"7.\tExit");
	
	
	printf("\nSelect a conversion option 1-6 >");
	scanf("%i", &choice);
	
	
	switch(choice){
		
		case 1 :
			printf("\nEnter a temperature >");
			scanf("%f",&temp);
			
			C=((float)5/(float)9)*(temp-32);
			printf("Celsius = %.4f\n",C);
			break;
			
		case 2 :
			printf("\nEnter a temperature >");
			scanf("%f",&temp);
			F=(((float)9/(float)5)*temp)+32;
			printf("Farenheit = %.0f\n",F);
			break;
			
		case 3 :
			printf("\nEnter a temperature >");
			scanf("%f",&temp);
			K=temp+273.15;
			printf("Kelvin = %.2f\n",K);
			break;
		case 4 :
			
			printf("\nEnter a temperature >");
			scanf("%f",&temp);
			C=temp-273.15;
			printf("Celsius = %.2f\n",C);
			break;
		case 5 :
			
			printf("\nEnter a temperature >");
			scanf("%f",&temp);
			R=((float)9/(float)5)*temp;
			printf("Rankine = %.0f\n",R);
			break;
		case 6 :
			printf("\nEnter a temperature >");
			scanf("%f",&temp);
			K=((float)5/(float)9)*temp;
			printf("Celsius = %.4f\n",K);
			break;
		
		case 7 :
			goto QUIT;
			/* I could've used a a variable equal to a boolean and an if statement to check if the variable is true outside the switch statement, and break out of the loop
			if the variable was  */
		
		default :
			printf("Invalid option");
			
		
	}

}
QUIT: ;



return 0;
}
