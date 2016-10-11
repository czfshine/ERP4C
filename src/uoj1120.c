#include "stdio.h"

int main(int argc, char const *argv[])
{
	double x,y;

	scanf("%lf,%lf",&x,&y);

	if(0.999<x*x+y*y&&x*x+y*y<1.001){printf("Y");}else{printf("N");}
	return 0;
}