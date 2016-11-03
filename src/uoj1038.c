#include "stdio.h"	

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n-i; ++j)
			printf(" ");
		for (int k = 1; k < i+2 ; ++k)
			printf("%d",k);
		for (int k = i; k >=1 ; --k)
			printf("%d",k);
		printf("\n");

	}
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < i+1; ++j)
			printf(" ");
		for (int k = 1; k < (n-i) -1; ++k)
			printf("%d",k);
		for (int k = (n-i)-1; k >=1 ; --k)
			printf("%d",k);
		printf("\n");
	}
	return 0;
}