#include "stdio.h"
int a,b,c;
void sort(){
	int t;
	if(a>b){t=a,a=b,b=t;}
	if(a>c){t=a,a=c,c=t;}
	if(b>c){t=a,a=c,c=t;}
}
int main(int argc, char const *argv[])
{
	int n,m;
	a=1,b=2,c=3;
	printf("%d %d %d",a,b,c);
	sort();
	printf("%d %d %d",a,b,c);
	scanf("%d%d",&n,&m);
	
	a=b=c=n;
	while(a!=m){
		printf("%d %d %d",a,b,c);
		if(m+b>c&&m+c>b){
			a=m;
			sort();
			continue;
		}
		a=b-c+1;
	}
	return 0;
}