#include "stdio.h"
//todo
void s(char * a,char *b){
	char t=*a;
	*a=*b;
	*b=*a;
}
void p(char * str,int k,int m){
	if((k>m)&&(str[m]>str[0])){
		for (int i = 0; i <=m; ++i)
		{
			printf("%c",str[i]);
		}
		printf("\n");
	}else{

		for (int i = k; i <=m; ++i)
		{
			s(str+k,str+i);
			p(str,k+1,m);
			s(str+k,str+i);
		}
	}

}
int main(int argc, char const *argv[])
{
	
	char str[10]={0};
	int n;
	scanf("%d",&n);
	getchar();
	for (int i = 0; i < n-1; ++i)
	{
		str[i]=getchar();
	}
	p(str,0,n-1);
	return 0;
}