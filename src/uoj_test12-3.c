#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&m,&n);
	int sum=1;
	if(n<m/2){n=m-n;}
	for (int i = m; i > n; --i)
	{
		sum*=i;
	}
	int sum2=1;
	for (int i = 1; i <= n; ++i)
	{
		sum2*=i;
	}
	printf("%d",sum/sum2);
	return 0;
}