#include "stdio.h"
#define M 3
#define N 4

int main(int argc, char const *argv[])
{
	int data[M][N];
	int dataT[N][M];
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d",&dataT[j][i]);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%d ",dataT[i][j]);
		}
		printf("\n");
	}
	return 0;
}