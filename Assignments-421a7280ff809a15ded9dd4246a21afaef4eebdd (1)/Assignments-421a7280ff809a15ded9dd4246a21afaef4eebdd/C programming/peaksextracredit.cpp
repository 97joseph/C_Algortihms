// Program name: exercise 16
// Author: Dillon Pinto
// Course:  Computer Science 217
// Description: 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#define MAXROW 50
#define MAXCOL 50
#define MAXPEAKS 150
#define DETECTED 1 
#define FALSE 0 
#define TRUE 1 
#define FILENAME "peaks.txt"

int peakdetect (double xydata[MAXROW][MAXCOL], int i, int j){
	if ((xydata[i-1][j]<xydata[i][j]) &&
		(xydata[i+1][j]<xydata[i][j]) &&
		(xydata[i][j-1]<xydata[i][j]) &&
		(xydata[i][j+1]<xydata[i][j])){
		return DETECTED;}
	else{
		return FALSE;
	}}
int main(void) 
{
	double value;
	int i=0,j=0,col=0,row=-1;
	double peaks_array[MAXPEAKS];
	double xydata[MAXROW][MAXCOL];
	FILE *peaks;
	peaks = fopen(FILENAME, "r");
	while(!feof(peaks)){
		col=i%50;
		i+=1;
		if (col==0){
			row+=1;
		}
		if (row==50){
		break;}
		fscanf(peaks, "%lf",&xydata[row][col]);	}
	printf("Peak height\t\tx-coord\t\ty-ccord\n");
	for (i=1;i<=MAXROW-2;i++){
		for(j=1;j<=MAXCOL-2;j++){
			int peak_search=peakdetect (xydata, i,j);
			if (peak_search==DETECTED){
				
				printf("%.2lf\t\t\t%i\t\t%i\n",xydata[i][j],i,j);
				}}}
	return 0;
}
