#include "stdio.h"
#include "stdlib.h"
//todo
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

void r(int *data,int *out,int n,int m ){
		for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					*(out+i*m+j)=*(data+(m-j-1)*m+i);
				}
			}
}

void printMatrix(void * d,int c,int r){
	int *data;
	data=(int *)d;
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			printf("%d",*(data+i*r+j));
			if(j<r-1) printf(" ");
		}
		if(i<c-1)printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int * data;
	data=getMatrix(n,m);
	int *o;
	o=(int*)malloc(4*n*m);

	k%=4;
	switch(k){
		case 0:{printMatrix(data,n,m);
			break;}

		case 1:{
			r(data,o,n,m);
			printMatrix(o,n,m);
			break;

		}
		case 2:{
			r(data,o,n,m);
			r(o,data,n,m);
			printMatrix(data,n,m);
			break;
		}
		case 3:{

			r(data,o,n,m);
			r(o,data,n,m);
			r(data,o,n,m);
			printMatrix(o,n,m);
			break;

		}
	}
	return 0;
}