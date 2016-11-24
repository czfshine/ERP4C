#include "stdio.h"

int main(int argc, char const *argv[])
{
	char ch;
	for (int i = 0; i < 5; ++i)
	{
		scanf("%c",&ch);
		if(ch>='A' &&ch=<'Z' )
			ch+=32;
		printf("%c",ch);
	}
	return 0;
}