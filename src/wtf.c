#include "stdio.h"

int main(int argc, char const *argv[])
{
	char str[81];
	int a[81]={0},i=0;
	scanf("%s",str);
	while(str[i]!='\0')
	{
		a[i]=str[i]-'0';
		i++;
	}

	for ( i = 0; i < 81; ++i)
	{
		printf("a[%03d]=%03d\n",i,a[i]);
	}


	return 0;
}