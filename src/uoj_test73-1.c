#include "stdio.h"
#include <string.h>
int is(char * str,int len){
	int fail=0;
	if((len%2)==0){
		for (int i = 0; i < len/2; ++i)
		{
			if(str[i]==str[len-i-1]){}else{fail=1;}
		}
	}else{
		for (int i = 0; i < (len-1)/2; ++i)
		{
			if(str[i]==str[len-i-1]){}else{fail=1;}
		}
	}

	if(fail){
		return 0;
	}else{
		return 1;
	}
}
void newstr(char * str,char * out,int len,int index){
	int i=0,j=0;
	memset(out,0,81);
	for (int i = 0; i < len; ++i)
	{
		if(i!=index){
			out[j]=str[i];
			j++;
		}
	}
}
int main(int argc, char const *argv[])
{
	char str[81]={0},out[81]={0};
	int i,Y=0;
	for( i=0;(str[i]=getchar())!='\n';i++);
	if(is(str,i))
		Y=1;
	for (int j = 0; j < i; ++j)
	{
		newstr(str,out,i,j);
		//printf("%s",out);

		if(is(out,i-1))
			Y=1;
	}

	if(Y)
		printf("Y");
	else
		printf("N");
	return 0;
}