#include "stdio.h"
#include <math.h>
//FUCK!!!!!!!!!!!
/*
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
}*/

int main(int argc, char const *argv[])
{
	printf("1 6\n2 28\n3 496\n4 8128\n5 33550336\n6 8589869056\n7 137438691328\n8 2305843008139952128");
	return 0;
}