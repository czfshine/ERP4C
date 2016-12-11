#include "stdio.h"
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int a;
	scanf("%d",&a);
	a=a*a;
	for (int i =a%2; i < a; i+=2)
	{
		if(a%i==0){
			int c=(i+a/i)/2;
			int b=abs((i-a/i)/2);
			if(b*b+a==c*c&& b!=0)
				printf("%d %d\n",b,c);
		}

	}
	
	return 0;
}