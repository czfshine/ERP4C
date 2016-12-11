#include "stdio.h"
#include "stdlib.h"
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	int k=n/2;
	for (int j = -k; j <= k; ++j)
	{
		for (int i = 0; i < abs(j); ++i)
		{
			printf("*");
		}
		for (int i = 0; i < abs(k+j); ++i)
		{
			printf(" ");

		}

		printf("0\n");
	}
	return 0;
}