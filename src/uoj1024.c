/*

**************************************
1024 计算阶乘
**************************************
Description
输入正整数n（n<12），计算n!（注n!=1*2*3*...*n）
**************************************
Sample Input
3
**************************************
Sample Output
6
**************************************
Author0*/
#include "stdio.h"
int f(int n){
	if(n==1)
		return 1;
	else
		return f(n-1)*n;
}
int main(int argc, char const *argv[])
{
	int max;
	scanf("%d",&max);
	printf("%d",f(max));
	return 0;
}