#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int* getMatrix  (int c,int r){
	int* data;
	data=(int*)malloc(4*c*r);
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			scanf("%d",data+i*r+j);
		}
	}

	return data;
}
	
int main(int argc, char const *argv[])
{
	int *data;
	data=getMatrix(4,3);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ",*(data+j*4+i));
		}
		printf("\n");
	}
	return 0;
}