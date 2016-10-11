#include "stdio.h"
//TODO
int main(int argc, char const *argv[])
{
	double f=2,s=1,t=3;
	double sum;
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		sum+=f/s;
		t=f+s;
		s=f;
		f=t;
	}
	printf("%.4f",sum);
	return 0;
}