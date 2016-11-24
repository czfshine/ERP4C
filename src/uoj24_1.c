/*
描述
由键盘输入5个字符，将其中的大写字符变成小写（其它类型的字符不变），最后，按输入顺序输出这5个字符。

输入样例
ApPLe
输出样例
apple*/

#include "stdio.h"

int main(int argc, char const *argv[])
{
	char ch;
	for (int i = 0; i < 5; ++i)
	{
		scanf("%c",&ch);
		if(ch>='A' &&ch<='Z' )
			ch+=32;
		printf("%c",ch);
	}
	return 0;
}