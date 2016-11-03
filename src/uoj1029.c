#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,m;
	int r;
	scanf("%d,%d",&n,&m);
	n>m?r=n,n=m,m=r:,;
	while(n%m){
		r=m%n;
		m=n;
		n=r;
	}
	printf("%d",m);
	return 0;
}