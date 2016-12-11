#include "stdio.h"

int f(int n){
	if(n==1)return 1;
	return f(n-1)*n;
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&m,&n);
	if(n>m){n=m-n;}
	printf("%d",f(m)/f(m-n)/f(n));
	return 0;
}