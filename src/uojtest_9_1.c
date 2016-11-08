#include "stdio.h"

int F(int x){
	if(x<3) return x;
	if(x%3==0) return F(x/3)*2  ;
	if(x%3==1) return F((x-1)/3)+1 ;

	return F((x-2)/3)+2 ;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	printf("%d",F(n));
	return 0;
}