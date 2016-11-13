/*

**************************************
10303 数字三角（必做）
**************************************
Description

问题描述：给定一个由n行数字组成的数字三角形，如下图所示。试用动态规划算法，计算出从三角

顶部至底部的一条路径，使得该路径经过的数字总和最大。



注意每个数字只能走向下一行左边或右边的数字，而不能跳跃的走。
**************************************
Input         7
**************************************
Output      3   8
**************************************
Sample Input    8   1   0
**************************************
Sample Output  2   7   4   4
**************************************
Hint4   5   2   6   5
**************************************
Author

第一行是数字三角的行数n，1<=n<=100。接下来n行是数字三角各行中的数字，所有数字在0~99之间。0*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max(x,y) (x)>(y)?(x):(y)
int n,d[100][100],a[100][100],j=0;
int solve(int i, int j){    
	if(d[i][j] >= 0) return d[i][j];    
	return d[i][j] = a[i][j] +(i == n ? 0 : max(solve(i+1,j),solve(i+1,j+1)));
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i = 0; i <n; ++i)
		for (int k = 0; k <= i; ++k)
			scanf("%d",&a[i][k]);
	memset(d,-1,sizeof(d));
	printf("%d\n",solve(0,0));
	for (int i = 0; i <n; ++i){	
		printf("%d ",a[i][d[i][j]>d[i][j+1]?j:j++]);
	return 0;
}
}
