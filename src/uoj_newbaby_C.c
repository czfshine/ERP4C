#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kcase = 0; kcase < T; ++kcase)
	{
		int A,D;
		char B[102];

		scanf("%d.%se%d",&A,B,&D);
		printf("%d%s%d",A,B,D);
	}
	return 0;
}