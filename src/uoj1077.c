#include "stdio.h"
int main(int argc, char const *argv[])
{
	int d[8],b[8];

	for (int i = 0; i < 8; ++i)
	{
		scanf("%d",d+i);
	}

	for (int i = 0; i < 8; ++i)
	{
		scanf("%d",b+i);
	}


	int x,y;

	x=d[0];
	y=b[0];

	for (int j = 1; j < 8; ++j)
	{
		y-=b[j];
		if(y<0) y=b[j]+y;
		x*=d[j];
		y*=d[j];
	}
	printf("%d",(x+y+1)%;
	return 0;
}