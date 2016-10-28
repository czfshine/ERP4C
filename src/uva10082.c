#include "stdio.h"
int main(int argc, char const *argv[])
{
	char str[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char ch;
	int i=0;
	while((ch=getchar())!=EOF){
		for (i = 0; i < 47; ++i)
		{
			if(str[i]==ch) {printf("%c",str[i-1]);
				break;
		}

		}
		if(i>46)
			printf("%c",ch);
	}
	return 0;
}