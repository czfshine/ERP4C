#include "stdio.h"
#include "string.h"

char cmp(char * str,int s,int e){
	int len=strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if(str[(s+i)%len]!=str[(e+i)%len])
			return str[(s+i)%len]<str[(e+i)%len];
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	char str[81];
	while(T--){
		scanf("%s",str);
		int re=0;
		int count=strlen(str);
		for (int i = 0; i < count; ++i)
		{
			if(cmp(str,i,re)) re=i;
		}

		for (int i = 0; i < count; ++i)
		{
			putchar(str[(re+i)%count]);
		}
		putchar('\n');
	}

	return 0;
}