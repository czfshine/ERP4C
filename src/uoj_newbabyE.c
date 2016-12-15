#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kkk = 0; kkk < T; ++kkk)
	{
		long long N,a;
		scanf("%lld%lld",&N,&a);
		if(N*N==a&&N%2==1){
			printf("%lld %lld\n",N/2+1,N/2+1);
			continue;
		}
		int yes=0;
		long long sum=0,temp=1;
		long long t=N/2+1;
		while(sum<a&& temp<=t){
		//	printf("%lld\n",sum);
			sum+=4*N-(2*temp-1)*4;
			temp++;
		}
		sum-=4*N-(2*temp-3)*4;
		//printf("%lld,%lld",sum,N-(temp-2 )*2);
		int dx=temp-1;
		int dy=temp-1;
		sum++;
		//printf("%d,%d",dx,dy);
		for (int i = 0; i < N-(temp-2 )*2-1; ++i)
		{
			if(sum!=a){
				dx++;
			}else{
				yes=1;
				break;
			}
			sum++;
		}
		if(yes){
			printf("%d %d\n",dy,dx);
			continue;
		}
		for (int i = 0; i < N-(temp-2 )*2-1; ++i)
		{
			if(sum!=a){
				dy++;
			}else{
				yes=1;
				break;
			}
			sum++;
		}
if(yes){
			printf("%d %d\n",dy,dx);
			continue;
		}
		for (int i = 0; i < N-(temp-2 )*2-1; ++i)
		{
			if(sum!=a){
				dx--;
			}else{
				yes=1;
				break;
			}
			sum++;
		}
if(yes){
			printf("%d %d\n",dy,dx);
			continue;
		}
		for (int i = 0; i < N-(temp-2 )*2-1; ++i)
		{
			if(sum!=a){
				dy--;
			}else{
				yes=1;
				break;
			}
			sum++;
		}

if(yes){
			printf("%d %d\n",dy,dx);
			continue;
		}
		//printf("%lld",sum-a);
		
	}
	return 0;
}
