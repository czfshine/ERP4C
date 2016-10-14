#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n,sum=0;
	for (int i = 0; i < 12; ++i)
	{
		scanf("%d",&n);
		if(i==0 || i==5 || i== 10){
			sum+=n;
		}
	}

	printf("%d",sum);
	return 0;
}