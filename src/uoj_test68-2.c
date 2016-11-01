#include "stdio.h"
#define PI 3.14159
int main(int argc, char const *argv[])
{
	double r,h;
	scanf("%lf%lf",&r,&h);
	printf("%.3lf",PI*r*r*2+PI*r*2*h);
	return 0;
}