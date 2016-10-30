#include "stdio.h"
/* 
error 1:
	new line

*/
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
		for (int i = 0; i < 10; ++i)
		{	if(i<9)
				printf("%d ",count[i]);
			else
				printf("%d",count[i]);
		}
		if(T) printf("\n");
	}
	return 0;
}