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
				double temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}
	double min=data[0]-data[1];

	for (int i = 0; i < 9; ++i)
	{	//printf("%lf",data[i]);
		if(data[i]-data[i+1] <min){
			min=data[i]-data[i+1];
		}
	}
	printf("%.2lf",min);
	return 0;
}