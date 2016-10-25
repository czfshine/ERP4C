#include "stdio.h"
#include <math.h>
//广义斐波那契数列求和
//233333333
int main(int argc, char const *argv[])
{
	//输入框架：
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		long a,b,N;
		scanf("%d %d %d",&a,&b,&N);

		double P,T,S;
		P=0.4472136*pow(1.618034,N);
		T=0.4472136*pow(1.618034,N+1)-1;
		S=a*P+T*b;
		printf("%d\n",(long)floor(S));
	}
	return 0;
}