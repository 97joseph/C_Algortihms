#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) 
{
	#define PI 3.14159265359
	float CableDiameter,d,Conduit_diameter;
	int i=0,Nmax;
printf("Calculate the number of cables that fit inside of a conduit\nPlus the amount of Firestopping material needed");
printf("\n\nThe following 2 inputs are needed to calculate the number of cables\nthat fit inside the conduit:\n");
TOP:
printf("\nEnter the conduit inner diameter in inches> ");
scanf("%f",&Conduit_diameter);

printf("Enter the cable outer diameter in inches> ");
scanf("%f",&CableDiameter);

if (Conduit_diameter==0 or CableDiameter==0 ){
	printf("\nError either diameter cannot be 0\n");
	goto TOP;
}
float CableR, ConduitR;
CableR=CableDiameter*0.5;
ConduitR=Conduit_diameter*0.5;
d=CableDiameter*.866;
Nmax=(ConduitR-CableR)/d;

int TotalCables=0;

for (i=0;i<Nmax;i++){
	TotalCables+=(PI/(asin( CableR /((ConduitR)-(CableR)-d*i))));
}
if (TotalCables>3){
	TotalCables+=1;}
	
int Conduits,PercentFill,FirestopThickness;
printf("\nThe following 3 inputs are needed to calculate\nthe amount the firestop material needed:\n\n");
printf("Enter the maximum percent of allowed cable fill> ");
scanf("%i",&PercentFill);
printf("Enter the thickness of the firestop material in inches> ");
scanf("%i",&FirestopThickness);
printf("Enter the number of conduits> ");
scanf("%i",&Conduits);
int TotalInstalledCables= TotalCables*(float)PercentFill/100.0;
float ConduitArea=PI*(ConduitR*ConduitR);
float TotalCablesArea=(float)TotalCables*(PI*(CableR*CableR));
float FireStoppingMaterial=(ConduitArea-TotalCablesArea*(float)(PercentFill/100.0))*(float)(FirestopThickness*Conduits);
printf("At %i%% the number of cables that fit inside the conduit is: %d",PercentFill,TotalInstalledCables);
printf("\nThe volume of the firestopping material needed is : %.2f cubic inches",FireStoppingMaterial);
return 0;
}
