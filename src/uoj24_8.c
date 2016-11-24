/*
描述
给定一个N行N列的二维整数矩阵（N<=10)，从该矩阵中任选一个元素，然后将该元素以及同该元素同行或者同列的元素全部累加
起来，得到累加和，称为选取。要求输出所有可能的选取中，取得最大值的选取。

输入格式
第一行为正整数N，然后N行，每行N个整数。
输出格式
最大选取
输入样例
3
1 2 3
4 5 6
7 8 9
输出样例
33
提示
1 2 3
4 5 6
7 8 9
选元素9，及其同行或同列的元素，3+6+7+8+9=33
*/
#include <stdio.h>
#include <stdlib.h>
int* getMatrix  (int c,int r){
	int* data;
	data=(int*)malloc(4*c*r);
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			scanf("%d",data+i*r+j);
		}
	}

	return data;
}

int main(int argc, char const *argv[])
{
	int *data;
	int N;
	scanf("%d",&N);
	data=getMatrix(N,N);

	int x[N],y[N];

	for (int i = 0; i < N; ++i)
	{	int sum=0;
		for (int j = 0; j < N; ++j)
		{
			sum+=*(data+i*N+j);
		}

		x[i]=sum;
	}

	for (int i = 0; i < N; ++i)
	{	int sum=0;
		for (int j = 0; j < N; ++j)
		{
			sum+=*(data+j*N+i);
		}

		y[i]=sum;
	}
	int max=x[0]+y[0]-*(data);
	for (int i = 0; i < N; ++i)
	{	
		for (int j = 0; j < N; ++j)
		{
			int n=*(data+j*N+i);
			int xd=x[j];
			int yd=y[i];//fuck
			int m=xd+yd-n;
			//printf("%d %d %d %d %d %d\n",i,j,xd,yd,n,m);
			max=max>m?max:m;
		}
	}

	printf("%d",max);
	return 0;
	
}