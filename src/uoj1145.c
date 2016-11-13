/*

**************************************
1145 回文串
**************************************
Description

读入一行字符串（不多于80个字符，以回车结束），判断该字符串是否为回文串（即从左向右拼写与从



右向左拼写是一样的），是则输出Y，不是则输出N。
**************************************
Input

一行字符串
**************************************
Output

是则输出Y，不是则输出N
**************************************
Sample Input

abba
**************************************
Sample Output

Y
**************************************
Hint

或

input:

abcba



output:

Y



或

input:

abc



output:

N


**************************************
Author0*/
#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	char str[81];
	int len,fail=0;
	
	scanf("%s",str);
	len=strlen(str);
	if((len%2)==0){
		for (int i = 0; i < len/2; ++i)
		{
			if(str[i]==str[len-i-1]){}else{fail=1;}
		}
	}else{
		for (int i = 0; i < (len-1)/2; ++i)
		{

			if(str[i]==str[len-i-1]){}else{fail=1;}
		}
	}

	if(fail){
		printf("N");
	}else{
		printf("Y");
	}
	
	return 0;
}