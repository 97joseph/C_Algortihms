// Program name: exercise 16
// Author: Dillon Pinto
// Course:  Computer Science 217
// Description: 
#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
	int day1,day2,day3,day4,day5,day6,day7, weekTotal, row=0;
	FILE *fp;
	printf("All powerplant output over an 8 week period\n");
	printf("\tDay1   Day2    Day3    Day4    Day5    Day6    Day7   WeekTotal\n");
	printf("-----------------------------------------------------------------------\n");
	int power_list[8][7];
	fp = fopen("power1.txt", "r");
	while(!feof(fp)){
		fscanf(fp, "%d %d %d %d %d %d %d", &day1,&day2,&day3,&day4,&day5,&day6,&day7);
		power_list[row][0]=day1;
		power_list[row][1]=day2;
		power_list[row][2]=day3;
		power_list[row][3]=day4;
		power_list[row][4]=day5;
		power_list[row][5]=day6;
		power_list[row][6]=day7;
		row+=1;	
	}
    fclose(fp);
	int i,j;
	for(i=0;i<8;i++){
		int weekly_total=0;
		printf("Week %d  ",i+1);
		for(j=0;j<7;j++){
			printf("%d\t",power_list[i][j]);
			weekly_total+=power_list[i][j];
			if (j==6){
				printf("%d\n",weekly_total);}}}
				
	int min_power=100000,week_min,day_min,max_power=0,week_max,day_max,instance_min,instance_max,power;
	for(i=0;i<8;i++){
		for(j=0;j<7;j++){
			
			power=power_list[i][j];
			if (power>max_power){
				max_power=power;
				week_max=i+1;
				day_max=j+1;
				instance_max=0;
				
			}
			if (power<min_power){
				min_power=power;
				week_min=i+1;
				day_min=j+1;
				instance_min=0;
			}
			if (power=max_power){
				instance_max=1;
			}
			if (power=min_power){
				instance_min=1;
			}}}
			
			printf("\nWeek %d, day %d was a maximum power out day of %.2f Megawatts\n",week_max,day_max,(float)max_power);
			printf("Week %d, day %d was a minimum power out day of %.2f Megawatts\n",week_min,day_min,(float)min_power);
	return 0;
}
