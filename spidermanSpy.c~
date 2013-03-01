/*
File: spidermanSpy.c - implementation file
Parameters: 2D array 80X80 size, size of array N, current position (x,y)
exit code: current process will exit with code 1 if MJ has been found, else 0
*/
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int spider_spy(int **a,int n,int x,int y)
{
	if(a[x][y] == 1)
		exit(0);
	if(a[x][y] == 2)
	{
		printf("(%d,%d)",x,y); //found MJ
		exit(1);
	}
	pid_t pid1,pid2;
	int status1,status2;
	if( (x+1) < n)
	{
		pid1 = fork();	//sending the spy to below
		if(!pid1)
			spider_spy(a,n,x+1,y);
	}
	if( (y+1) < n && pid1!=0) // sending the spy to right and make sure that only parent from previous code executes this
	{
		pid2 = fork();
		if(!pid2)
			spider_spy(a,n,x,y+1);
	}
	wait(&status1);
	wait(&status2);
	//printf("my pid=%d status1=%d status2=%d,x=%d,y=%d\n",getpid(),status1,status2,x,y);
	if( status1==256 || status2==256)
	{
		printf("-> (%d,%d)",x,y); 
		exit(1); //giving back MJ to parent process
	}
	
	exit(0);
}
