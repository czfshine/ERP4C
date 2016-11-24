#include "stdio.h"

int main(int argc, char const *argv[])
{
	int data[20];
	for (int i = 0; i < 20; ++i)
	{
		scanf("%cd",data+i);
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
	for (int i = 0; i < 20; ++i)
	{
		printf("%d ",data[i]);
	}
	return 0;
}
