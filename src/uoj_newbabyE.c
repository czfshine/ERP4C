#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kkk = 0; kkk < T; ++kkk)
	{
		long long N,a;
		scanf("%lld%lld",&N,&a);
		long long temp;
		temp=a/(4*N)+2;

		while(4*N*temp-temp*temp >a){
			printf("%lld",4*N*temp-temp*temp);
			temp--;
		}
		printf("%lld",temp+1);
	}
	return 0;
}
