#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
int main(void) 
{
	char infilename[20],outfilename[20],secretmessage[100],encryption_codes[100];
	int i, key;
	FILE *message;
	for (i=0;i<100;i++){
		secretmessage[i]=0;
	}
	printf("This program encrypts or decrepyts a message\n");
	printf("Enter the input file name> ");
	scanf("%s",&infilename);
	printf("Enter the output file name> ");
	scanf("%s",&outfilename);
	printf("Enter the encryption key number between 1 and 32767>");
	scanf("%d",&key);
	srand(key);
	for(i=0;i<100;i++){
	encryption_codes[i]=rand()%256;
}
	message=fopen(infilename,"r");
	if (message==NULL){
		perror("Error");
		goto END;
	}
	else{
		i=0;
		while(!feof(message)){
			fscanf(message,"%c",&secretmessage[i++]);}
		printf("Message read from file\n%s\n",secretmessage);
		for(i=0;i<strlen(secretmessage);i++){
			secretmessage[i]=encryption_codes[i]^secretmessage[i];}
		printf("Encrypted message send to file\n%s\n",secretmessage);}
	fclose(message);
	FILE *write_to;
   write_to = fopen(outfilename, "w+");
   fputs(secretmessage, write_to);
   fclose(write_to);
	END:
return 0;
}
