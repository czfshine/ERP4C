#include "stdio.h"
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; ++i)
	{
		int n;
		scanf("%d",&n);
		printf("%s\n",n%27==0?"YES":"NO");
	}
	return 0;
}