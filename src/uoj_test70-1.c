#include "stdio.h"
#include "math.h"
int main(int argc, char const *argv[])
{
	int n,count=0;
	scanf("%d",&n);
	for (int i = 1; i <=n; ++i)
	{
		if(n%i==0) {
			count++;
			//n/=i;
		}
	}
	printf("%d",count);
	return 0;
}