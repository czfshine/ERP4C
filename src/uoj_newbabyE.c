#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kkk = 0; kkk < T; ++kkk)
	{
		long long N,a;
		scanf("%lld%lld",&N,&a);
		long long sum=0,temp=1;

		while(sum<a){
			sum+=4*N-(2*temp-1)*4;
			temp++;
		}
		printf("%lld",sum);

		
	}
	return 0;
}

