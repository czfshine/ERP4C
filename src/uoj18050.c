/*

**************************************
18050 打印三角形
**************************************
Description

编写程序，输入整数n，输出n行的字符图案。例如n=5时输出：

    *

   **

  ***

 ****

*****

 ****

  ***

   **

    *




**************************************
Input

输入一个整数
**************************************
Output

输出2*n-1行的三角形
**************************************
Sample Input

2
**************************************
Sample Output

 *

**

 *
**************************************
Author0*/
//like uoj1035 :)
#include "stdio.h"	

int main(int argc, char const *argv[])
{
	
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n-i; ++j)
		{
			printf(" ");
		}
		for (int k = 0; k < i+1 ; ++k)
		{
			printf("*");
		}
		
		printf("\n");

	}

	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < i+1; ++j)
		{
			printf(" ");
		}
		for (int k = 3; k < (n-i)+2 ; ++k)
		{
			printf("*");
		}
		
		printf("\n");

	}

	return 0;
}