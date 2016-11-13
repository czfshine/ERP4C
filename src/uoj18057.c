/*

**************************************
18057 ASCII码值之和的差
**************************************
Description

输入两个字符串s1和s2(每个串占一行，以换行回车符结束)，计算两个字符串的所有字符的ASCII码值之和的差。
**************************************
Input

两行字符，第行字符不超过80个字符
**************************************
Output

ASCII码值之和的差
**************************************
Sample Input

234

123


**************************************
Sample Output

3
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	char str[81],ch,cur=0;
	int sum1=0,sum2=0;
	while((ch=getchar())!='\n')
		str[cur++]=ch;
	for (int i = 0; i < 81; ++i)
	{
		if(i==cur) break;
		sum1+=str[i];
	}
	cur=0;
	while((ch=getchar())!='\n')
		str[cur++]=ch;
	for (int i = 0; i < 81; ++i)
	{
		if(i==cur) break;
		sum2+=str[i];
	}
	printf("%d",sum1-sum2);
	return 0;
}