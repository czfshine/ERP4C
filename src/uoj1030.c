#include "stdio.h"
int main(int argc, char const *argv[])
{
	char str[80];
	gets(str);

	for (int i = 0; i < 80; ++i)
	{
		if(str[i]>64 &&str[i]<91){str[i]+=32;}
	}
	printf("%s",str);
	return 0;
}