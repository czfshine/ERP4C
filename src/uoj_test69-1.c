#include "stdio.h"
int main(int argc, char const *argv[])
{
	double a,t;
	scanf("%lf %lf",&a,&t);
	printf("%.2lf",0.5*a*t*t);
	return 0;
}