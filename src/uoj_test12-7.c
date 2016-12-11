#include "stdio.h"
#include "math.h"
#define min(x,y) (x)<(y)? (x):(y)
int main(int argc, char const *argv[])
{
	float data[10];
	for (int i = 0; i < 10; ++i)
	{
		scanf("%f",data+i);
	}
	float m=fabs(data[1]-data[0]);
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			m=min(m,fabs(data[i]-data[j]));
		}
	}
	printf("%.2f",m);
	return 0;
}