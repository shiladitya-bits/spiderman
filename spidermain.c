/*
File: spidermain.c - Driver file
Creates a new process and calls the spider_spy function declared in header.h
if status returned  =1 MJ has been found
if status returned  =0 MJ has not been found
Pre condition: N>0 and there is only one path from spiderman to MJ
Post condition: Backward path is traced from MJ to Spiderman. In the end it is printed whether MJ has been found or not. 
*/
#include "header.h"
int main()
{
	pid_t pid;
	FILE *fp = fopen("input.txt","r");
	int n,i,j,status;
	//printf("Enter N: ");	
	fscanf(fp,"%d",&n);
	int **a;
	//printf("\nEnter the matrix elements in row major order:\n");
	a = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		a[i] = (int *)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
			fscanf(fp,"%d",&a[i][j]);
	}
	//input over. Sending spies now	
	pid = fork();	
	if(pid == -1)
	{
		perror("fork error");
	}		
	else if(!pid)
	{
		spider_spy(a,n,0,0);
	}
	wait(&status);	
	
	if(status == 256)
		printf("\nMJ successfully rescued\n");
	else if(status == 0)
		printf("\nSpiderman cannot rescue MJ\n");
	else
		printf("\nerror in execution\n");
	fclose(fp);	
	return 0;
}


