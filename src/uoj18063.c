#include "stdio.h"
//todo
int main(int argc, char const *argv[])
{
	long long n,m=3;
	scanf("%lld",&n);
	long long data[n+1];
	data[1]=1;
	for (long long i = 2; i <= n; ++i)
		data[i] = (data[i-1]+m-1)%i + 1;
	printf("%lld\n",data[n]);
	return 0;
}