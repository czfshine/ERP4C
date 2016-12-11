#include "stdio.h"
/*
 测试数据用例 No.2

标准输入数据:
22 4
57 27
61 3
5 4
   1|6
   2|4
   3|9
   4|3


你的错误输出结果:
   1|8
   2|4
   3|31
   4|3
*/

/*

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
*/
#define min(x,y) (x)<(y)?(x):(y)
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
		a=b=c=m;
		while(c!=n){
			printf("%d %d %d\n",a,b,c);
			c=min(a+b-1,n);
			sort();
		}


	}

	return 0;
}