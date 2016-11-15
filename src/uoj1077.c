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

	for (int i = d[0]+b[0]; ; i+=d[0])
	{
		for (int j = 1; j < 8; ++j)
		{
			if(i%d[j]!=b[j]){
				break;
			}
		}
		if(j==8){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}