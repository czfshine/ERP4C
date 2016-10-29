#include "stdio.h"

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)==1&&n){
		int data[n];
		int c1[11]={0};
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",data+i);
			c1[data[i]]++;
		}
		int m=1;
		while(m){
			int c2[11]={0};
			int A=0,B=0;
			printf("%d %d\n",A,B);
			for (int i = 0; i < n; ++i)
			{
				scanf("%d",&m);
				if(m==0) continue;
				c2[m]++;
				if(data[i]==m) A++;
			}
			for (int j = 1; j <= 9; ++j){
				if(c1[j] < c2[j]) B += c1[j]; else B += c2[j];
			}
			if(m)
				printf("%d %d\n",A,B);
		}
	}
	return 0;
}