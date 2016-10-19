#include "stdio.h"
#define max(x,y) (x)>(y)?x:y
#include "stdlib.h"
#include "math.h"
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int data[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",data+i);
	}
	int count=0,c=0;
	int *p,*q;
	for (p =data+n-1; p >=data; --p)
	{	count=0;
		for (q=p;q>=data;--q)
		{
			if(*q<=abs(*p)){
				count++;
			}else{
				break;
			}
		}
		c=max(count,c);
	}

	printf("%d",c);


	return 0;
}