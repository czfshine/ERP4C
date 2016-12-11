#include <stdio.h>
float f(int n)
{
	if(n==0 || n==1)
		return 1;
	else if(n>1)
		return f(n-1)*n;
	return 1;
}
void main()
{
	int m,n,s;
	scanf("%d%d",&m,&n);
	s=fun(m)/(fun(n)*fun(m-n));
	printf("%d\n",s);
}