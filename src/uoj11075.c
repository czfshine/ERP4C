#include "stdio.h"
int main(int argc, char const *argv[])
{
	long long n,yes=1;
	scanf("%lld",&n);
	for (long long i = 0; i <=(256*n-2101)/3125; ++i)
	{
		if((2101 + 3125*i)%256==0){
			printf("%lld ",(2101 + 3125*i)/256);
			yes=0;
		}
	}
	if(yes)
		printf("impossible");
	return 0;
}