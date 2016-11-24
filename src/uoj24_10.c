/*
描述
10000的阶乘是一个很大的数字，但这一次我们关心的不是这个数字是多少，而是这个数字从个位开始向左直到第一个不为零的数字一共有多少个零。比如5的阶乘是120，
有1个零，10的阶乘是3628800，有2个零。现给你若干个数，这些数各有多少个零。

输入格式
第一行为数N，表示有多少个数
此后一行一个整数（数的范围为1至1000000000）
输出格式
对每一个整数，输出该数阶乘中按题意要求的需的个数
输入样例
6
3
60
100
1024
23456
8735373
输出样例
0
14
24
253
5861
2183837*/
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);

	while(T--){
		long long  n;
		scanf("%lld",&n);
		long long  m=n/5;
		long long h;
		long long count=0;
		for (long long i = 1; i <= m; ++i)
		{	count++;
			long long  t=i;
			while(t%5==0){
				t=t/5;
				count++;
			}
			
		}
		printf("%lld\n",count);
	}
	return 0;
}