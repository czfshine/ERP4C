#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int f(int n){
	long long k=1;
	int c=0;
	while(k<n){
		printf("%d",c);
		k*=5;
		c++;
	}
	//printf("%d",c--);
	c--;
	int j=1;
	long sum=0;
	int n1=4;
	for (int i = 0; i < c; ++i)
	{	

		for (int kk = 0; kk < n1; ++kk)
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
	scanf("%d",&n);
	f(n);
	return 0;
}