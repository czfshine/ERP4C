#include <stdio.h>
#define MAXLONG 81
#include "string.h"
//TODO
void tonum(char * num){

	for (int i = 0; i < 82; ++i)
	{
		if(num[i]){
			num[i]-=48;
		}
	}
}
void tostr(char * num,int len){

	for (int i = 0; i < len-1; ++i)
	{

			num[i]+=48;
		
	}
	num[len]='\0';
}
int main(int argc, char const *argv[])
{
	char num1[82]={0},num2[82]={0},re[82]={0};

	scanf("%s",num1);
	scanf("%s",num2);
	tonum(num1);
	tonum(num2);
	int len1,len2;

	len1=strlen(num1);
	len2=strlen(num2);

	int a,b,c=0;
	if(len1>len2){
		for (int i = 0; i < len2; ++i)
		{

			a=num1[len2-i-1];
			b=num2[len2-i-1];

			c=((a+b+c)-(a+b+c)%10)/10;
			re[len2-i-1]=(a+b)%10;

			printf("%d,%d,%d\n",a,b,c);
			tostr(re,len2);
			printf("%s\n",re);
			tonum(re);
		}
	}
	tostr(re,len2);
	printf("%s",re);
	return 0;
}