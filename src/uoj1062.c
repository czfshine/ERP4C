/*

**************************************
1062 打印矩阵
**************************************
Description

由键盘输入一个3＊4的矩阵，要求输出它的转置矩阵。
**************************************
Input
3行4列的矩阵，数与数之间由一个空格分隔
**************************************
Output
4行3列的矩阵，数与数之间由一个空格分隔
**************************************
Sample Input

1 6 9 3

1 1 0 2

1 9 8 9


**************************************
Sample Output

1 1 1

6 1 9

9 0 8

3 2 9


**************************************
Author0*/
#include "stdio.h"
#define M 3
#define N 4

int main(int argc, char const *argv[])
{
	int data[M][N];
	int dataT[N][M];
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d",&dataT[j][i]);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%d ",dataT[i][j]);
		}
		printf("\n");
	}
	return 0;
}