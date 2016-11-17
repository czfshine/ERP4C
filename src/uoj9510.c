#include "stdio.h"
#define min(x,y) x<y?x:y
//todo
int main(int argc, char const *argv[])
{
	int a,b,c;

	scanf("%d%d%d",&a,&b,&c);
	int m=min(min(a,b),c);

	a-=m;b-=m;c-=m;
	int sum=0;
	if(a==0){
		int n1=b/2;
		int n2=c/2;
		int n3=b%2+c%2;
		sum=n1+n2+n3+m;
	}else if(b==0){

		int n1=a/3;
		int n2=c/2;

		int n3=a%3+c%2;
		sum=n1+n2+n3+m;

	}else{

		int n1=min(a/2,b);

		a-=n1*2;
		b-=n1;

		int n2=a/3;
		int n3=b/2;

		int n4=a%3+b%2;

		sum=n1+n2+n3+n4+m;
	}

	printf("%d",sum);

	return 0;
}