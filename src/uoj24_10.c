#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);

	while(T--){
		int n;
		scanf("%d",&n);
		int m=n/5;
		int h;
		for (int i = 1; i <= m; ++i)

		{	int count=0;
			int t=i;
			while(t%5==0){
				t=t/5;
				count++;
			}
			printf("%d",count);
		}
		printf("1\n");
	}
	return 0;
}