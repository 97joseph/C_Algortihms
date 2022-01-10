// Program name: Exercise 8.1
// 
// Author: Dillon Pinto
// Date:  2/25/16
// Course:  Computer Science 217
// 
// 
// Description: Solar panel  stuff
//               

 

#include <stdio.h>
#include <stdlib.h>

int main(void) {

float power_max,t_derate_factor,power_derated,rated_efficiency,sun_energy,panel_area,temperature,power_measured;
int relative_efficiency;

printf("This program detects the state of a solar array\n\n");
printf("Enter the rated solar panel effieciency in %> ");
scanf("%f",&rated_efficiency);
printf("Enter the sun radiation energy in watts/m^2 > ");
scanf("%f",&sun_energy);
printf("Enter the solar panel area in m^2> ");
scanf("%f",&panel_area);
printf("Enter the solar panel temperature in deg C> ");
scanf("%f",&temperature);
printf("Enter the measured solar panel power in Watts> ");
scanf("%f",&power_measured);


power_max=(rated_efficiency/100)*sun_energy*panel_area;
t_derate_factor=1-(temperature-25.0)/200.0;
power_derated=power_max*t_derate_factor;
relative_efficiency=((power_measured/power_derated)*100)+0.5;

printf("\nMaximum panel power %.2f Watts",power_max);
printf("\nTemperature derated panel power %.2f Watts",power_derated);
printf("\nRelative panel efficiency %i%%  \n",relative_efficiency);




switch(relative_efficiency){
	//large upper range because it could be over 100%
	case 91 ... 200:
		printf("The panels are functioning optimally");
		break;
	case 81 ... 90:
		printf("Inspect the panels for dust");
		break;
	case 71 ... 80:
		printf("The panels are most likely filthy");
		break;
	case 51 ... 70:
		printf("The panels may be partially obstructed");
		break;
	case  31 ... 50:
		printf("The panels are nearly mostly obstructed");
		break;
	default:
		printf("The panels have failed");

}


return 0;
}
