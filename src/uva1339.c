#include "stdio.h"
#include <string.h>
int main(int argc, char const *argv[])
{
	int c1[26]={0},c2[26]={0};
	char s1[101],s2[101];
	int temp;
	while(scanf("%s",s1)!=EOF){
		printf("YES");
		scanf("%s",s2);

		for (int i = 0; i < strlen(s1); ++i)
			c1[s1[i]-'A']++;
		for (int i = 0; i < strlen(s2); ++i)
			c2[s2[i]-'A']++;

		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if(c1[i]>c1[j]){
					temp=c1[i];c1[i]=c1[j];c1[j]=temp;
				}
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if(c2[i]>c2[j]){
					temp=c2[i];c2[i]=c2[j];c2[j]=temp;
				}
			}
		}
		int i;
		for ( i= 0; i < 26; ++i)
		{
			if(c1[i]!=c2[i])
				break;
		}
		if(i==26){
			printf("YES");
		}else{
			printf("NO");
		}
		
	}

	return 0;
}