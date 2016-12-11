#include "stdio.h"
#include <stdlib.h>
#define min(x,y) x<y?x:y
int main(int argc, char const *argv[])
{
	long long  a,n,flag=0;
	scanf("%lld",&n);
	a=n*n;
	for (long long  i =a%2?1:2; i < a; i+=2)
	{

		if((a%i)==0){
			//printf("%d %d\n",a,i);
			long long c=(i+a/i)/2;
			long long b=abs((i-a/i)/2);
			if(b*b+a==c*c&& b!=0)
				if((n<b&&n<c)&&(n+b>c&&n+c>b&&b+c>n)){
					printf("%lld %lld",b,c);
					flag=1;
					break;
				}
		}

	}

	if(!flag) printf("N0");
	return 0;
}