#include "stdio.h"
#include <math.h>
int main(int argc, char const *argv[])
{
	double a,xn=1,xn1;
	scanf("%lf",&a);

	while(fabs(xn-xn1)>=1e-5){
		xn1=xn;
		xn=0.5*(xn+a/xn);

	}

	printf("%.4lf",xn);

	return 0;
}