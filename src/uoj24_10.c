#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);

	while(T--){
		long long  n;
		scanf("%lld",&n);
		long long  m=n/5;
		long long h;
		long long count=0;
		for (long long i = 1; i <= m; ++i)
		{	count++;
			long long  t=i;
			while(t%5==0){
				t=t/5;
				count++;
			}
			
		}
		printf("%lld\n",count);
	}
	return 0;
}