#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);

	for (int i = 0; i < T; ++i)
	{
		int n,k,l,t=0,m;
		scanf("%d",&n);
		int a[n];

		for (int j = 0; j < n; ++j)
		{
			scanf("%d",a+j);
		}

		for(k=0;k<n;k++) 
   		{
   			for(l=0;l<k;l++) 
        		 if (a[k]<a[l]) 
            		{t=a[k];a[k]=a[l];a[l]=t;} 
   		} 

   		for (m = 0; m <(n + 1)/ 2; ++m)
   		{
   			 printf("%d ",a[m]);
   		}

   		for (m = (n + 1) / 2; m <n; ++m)
   		{
   			 printf("%d ",a[m]);
   		}
	}
	return 0;
}