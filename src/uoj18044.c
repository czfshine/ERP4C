/*

**************************************
18044 成绩等级评分
**************************************
Description

编写程序，由键盘输入一个百分制的整数成绩，要求输出对应的成绩等级。90分以上为A，80到89分为B，70到79分为C，60到69分为D，

60分以下为E。成绩不在0到100之间时输出“error”
**************************************
Input

一个整数成绩
**************************************
Output

输出对应的等级或error
**************************************
Sample Input

99
**************************************
Sample Output

A
**************************************
Author0*/
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int s;
	scanf("%d",&s);
	if (s<0 || s>100)
		{printf("error");return 0;}
	if(s>=0 && s<60)
		{printf("E");return 0;}
	if (s<70)
		{printf("D");return 0;}
	if (s<80)
		{printf("C");return 0;}
	if (s<90)
		{printf("B");return 0;}
	if (s<=100)
		{printf("A");return 0;}
	
	

	return 0;
}