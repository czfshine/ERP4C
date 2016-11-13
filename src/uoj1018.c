/*

**************************************
1018 数的排序
**************************************
Description
由键盘输入三个整数a、b、c，按从小到大的顺序输出这三个数。
**************************************
Input
三个数由逗句分隔
**************************************
Sample Input
65,45,90
**************************************
Sample Output
45,65,90
**************************************
Author0*/
#include "stdio.h"
main(){
	int data[3];
    int i,j;
	scanf("%d,%d,%d",&data[0],&data[1],&data[2]);
	for( i=0;i<3;i++)
        for ( j=0;j<i;j++)
            if(data[i]>data[j]){
                int temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
    printf("%d,%d,%d",data[2],data[1],data[0]);
}
