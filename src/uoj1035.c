/*

**************************************
1035 打印菱形图案
**************************************
Description
由键盘输入正数n（n<30），要求输出如下2*n+1行的菱形图案。
**************************************
Output
菱形右边不留多余空格
**************************************
Sample Input
2
**************************************
Sample Output

  *

 ***

*****

 ***

  *


**************************************
Author0*/
#include "stdio.h"	
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	n++;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n-i; ++j)
			printf(" ");
		for (int k = 0; k < i*2+1 ; ++k)
			printf("*");
		printf("\n");
	}
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < i+1; ++j)
			printf(" ");
		for (int k = 3; k < (n-i)*2 ; ++k)
			printf("*");
		printf("\n");
	}
	return 0;
}