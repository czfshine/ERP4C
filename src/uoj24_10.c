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
			while(i%5==0){
				count++;
			}
			printf("%d",count);
		}
	}
	return 0;
}