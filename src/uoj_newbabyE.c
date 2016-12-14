#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kkk = 0; kkk < T; ++kkk)
	{
		long long N,a;
		scanf("%lld%lld",&N,&a);
		if(N*N==a){
			printf("%lld %lld",N/2+1,N/2+1);
			continue;
		}
		long long sum=0,temp=1;
		long long t=N/2+1;
		while(sum<a&& temp<=t){
			//printf("%lld",sum);
			sum+=4*N-(2*temp-1)*4;
			temp++;
		}
		printf("%lld,%d",sum,temp);
		if(sum-a<2){
			int dx=temp-1;
			int dy=temp;
			printf("%d %d",dx,dy);
		}
		//printf("%lld",sum-a);
		
	}
	return 0;
}
