#include "stdio.h"

int main(int argc, char const *argv[])
{	char ch;
	while((ch=gerchar())!='\n'){
		if(ch!='A')
			printf("%c",ch);
	}
	return 0;
}