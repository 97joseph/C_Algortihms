// Program name: Exercise 6
// 
// Author: Dillon Pinto
// Date:  2/25/16
// Course:  Computer Science 217
// 
// 
// Description: Finds the largest of 3 numbers
//               

 

#include <stdio.h>
#include <stdlib.h>

int main(void) {

float a,b,c;

printf("Find the largest number\n");
printf("Enter number a >");
scanf("%f",&a);
printf("Enter number b >");
scanf("%f",&b);
printf("Enter number c >");
scanf("%f",&c);


if ((a>b) and (a>c)){
	printf("a is the greatest");
}

else if ((b>a)and (b>c)){
	printf("b is the greatest");
}

else if ((a==c)and (a==b) and (a==c)){
	printf("they are all equal ");
}

else if ((a==c)and (a==b)){
	printf("they are all equal ");
}

else if (a==c){
	printf("a = c are the greatest");
}

else if (a==b){
	printf("a = b are the greatest");
}

else if (b==c){
	printf("b = c are the greatest");
}

else{
	printf("c is the greatest");
}

printf("\n");
return 0;
}
