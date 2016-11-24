#include "stdio.h"
#define abs(x) x>0?x:-x
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	if(n==1){
		printf("*");
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("*");
	}
	printf("\n");
	for (int i = n/2-n+2; i < n-n/2-1; ++i)
	{
		//printf("%d",i);

		int k=abs(i);

		for (int i = 0; i < k+1; ++i)
		{
			printf("*");
		}
		for (int i = 0; i < (n-2)-(k*2); ++i)
		{
			printf(" ");
		}
		for (int i = 0; i < k+1; ++i)
		{
			printf("*");
		}

		printf("\n");


	}


	for (int i = 0; i < n; ++i)
	{
		printf("*");
	}
	printf("\n");

	return 0;
}