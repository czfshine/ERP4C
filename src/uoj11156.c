/*

**************************************
11156 旋转矩阵一
**************************************
Description

    某天，tianjiewang在搭火车，由于他搭车后容易晕车，突然他想到了矩阵的旋转。

给一个3*3的矩阵，矩阵旋转是按顺时针的

例如



           1 2 3          7 4 1

           4 5 6 转一次是 8 5 2 

           7 8 9          9 6 3



           1 2 3          9 8 7

           4 5 6 转两次是 6 5 4

           7 8 9          3 2 1

问给一个n*m 的矩阵,问顺时针旋转k次后，求旋转后的矩阵是？（1<=n,m,k<=100），由于正在搭火车,tianjiewang的头很晕，

不知怎样做，现在他向你求助，你可以帮助他吗？



（出题人tianjiewang）


**************************************
Input

第一行输入 n，m，k；

第二行到第n + 1行，每行有m 个数,每个数的取值范围是（1<=Aij<=100）


**************************************
Output

输出n*m矩阵顺时针旋转k次后的矩阵
**************************************
Sample Input

3 3 1

1 2 3

4 5 6 

7 8 9


**************************************
Sample Output

7 4 1

8 5 2

9 6 3


**************************************
Source
**************************************
Author0*/
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