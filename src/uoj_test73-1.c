#include "stdio.h"
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
int main(int argc, char const *argv[])
{
	char str[81];
	int i;
	for( i=0;(str[i]=getchar())!='\n';i++);
	if(is(str,i)){
		printf("Y");
	}else{
		printf("N");
	}
	return 0;
}