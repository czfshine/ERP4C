#include "stdio.h"
int main(int argc, char const *argv[])
{
	int a,b,c,n;
	scanf("%d",&n);
	for (a=1;a<=n;a++){
		for (int b = a; b < n+1; ++b)
		{
			for (int c = b; c < n+1; ++c)
			{
				if(a*a+b*b == c*c){
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
	return 0;
}