//Name: Dillon Pinto
//Exercise: problem 3-19

#include <stdio.h>
#include <math.h>

int main ()
{
	#define PI 3.14159265358979323846
	float increment,angle=0,angle_in_radians;
	printf("Enter the value for increment berween lines: ");
	scanf("%f",&increment);
	
	printf("Degrees to Radians with the increment %f\n",increment);
	
	while(angle<=360){
	
		angle_in_radians=(angle/(float)360)*(2*PI);
		printf("%f\t%f\n",angle,angle_in_radians);
		
		if (angle==360){
			break;
		}
		angle+=increment;
		if (angle>360){
			angle=360.0;	
		}
		
	}
	
	return 0;
   
}
