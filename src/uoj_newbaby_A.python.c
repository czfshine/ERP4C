//23333333333333333333
#include "stdio.h"

int main(int argc, char const *argv[])
{	int n;
	scanf("%d",&n);
	if(n==4 or n==2 or n==1)
		printf("NO");
	else
		printf("%d %d",(n%2==0)?(n*n/4-1):(n*n/2),(n%2==0)?(n*n/4+1):(n*n/2+1));
	return 0;
}
