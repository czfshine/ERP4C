#include "stdio.h"
int main(int argc, char const *argv[])
{
	float sum=0,data;
	for (int i = 0; i < 10; ++i)
	{
		scanf("%f",&data);
		sum+=data;
	}

	printf("%.2f",sum/10.0);


	return 0;
}