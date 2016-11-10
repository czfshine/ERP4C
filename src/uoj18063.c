#include "stdio.h"
//todo
long long data[1000000];
int main(int argc, char const *argv[])
{
	long long n,m=3;
	scanf("%lld",&n);
	
	data[1]=1;
	for (long long i = 2; i <= n; ++i)
		data[i] = (data[i-1]+m-1)%i + 1;
	printf("%lld\n",data[n]);
	return 0;
}