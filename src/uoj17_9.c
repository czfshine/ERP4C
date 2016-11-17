#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int f(int n){
	long long k=1;
	int c=0;
	while(k<n){
		//printf("%d",c);
		k*=5;
		c++;
	}
	
	c--;
	printf("%d",c);
	int j=1;
	long sum=0;
	int n1=4;
	for (int i = 0; i < c-1; ++i)
	{	

		for (int kk = 0; kk < n1; ++kk)
		{
			sum+=j;
			printf("%ld\n",sum);
		}
		j++;
		n1*=5;
	}

	int cc=n-n1/4;

	for (int i = 0; i < cc; ++i)
	{
		sum+=j;
			printf("%ld\n",sum);
	}
	printf("%ld",sum);
	return c;
}
int main(int argc, char const *argv[])
{	int n;
	scanf("%d",&n);
	f(n);
	return 0;
}