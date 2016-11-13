/*

**************************************
18055 主对角线上的元素之和
**************************************
Description

输入一个3行4列的整数矩阵，计算并输出主对角线上的元素之和
**************************************
Input

3行4列整数矩阵
**************************************
Output

主对角线上的元素之和
**************************************
Sample Input

1 2 3 4

5 6 7 8

9 10 11 12


**************************************
Sample Output

18


**************************************
Hint

1，6和11
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n,sum=0;
	for (int i = 0; i < 12; ++i)
	{
		scanf("%d",&n);
		if(i==0 || i==5 || i== 10){
			sum+=n;
		}
	}

	printf("%d",sum);
	return 0;
}