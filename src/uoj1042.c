#include "stdio.h"
int main(int argc, char const *argv[])
{
	int m,sum_m=0,sum_b=0,day=0,b=1;
	scanf("%d",&m);
	sum_m+=m;
		sum_b+=b;
		b*=2;
		day++;
	while(sum_b<=sum_m*100){
		sum_m+=m;
		sum_b+=b;
		b*=2;
		day++;
	}
	printf("%d",day);
	return 0;
}