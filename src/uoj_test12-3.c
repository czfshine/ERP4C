#include <stdio.h>
float f(int n)
{
	if(n==0 || n==1)
		return 1;
	else if(n>1)
		return f(n-1)*n;
	return 1;
}
int main()
{
	int m,n,s;
	scanf("%d%d",&m,&n);
	s=f(m)/(f(n)*f(m-n));
	printf("%d\n",s);
	return 1;
}
