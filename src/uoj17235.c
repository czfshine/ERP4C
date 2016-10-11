#include <stdio.h>
#include "math.h"
#define PI 3.141592653
int main(int argc, char const *argv[])
{
	double s,A,v,t,r,x,y,T,t0;
	scanf("%lf%lf%lf%lf%lf",&s,&A,&v,&t,&r);
	A=A/180.0*PI;
	t0=v*sin(A)/10.0*2.0;
	if(t>t0){
			x=v*cos(A)*t0;
			y=0.0;
		}else{
			x=v*cos(A)*t;
			y=v*sin(A)*t-10.0*t*t/2.0;
	}
	if(((x-s)*(x-s)+y*y)<=r*r){
		printf("nice!");
	}else{
		printf("T^T");
	}

	return 0;
}