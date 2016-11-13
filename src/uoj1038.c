/*

**************************************
1038 打印图案
**************************************
Description

由键盘输入正数n（n<10），要求输出如下中间数字为n的菱形图案。
**************************************
Output

菱形右边不留多余空格
**************************************
Sample Input

4
**************************************
Sample Output

   1

  121

 12321

1234321

 12321

  121

   1


**************************************
Author0*/
#include "stdio.h"	

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n-i; ++j)
			printf(" ");
		for (int k = 1; k < i+2 ; ++k)
			printf("%d",k);
		for (int k = i; k >=1 ; --k)
			printf("%d",k);
		printf("\n");

	}
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < i+1; ++j)
			printf(" ");
		for (int k = 1; k < (n-i) -1; ++k)
			printf("%d",k);
		for (int k = (n-i)-1; k >=1 ; --k)
			printf("%d",k);
		printf("\n");
	}
	return 0;
}