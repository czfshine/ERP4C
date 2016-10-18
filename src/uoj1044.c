#include "stdio.h"

int main(int argc, char const *argv[])
{
	int data[10],min;
	for (int i = 0; i < 10; ++i)
		scanf("%d",data+i);
	min=data[0];
	for (int i = 0; i < 10; ++i)
		if(data[i]<min){min=data[i];}
	printf("%d",min);
	return 0;
}


	