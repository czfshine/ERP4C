#include "stdio.h"
int main(int argc, char const *argv[])
{	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int count[10]={0};
		for (int i = 1; i <= n; ++i)
		{
			int t=i;
			while(t){
				count[t%10]++;
				t/=10;
			}

		}
		for (int i = 0; i < 10; ++i)
		{
			printf("%d ",count[i]);
		}
	}
	return 0;
}