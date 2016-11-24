/*
描述
由键盘输入一个句子（字符个数不定，最多不超过80个，以'\n'结束），将其中的大写字符变成小写（其它类型的字符不变），
最后输出变换后的句子。

输入样例
ThiS IS My fIrSt C ProgrAm!
输出样例
this is my first c program!
*/
#include "stdio.h"

int main(int argc, char const *argv[])
{
	char ch;
	while((scanf("%c",&ch))&& ch!='\n'){

		if(ch>='A' &&ch<='Z' )
			ch+=32;
		printf("%c",ch);
	}
	return 0;
}
