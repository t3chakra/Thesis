#include<stdio.h>
int main()
{
	
	char buffer[2500];	
	while(1) 
	{
		fgets(buffer,sizeof buffer,stdin);
		fprintf(stdout,"Inside C code %s\n",buffer);
		
	}
	fprintf(stdout,"C exiting\n");
	fflush(stdout);
	return 0;
}
