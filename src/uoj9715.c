#include "stdio.h"
#include <math.h>
#include "stdlib.h"
#define min(x,y) ((x)<(y)?x:y)
#define max(x,y) ((x)>(y)?x:y)
//todo
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int x[n],c,rh,lh,m=0,j,k,i,s,mi;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",x+i);
	}
	for (int i = 0; i < n; ++i)
	{
		c=x[i];
		rh=0;
		lh=0;
		mi=x[i];
		for (j = 0; j < n; ++j)
		{
			rh=x[j];
			for (k=i;k>0;k--)
			{
				lh=x[k];
				mi=min(mi,min(lh,rh));
				s=mi*(abs((j+1)-(k+1))+1);
				printf("%d,%d=%d %d %d\n",j+1,k+1,(abs((j+1)-(k+1))+1),mi,s);
				m=max(m,s);
			}
		}

	}

	printf("%d",m);
	return 0;
}