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
	printf("%d",sum);
	return 0;
}