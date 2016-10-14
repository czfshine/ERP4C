#include "stdio.h"

int main(int argc, char const *argv[])
{
	int s;
	scanf("%d",&s);
	if (s<0 || s>100)
		{printf("error");return 0;}
	if(s>=0 && s<60)
		{printf("E");return 0;}
	if (s<70)
		{printf("D");return 0;}
	if (s<80)
		{printf("C");return 0;}
	if (s<90)
		{printf("B");return 0;}
	if (s<=100)
		{printf("A");return 0;}
	
	

	return 0;
}