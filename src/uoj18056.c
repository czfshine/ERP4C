#include "stdio.h"
int main(int argc, char const *argv[])
{
	char ch;
	int count=0,cn=0;
	while(cn<3){
		ch=getchar();
		if(ch>='A'&&ch<='Z'){
			count++;
		}

		if(ch=='\n'){
			cn++;
		}
	}

	printf("%d",count);
	return 0;
}