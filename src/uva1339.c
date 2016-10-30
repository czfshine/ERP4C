#include "stdio.h"
#include <string.h>
int main(int argc, char const *argv[])
{
	char s1[101],s2[101];
	int temp,i,f=0;
	while(scanf("%s",s1)!=EOF){
		scanf("%s",s2);
		if(f){
			printf("\n");
		}
		f=1;
		int c1[26]={0},c2[26]={0};
		if(strlen(s1) != strlen(s2))
		{
			printf("NO");
			continue;
		}

		for (i = 0; i < strlen(s1); ++i)
			c1[s1[i]-'A']++;
		for (i = 0; i < strlen(s2); ++i)
			c2[s2[i]-'A']++;
		for ( i = 0; i < 26; ++i)
		{
			for (int j = i; j < 26; ++j)
			{
				if(c1[i]>c1[j])
					temp=c1[i];c1[i]=c1[j];c1[j]=temp;
				if(c2[i]>c2[j])
					temp=c2[i];c2[i]=c2[j];c2[j]=temp;
			}
		}
		for ( i= 0; i < 26; ++i)
			if(c1[i]!=c2[i])
				break;
		if(i==26)
			printf("YES");
		else
			printf("NO");
	}
	return 0;
}