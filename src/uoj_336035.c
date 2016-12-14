#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[])
{
	double x;
	scanf("%lf",&x);
	if(x>=0) printf("%.2lf",sqrt(x));
	else printf("%.2lf",x);
	return 0;
}