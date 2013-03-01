/*
File: header.h - Header file for spiderman program
Defines the functions used and required libraries required for system calls and I/O
int spider_spy(int[][],int,int,int) traverses the matrix and finds MJ and traces back her to spiderman (0,0) 
It exits with code 1 if MJ has been found, else 0 if not found
*/
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int spider_spy(int **,int,int,int);

