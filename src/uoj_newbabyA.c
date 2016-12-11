#include "stdio.h"
#include <stdlib.h>
#define min(x,y) x<y?x:y
int main(int argc, char const *argv[])
{
	int a,n,flag=0;
	scanf("%d",&n);
	a=n*n;
	for (int i =a%2?1:2; i < a; i+=2)
	{

		if((a%i)==0){
			//printf("%d %d\n",a,i);
			int c=(i+a/i)/2;
			int b=abs((i-a/i)/2);
			if(b*b+a==c*c&& b!=0)
				if((n<b&&n<c)&&(n+b>c&&n+c>b&&b+c>n)){
					printf("%d %d",b,c);
					flag=1;
					break;
				}
		}

	}

	if(!flag) printf("N0");
	return 0;
}