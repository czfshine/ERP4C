/*
描述
由键盘输入20个整数，统计不同数字的个数。

输入样例
70  5  14  22  19  2  99  67  13  66  5  93  44  38  22  11  39  22  33  11
输出样例
16
提示
因为5有1个重复数字，11有1个重复数字，22有2个重复数字*/
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int data[20];
	for (int i = 0; i < 20; ++i)
	{
		scanf("%d",data+i);
	}

	for (int i = 0; i < 20; ++i)
	{
		for (int j = i; j < 20; ++j)
		{
			if(data[i]<data[j])
			{
				int tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;
			}
		}
	}
	int count =0;
	for (int i = 1; i < 20; ++i)
	{
		if(data[i]!= data[i-1])
			count ++;
	}

	printf("%d",count+1);
	return 0;
}
