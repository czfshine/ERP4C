#include "stdio.h"
#include "string.h"
#include "ctype.h"
int main(int argc, char const *argv[])
{
	char str[31];
	char rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	char s[]="not a palindrome";
	char s2[]="a regular palindrome";
	char s4[]= "a mirrored string";
	char s3[]="a mirrored palindrome";
	int len;
	while(scanf("%s",str)==1){
		len=strlen(str);
		int p = 1, m = 1;
		for (int i = 0; i <(len+1)/2; ++i)
		{
			if(str[i] != str[len-1-i]) p = 0; //不是回文串
			if((isalpha(str[i])?rev[str[i] - 'A']:rev[str[i]- '0' + 25])!= str[len-1-i]) m = 0; //不是镜像串
		}
		printf("%s -- is %s.\n\n", str,p==0?(m==0?s:s4):(m==0?s2:s3));
	}
	return 0;
}