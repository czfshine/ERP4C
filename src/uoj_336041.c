#include "stdio.h"
#include <math.h>
#define min(x,y) x<y?x:y
double dist(double x1,double y1,double x2,double y2){

	return (sqrt(fabs((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))));
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	double x[T],y[T];

	for (int i = 0; i < T; ++i)
	{
	scanf("%lf%lf",x+i,y+i);
	}
	double m;
	m=dist(x[0],y[0],x[1],y[1]);

	for (int i = 0; i < T; ++i)
	{
		for (int j = i+1; j < T; ++j)
		{
			m=min(m,dist(x[i],y[i],x[j],y[j]));
		}
	}
	printf("%.2lf",m);
	return 0;
}