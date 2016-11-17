#include "stdio.h"
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
	data=getMatrix(3,4);

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ",*(data+i*3+j));
		}
		printf("\n")
	}
	return 0;
}