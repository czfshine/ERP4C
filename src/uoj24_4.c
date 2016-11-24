#include "stdio.h"

int main(int argc, char const *argv[])
{
	int data[20];
	for (int i = 0; i < 20; ++i)
	{
		scanf("%d",data+i);
	}

	for (int i = 0; i < 20; ++i)
	{
		for (int j = i; j < 20; ++j)
		{
			if(data[i]<data[j])
			{
				int tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;
			}
		}
	}
	int count =0;
	for (int i = 1; i < 20; ++i)
	{
		if(data[i]!= data[i-1])
			count ++;
	}

	printf("%d",count);
	return 0;
}
