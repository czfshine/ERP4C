#include "stdio.h"
//todo
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	int data[n+1];
	long long t=1;
	while(1){
		if(n<t)
			break;
		t=t<<1;
	}
	t=t>>1;
	printf("%d ",t);
	data[1]=1;
	for (int i = 2; i <= n; ++i)
		data[i] = (data[i-1]+m-1)%i + 1;

	printf("%d",data[n]);
	return 0;
}
