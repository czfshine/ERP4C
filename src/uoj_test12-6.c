#include "stdio.h"
#include "stdlib.h"
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	int k=n/2;
	for (int j = -k; j <= k; ++j)
	{
		for (int i = 0; i <= abs(j); ++i)
			printf("*");
		for (int i = 0; i < ((k-abs(j))*2)-1; ++i)
			printf(" ");
		if(abs(j)==k)
			for (int i = 0; i < k; ++i)
				printf("*");
		else
			for (int i = 0; i <= abs(j); ++i)
				printf("*");
		printf("\n");
	}
	return 0;
}