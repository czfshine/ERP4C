/*

**************************************
1028 求素数
**************************************
Description
输出2到200之间（包括2、200）的所有素数（注：要求1行1个素数，按由小到大的顺序输出）。
**************************************
Sample Input
（无）
**************************************
Sample Output

2

3

5

7

……

199


**************************************
Author0*/
#include "stdio.h"

int main(int argc, char const *argv[])
{
	char data [201]={0};
	data[0]=1;
	data[1]=1;
	data[2]=0;
	int j,i;
	for (i = 2; i < 201; ++i)
		if(!data[i])
			for (j = i+1; j < 201; ++j)
				if(j%i==0)
					data[j]=1;
	for (int i = 1; i < 201; ++i)
		if(!data[i]) printf("%d\n",i);
	return 0;
}