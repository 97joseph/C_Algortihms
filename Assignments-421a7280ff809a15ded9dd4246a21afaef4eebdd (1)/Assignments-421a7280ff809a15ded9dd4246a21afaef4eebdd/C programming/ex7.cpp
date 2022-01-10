// Program name: Exercise 7 - Extra credit
// Author: Dillon Pinto
// Course:  Computer Science 217
// Description: Extra credit - Boxes ex7
#include <stdio.h>
#include <stdlib.h>

int main(void) {

float large_box_height,large_box_width,box_A_height,box_A_width,box_B_height,box_B_width;

printf("Find if 2 small boxes fit in large box\n\n");

printf("Enter large box height >");
scanf("%f",&large_box_height);

printf("Enter large box width >");
scanf("%f",&large_box_width);

printf("\nEnter  box A height >");
scanf("%f",&box_A_height);


printf("Enter  box A width >");
scanf("%f",&box_A_width);

printf("\nEnter  box B height >");
scanf("%f",&box_B_height);

printf("Enter  box B width >");
scanf("%f",&box_B_width);

if ((box_A_height==box_A_width) and (box_B_height==box_B_width)){

	if (((large_box_height-box_A_height-box_B_height)>=0) and ((large_box_width-box_A_width-box_B_width)>=0)){
	
		
		printf("They fit");
		return 0;
		    }

	else{
	printf("They don't fit");
	return 0;
	}}

else if (large_box_height==large_box_width){

	
	 if ((box_A_height != box_A_width)and (box_B_height == box_B_width) ){
	 	if (large_box_height<=box_A_height){
	 		printf("They don't fit");
	 		return 0;
		 
		if ((box_A_height>box_A_width)){
			
			
			printf("\nThey fit if Box A is above/below Box B and is rotated 90 degrees");}
			
		else{
			printf("\nThey fit if Box A is beside Box B and is rotated 90 degrees");}
	
	
	}
	
	}else if ((box_B_height != box_B_width) and (box_A_height == box_A_width)){
		if (box_B_height>box_B_width){
			printf("\nThey fit if Box B is above/below Box A and is rotated 90 degrees");	
		}
		
		else{
			printf("\nThey fit if Box B is beside Box A and is rotated 90 degrees");
		}
	}
	else if((box_A_height==box_B_height)and(box_B_width==box_A_width)){
		if (box_A_height>box_A_width){
			if (large_box_height>=box_A_height){
				printf("The fit with both box A and B height wise parallel");}
				else{
					printf("They don't fit");
				}}
		else{
			if (large_box_width>=box_A_width){
				printf("The fit with both box A and B width wise parallel");}
				else{
					printf("They don't fit");
				}}}
	else if ((box_A_height==box_B_width)and (box_A_width==box_B_height)){
		if(box_A_height>box_A_width){
			if (large_box_width>=box_A_height and large_box_height>=box_B_width){
				printf("They fit if either box A or B are rotated 90 degrees");
			}
			else{
				printf("They don't fit");
			}
		}
		else{
			if (large_box_height>=box_A_width and large_box_width>=box_B_height ){
				printf("They fit if either box A or B are rotated 90 degrees");}
			else{
				printf("They don't fit");
			}
				}
	}}
		

	
else if (large_box_height!=large_box_width){
		if (box_A_height==box_B_width){
			if (large_box_height>=box_A_height){
				printf("They fit if either box A or B are rotated 90 degrees");}}
		
		else if (box_B_height==box_A_width){
			if (large_box_width>box_A_height){
				printf("They fit if either box A or B are rotated 90 degrees");}}
	}
return 0;
}
