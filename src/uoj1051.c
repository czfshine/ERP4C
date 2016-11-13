/*

**************************************
1051 找矩阵中的鞍点
**************************************
Description

由键盘输入一个3＊4（3行4列）的矩阵，输出矩阵中的鞍点（即在矩阵行中最大，列中最小的数）。

若没有鞍点，输出“NO”字样。
**************************************
Sample Input

87  90  110  98

70  97  210  65

98  45  120  30


**************************************
Sample Output

110
**************************************
Author0*/
#include <stdio.h>
#include "stdlib.h"
int* getMatrix  (int c,int r){
	int * data;
	data=(int *)malloc(4*c*r);
	for (int i = 0; i < c; ++i)
		for (int j = 0; j < r; ++j)
			scanf("%d",data+i*r+j);
	return data;
}
void getcmax(int  * c,int * out){
	int max=*c;
	for (int i = 0; i < 4; ++i)
	{
		if(max<*(c+i)){
			for (int j = 0; j < 4; ++j)
				*(out+j)=0;
			*(out+i)=1;
			max=*(c+i);
		}else{
			if(max==*(c+i))
				*(out+i)=1;
		}
	}

}
void getrmin(int  * c,int out[][4],int r){

	int min=*c;
	for (int i = 0; i < 3; ++i)
	{
		if(min>*(c+i)){
			for (int j = 0; j < 3; ++j)
				out[j][r]=0;
			out[i][r]=1;
			min=*(c+i);
		}else{
			if(min==*(c+i))
				out[i][r]=1;
		}
	}

}
int main(int argc, char const *argv[])
{
	int *data;
	int isMax[3][4]={0},isMin[3][4]={0},tempr[3]={0};
	int yes=1;

	data=getMatrix(3,4);

	for (int i = 0; i < 3; ++i)
		getcmax(data+i*4,isMax[i]);

	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			tempr[i]=*(data+i*4+j);
			
		}
		getrmin(tempr,isMin,j);
	}

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			if(isMax[i][j] && isMin[i][j]){
				printf("%d\n",*(data+i*4+j));
				yes=0;
			}
			
	if(yes)
		printf("NO");
	return 0;
}