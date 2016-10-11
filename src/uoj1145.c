#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	char str[81];
	int len,fail=0;
	
	scanf("%s",str);
	len=strlen(str);
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
		printf("N");
	}else{
		printf("Y");
	}
	
	return 0;
}