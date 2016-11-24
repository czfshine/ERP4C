#include "stdio.h"

int main(int argc, char const *argv[])
{
	char ch;
	while((ch=scanf(%c))&& ch!='\n'){

		if(ch>='A' &&ch<='Z' )
			ch+=32;
		printf("%c",ch);
	}
	return 0;
}
