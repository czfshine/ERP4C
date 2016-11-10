#include "stdio.h"
//todo
int main(int argc, char const *argv[])
{
	int n,m=3;
	scanf("%d%d",&n);
	int data[n+1];
	data[1]=1;
	for (int i = 2; i <= n; ++i)
		data[i] = (data[i-1]+m-1)%i + 1;
	printf("%d",data[n]);
	return 0;
}