#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int count[10]={0};
	for (int i = 1; i <= n; ++i)
	{
		int t=i;
		while(t){
			printf("-%d\n",t%10); 
			count[t%10]++;
			t/=10;
			printf("+%d",t);
		}

	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",count[i]);
	}
	return 0;
}