/*

**************************************
1020 正负奇偶判断
**************************************
Description
由键盘输入非零整数x，判断该数正负，正数输出positive，负数输出negative，接着判断该数的奇偶性，奇数输出odd，偶数输出even。
**************************************
Output
注意，正负判断结果与奇偶判断结果之间用回车符分隔
**************************************
Sample Input
-43
**************************************
Sample Output

negative

odd


**************************************
Author0*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a ;
	scanf("%d",&a);
	printf("%s\n%s",a>0?"positive":"negative",a%2==0?"even":"odd");
	return 0;
}