#include <stdio.h>

int main(){
	long n,m,a,x,y;
	scanf("%d%d%d",&n,&m,&a);
	x=(n-(n%a))/a;
	if (n%a){x++;}
	y=(m-(m%a))/a;
	if (m%a){y++;}
	printf("%d",x*y);
		return 0;
}