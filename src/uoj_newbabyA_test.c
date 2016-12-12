#include "stdio.h"

void f(int n){
	long long  a,flag=0;
	a=n*n;
	for (long long  i =1; i < a; i++)
	{

		if((a%i)==0){
			//printf("%d %d\n",a,i);
			long long c=(i+a/i)/2;
			long long b=abs((i-a/i)/2);
			if(b*b+a==c*c&& b!=0)
				if((n<b&&n<c)&&(n+b>c&&n+c>b&&b+c>n)){
					printf("%lld %lld",b,c);
					flag=1;
					break;
				}
		}

	}
	if(!flag) printf("N0");
}

void s (int n){
	if(n>=5){
	if(n%2==0){
		printf("%d %d",n*n/4-1,n*n/4+1);
	}else{
		printf("%d %d",n*n/2,n*n/2+1);
	}}
	else{
		if(n==4||n==2||n==1){
			printf("NO");
		}else
		{
			printf("4 5");
		}
	}
}
int main(int argc, char const *argv[])
{
	for (int i = 1; i < 10001; ++i)
	{
		printf("----%d----",i);
		f(i);
		printf("\n");
		s(i);
		printf("\n");
	}
	return 0;
}