#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kkk = 0; kkk < T; ++kkk)
	{
		long long N,a;
		scanf("%lld%lld",&N,&a);
		if(N*N==a)
			printf("%lld %lld",N/2+1,N/2+1);
		long long sum=0,temp=1;
		long long t=N/2+1;
		while(sum<=a&& temp<=t){
			printf("%lld",sum);
			sum+=4*N-(2*temp-1)*4;
			temp++;
		}
		printf("%lld,%d",sum,N-(temp-2)*2);

		
	}
	return 0;
}
