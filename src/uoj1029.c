/*

**************************************
1029 求最大公约数
**************************************
Description
由键盘输入两个正整数m、n（m、n<1000000），计算它们的最大公约数。
**************************************
Sample Input
16,24
**************************************
Sample Output
8
**************************************
Author0*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,m;
	int r;
	scanf("%d,%d",&n,&m);
	n>m?r=n,n=m,m=r:1;
	while(n%m){
		r=m%n;
		m=n;
		n=r;
	}
	printf("%d",m);
	return 0;
}