#include "stdio.h"
//todo
void p(char * str,int len){
	
	for (int i =0 ; i<len; ++i)
	{
		p(str,len-1-i);
		
	}
	printf("%c",str[len-1]);
}
int main(int argc, char const *argv[])
{
	
	char str[10]={0};
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n-1; ++i)
	{
		str[i]=getchar();
	}
	p(str,n);
	return 0;
}