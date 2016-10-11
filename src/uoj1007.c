#include "stdio.h"
#include <math.h>
int main(int argc, char const *argv[])
{
	double a;/* don't use this !!! :)*/
	scanf("%lf",&a);
	printf("%s",sqrt(a)*sqrt(a)==a?"Y":"N");
	return 0;
}