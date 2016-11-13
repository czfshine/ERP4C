#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max(x,y) (x)>(y)?(x):(y)
int n,d[100][100],a[100][100],j=0;
int solve(int i, int j){    
	if(d[i][j] >= 0) return d[i][j];    
	return d[i][j] = a[i][j] +(i == n ? 0 : max(solve(i+1,j),solve(i+1,j+1)));
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i = 0; i <n; ++i)
		for (int k = 0; k <= i; ++k)
			scanf("%d",&a[i][k]);
	memset(d,-1,sizeof(d));
	printf("%d\n",solve(0,0));
	for (int i = 0; i <n; ++i){	
		printf("%d ",a[i][d[i][j]>d[i][j+1]?j:j++]);
	return 0;
}
}
