#include "stdio.h"
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int data[n],ma,mi;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",data+i);
	}
	ma=0;
	for (int i = 0; i < n; ++i)
	{	mi=data[i];
		for (int j = i; j <n; ++j)
		{
			mi=min(mi,data[j]);
			ma=max(ma,(j-i+1)*mi);
			//printf("%d %d \n",mi,ma);
		}
	}
	printf("%d",ma);
	return 0;
}