#include "stdio.h"
int main(int argc, char const *argv[])
{
	double data[10];
	for (int i = 0; i < 10; ++i)
	{
		scanf("%lf",data+i);
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = i; j < 10; ++j)
		{
			if(data[i]<data[j]){
				int temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%lf",data[i]);
	}
	return 0;
}