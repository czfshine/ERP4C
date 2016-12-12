#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void f(int n,char * str){
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
					sprintf(str,"%lld %lld",b,c);
					flag=1;
					break;
				}
		}

	}
	if(!flag) printf("N0");
}

void s (int n,char * str){
	if(n>=5){
	if(n%2==0){
		sprintf(str,"%d %d",n*n/4-1,n*n/4+1);
	}else{
		sprintf(str,"%d %d",n*n/2,n*n/2+1);
	}}
	else{
		if(n==4||n==2||n==1){
			sprintf(str,"NO");
		}else
		{
			sprintf(str,"4 5");
		}
	}
}
int main(int argc, char const *argv[])
{	char s1[100],s2[100];
	for (int i = 1; i < 10001; ++i)
	{
		//printf("----%d----",i);
		f(i,s1);
//printf("\n");
		s(i.s2);
		//、、printf("\n");
		if(strcmp(s1,s2)!==0)
				printf("%d",i);
	}
	return 0;
}