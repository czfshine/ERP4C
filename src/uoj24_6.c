#include <stdio.h>
#include "math.h"

#define min(x,y) (x)>(y)?(x):(y)
double dist(int x ,int y,int dx,int dy){

	return sqrt(fabs((dx-x)*(dx-x)+(dy-y)*(dy-y)));
}
int main(int argc, char const *argv[])
{
	int data[50][2];
	int T=0;
	scanf("%d",&T);
	for (int i = 0; i < T; ++i)
	{
		scanf("%d%d",&data[i][0],&data[i][1]);
	}

	double m=dist(data[0][0] ,data[0][1],data[1][0],data[1][1]);
	printf("%lf",m);
	for (int i = 0; i < T; ++i)
	{
		for (int j = 0; j < T; ++j)
		{
			if(i!=j){
				m=min(dist(data[i][0] ,data[i][1],data[j][0],data[j][1]),m);
				printf("%lf",m);
			}
		}
	}
		
		printf("%lf",m);
	return 0;
}