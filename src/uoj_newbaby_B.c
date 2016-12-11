#include "stdio.h"
int a,b,c;

void sort(){
	int t;
	if(a<b){t=a,a=b,b=t;}
	if(b<c){t=b,b=c,c=t;}
	if(a<c){t=a,a=c,c=t;}
}
int main(int argc, char const *argv[])
{
	int n,m,count=0;

	while(scanf("%d%d",&n,&m)>0){
		count=0;
		a=b=c=n;
		while(a!=m){
			printf("%d %d %d\n",a,b,c);
			count++;
			if(m+b>c&&m+c>b)
				a=m;
			else
				a=b-c+1;
			sort();
		}
		//printf("%d%d%d",a,b,c);
		printf("%d\n",count);
	}
	return 0;
}