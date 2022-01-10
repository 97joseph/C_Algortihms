// Program name: Prob 39
// Author: Dillon Pinto
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(void) 
{
	#define OXYGEN 15.9994
	#define CARBON 12.011
	#define NITROGEN 14.00674
	#define HYDROGEN 1.00794
	#define SULFUR 32.066
	
	int O,C,N,H,S;
	float O_subtotal,C_subtotal,N_subtotal,H_subtotal,S_subtotal;
	
	printf("This program calculates the total atomic weight based on number of atoms of each element.\n");
	printf("Enter the number of oxygen atoms >");
	scanf("%d",&O);
	printf("Enter the number of carbon atoms>");
	scanf("%d",&C);
	printf("Enter the number of nitrogen atoms>");
	scanf("%d",&N);
	printf("Enter the number of sulfur atoms>");
	scanf("%d",&S);
	printf("Enter the number of hydrogen atoms>");
	scanf("%d",&H);
	
	O_subtotal=(float)(OXYGEN*O);
	C_subtotal=(float)(CARBON*C);
	N_subtotal=(float)(NITROGEN*N);
	H_subtotal=(float)(HYDROGEN*H);
	S_subtotal=(float)(SULFUR*S);
	printf("Element\t\tAtomic weight\tno# of atoms\t\t\tSubtotals\n");
	printf("--------------------------------------------------------------------------\n");
	printf("Oxygen\t\t%.5f\t\t%d\t\t\t%f\n",OXYGEN,O ,O_subtotal);
	printf("Carbon\t\t%.5f\t\t%d\t\t\t%f\n",CARBON,C ,C_subtotal);
	printf("Nitrogen\t%.5f\t\t%d\t\t\t%f\n",NITROGEN,N ,N_subtotal);
	printf("Sulfur\t\t%.5f\t\t%d\t\t\t%f\n",SULFUR,S ,S_subtotal);
	printf("Hydrogen\t%.5f\t\t\t%d\t\t\t%f\n",HYDROGEN,H ,H_subtotal);
	printf("--------------------------------------------------------------------------\n");
	
	float Total_atomic_weight, Total_subtotal;
	int Total_no_of_atoms;
	Total_atomic_weight=OXYGEN+CARBON+NITROGEN+SULFUR+HYDROGEN;
	Total_no_of_atoms=O+C+N+H+S;
	Total_subtotal=O_subtotal+C_subtotal+N_subtotal+H_subtotal+S_subtotal;
	printf("Totals\t\t%f\t\t%d\t\t\t%f\n",Total_atomic_weight,Total_no_of_atoms ,Total_subtotal);
	
	return 0;

}
