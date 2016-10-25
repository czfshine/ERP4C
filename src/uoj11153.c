#include "stdio.h"

int main(int argc, char const *argv[])
{
	int m,n,d;
	scanf("%d %d %d",&m,&n,&d);
	int a[d],b[d];
	for (int i = 0; i < d; ++i)
	{
		scanf("%d",a+i);
	}
	for (int i = 0; i < d; ++i)
	{
		scanf("%d",b+i);
	}

	for (int i = 0; i < d; ++i)
	{	
		if(n<=0 || m<=0)
			break;
		if(a[i]>0&&b[i]>0){
			if(a[i]>b[i]){
				m-=a[i];
			}else{
				if(a[i]<b[i])
					n-=b[i];
			}
			continue;
		}

		if(a[i]>0&&b[i]<0){
			if(a[i]+b[i]>0)
				m-=a[i];
			continue;
		}
		if(a[i]<0 &&b[i]>0){
			if(a[i]+b[i]>0)
				n-=b[i];
			continue;
		}

	}
	if(m<=0){
		printf("boss");
	}else{
		if(n<=0){
		printf("acmer");
	}else{
		printf("impossible");
	}
	}
	//printf("%d,%d",n,m);
	return 0;
}