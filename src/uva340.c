#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)==1&&n){
		int data[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",data+i);
		}

		int A=0,B=0;

		for (int i = 0; i < n; ++i)
		{
			int m;
			scanf("%d",&m);
			if(m==0)break;
			if(data[i]==m) A++;

			for (int j = 0; j < n; ++j)
			{
				if(data[j]==m) B++;
				break;
			}
			printf("%d %d",A,B);
		}
	}
	return 0;
}