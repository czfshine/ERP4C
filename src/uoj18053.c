/*

**************************************
18053 大于平均分
**************************************
Description

输入10个整数，计算它们的平均值，并统计有多少个数比平均值大。
**************************************
Input

10个整数
**************************************
Output

比平均值在的数的个数
**************************************
Sample Input

0 1 2 3 4 5 6 7 8 9


**************************************
Sample Output

5
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	int indata[10],count=0;
	double sum=0;
	for(int i=0;i<10;i++) {
		scanf("%d",&indata[i]);
	}

	for (int i = 0; i < 10; ++i)
	{
		sum+=indata[i];
	}

	sum=sum/10.0;

	for (int i = 0; i < 10; ++i)
	{
		if(indata[i]>sum){
			count++;
		}
	}
	printf("%d",count);
	return 0;
}