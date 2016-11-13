/*

**************************************
18048 自由落体
**************************************
Description

一个球从100米的高度自由落下，每次落地后弹起的原来高度的一半。计算并输出第n次落地时，共经过了多少米，第n次弹起的高度是多少?结果显示3位小数。
**************************************
Input

从键盘输入一个数n（n>0）
**************************************
Output

输出两个数，分别为共经过的米数和第n次弹起的高度，以一个空格分隔


**************************************
Sample Input

1
**************************************
Sample Output

100.000 50.000


**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	double h=100.0,sumh=0.0;
	int n,i;

	scanf("%d",&n);

	for (i=0;i<n;i++){
		sumh+=h*2;
		h/=2.0;
	}
	sumh-=100.0;
	printf("%.3lf %.3lf",sumh,h);
	return 0;
}