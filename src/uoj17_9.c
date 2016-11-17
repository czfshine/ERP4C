#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int f(long n){
	long k=1;
	int c=0;
	while(k<n){
		k*=5;
		c++;
	}
	int j=1;
	long sum=0;
	int n1=4;
	for (int i = 0; i < c; ++i)
	{	

		for (int i = 0; i < n1; ++i)
		{
			sum+=j;
		}
		j++;
		n1*=5;
	}
	printf("%d",sum);
	return c;
}
int main(int argc, char const *argv[])
{	int n;
	scanf("%d",n);
	f(n)
	return 0;
}