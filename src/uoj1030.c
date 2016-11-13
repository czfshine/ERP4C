/*

**************************************
1030 字符变换
**************************************
Description

由键盘输入一个句子（字符个数不定，最多不超过80个，以'\n'结束），将其中的大写字符变成小写（其它类型的字符不变），

最后输出变换后的句子。
**************************************
Sample Input

ThiS IS My fIrSt C ProgrAm!
**************************************
Sample Output

this is my first c program!
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	char str[80];
	gets(str);
	for (int i = 0; i < 80; ++i)
		if(str[i]>64 &&str[i]<91)
			str[i]+=32;
	printf("%s",str);
	return 0;
}