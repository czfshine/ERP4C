#include "stdio.h"
#include <math.h>
//FUCK!!!!!!!!!!!
int main(int argc, char const *argv[])
{	long long i=0,n=2,sum=0,k;
	while(i<8){
		k=sqrt(n);
		sum=1;
		for (long long  j = 2; j <= k; ++j)
		{
			if(n%j==0){
				sum+=j;
				sum+=n/j;
			}
		}
		if(sum==n){
			printf("%lld\n",n);
			i++;
		}
		n++;

	}
	return 0;
}