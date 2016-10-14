#include "stdio.h"
int main(int argc, char const *argv[])
{
	int indata[10],count=0;
	double sum=0;
	for(int i=0;i<10;i++) {
		scanf("%d",&indata[i]);
	}

	for (int i = 0; i < 10; ++i)
	{
		sum+=indata[i];
	}

	sum=sum/10.0;

	for (int i = 0; i < 10; ++i)
	{
		if(indata[i]>sum){
			count++;
		}
	}
	printf("%d",count);
	return 0;
}