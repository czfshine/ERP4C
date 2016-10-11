#include "stdio.h"
int main(int argc, char const *argv[])
{
	int data[10];

	for (int i = 0; i < 10; ++i)
	{
		scanf("%d",data+i);
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",data[10-i-1]);
	}
	return 0;


}