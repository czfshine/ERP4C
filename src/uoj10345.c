#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	double X[n],a=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",X+i);
		a=(a*i+X[i])/(i+1);
		printf("%.2lf ",a);
	}
	return 0;
}
