#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	char s[81];
	while(T--){
		scanf("%s",s);
		//printf("%s",s);
		int O=0,S=0;
		for (int i = 0; i < strlen(s); ++i)
		{
			if(s[i]=='O'){
				O++;
				S+=O;
			}else{
				O=0;
			}
		}

		printf("%d\n",S);
	}
	return 0;
}