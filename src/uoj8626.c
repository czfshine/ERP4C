#include "stdio.h"
#include <string.h>
#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01
//todo
int getnum(char * str,int *cur){
	int sum=0;
	for (;;)
	{	
		(*cur)++;
		printf("%d",*cur);
		if(str[*cur]>='0' &&str[*cur]<='9'){
			sum=sum*10+(str[*cur]-'0');
			

		}else{
			return sum;
		}
	}
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	char str[101];
	for (int i = 0; i < T; ++i)
	{
		scanf("%s",str);

		int cur=0,len=strlen(str),n=0;
		double sum=0;
		while(cur<=len){
			switch(str[cur]){
				case 'C':n=getnum(str,&cur);sum+=n*C;break;
				case 'N':n=getnum(str,&cur);sum+=n*N;break;
				case 'H':n=getnum(str,&cur);sum+=n*H;break;
				case 'O':n=getnum(str,&cur);sum+=n*O;break;
			}
			printf("%lld",sum);
		}

		printf("%lld",sum);
	}
	return 0;
}