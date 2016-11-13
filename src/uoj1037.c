/*

**************************************
1037 计算数列和
**************************************
Description

请按格式输出
**************************************
Output

20
**************************************
Sample Input

32.6603
**************************************
Sample Output
**************************************
Author0*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	double n=1,m=2,t=0;
	double sum=0;
	int r;
	scanf("%d",&r);

	for (int i = 0; i < r; ++i)
	{
		sum+=m/n;
		t=n;
		n=m;
		m=t+n;
	}
	printf("%.4f",sum);

	return 0;
}