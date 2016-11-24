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
		printf("%d\n",sum);
	}

	for (int i = 0; i < N; ++i)
	{	int sum=0;
		for (int j = 0; j < N; ++j)
		{
			sum+=*(data+j*N+i);
		}

		y[i]=sum;
		printf("%d\n",sum);
	}
	int max=x[0]+y[0]-*(data);
	for (int i = 0; i < N; ++i)
	{	
		for (int j = 0; j < N; ++j)
		{
			int n=*(data+j*N+i);
			int xd=x[i];
			int yd=y[i];
			int m=xd+yd-n;
			max=max>m?max:m;
		}
	}

	printf("%d",max);
	return 0;
}