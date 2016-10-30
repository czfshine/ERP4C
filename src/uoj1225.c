#include "stdio.h"
int main(int argc, char const *argv[])
{	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n==0){
			printf("1 0 0 0 0 0 0 0 0 0\n");
			continue;
		}
		int count[10]={0};
		for (int i = 1; i <= n; ++i)
		{
			int t=i;
			while(t){
				count[t%10]++;
				t/=10;
			}

		}
		for (int i = 0; i < 9; ++i)
		{
			printf("%d ",count[i]);
		}
		printf("%d",count[9]);
	}
	printf("\n");
	return 0;
}