#include <stdio.h>
char has5(int n){
	char a,b,c,d;

	a=(n-(n%1000))/1000;
	n=n-a*1000;
	b=(n-(n%100))/100;
	n=n-b*100;
	c=(n-(n%10))/10;
	n=n-c*10;
	d=n;
	if(a==5 || b==5 ||c==5 ||d==5) return 1;
	return 0;


}
int main(int argc, char const *argv[])
{
	int n;
	for (int i = 1; i < 1429; ++i)
	{
		n=i*7;
		if(has5(n)) printf("%d\n",n);

	}
	return 0;
}