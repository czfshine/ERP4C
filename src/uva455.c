#include "stdio.h"
#include "string.h"
/* error
	about the 描述
*/
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		char s[81];
		scanf("%s",s);
		int len=strlen(s);
		int j;
		for (int i = 1; i <len/2; ++i)
		{
			for (j = 0; j < len-i; ++j)
			{
				if(s[j]!=s[j+i]) break;
			}
			if(j==len-i){
				printf("%d\n\n",i);
				break;
			}else{
				printf("%d\n\n",len);//wtf???
			}
		}

	}
	return 0;
}