#include "stdio.h"
int main(int argc, char const *argv[])
{
	double h=100.0,sumh=0.0;
	int n,i;

	scanf("%d",&n);

	for (i=0;i<n;i++){
		sumh+=h*2;
		h/=2.0;
	}
	sumh-=100.0;
	printf("%.3lf %.3lf",sumh,h);
	return 0;
}