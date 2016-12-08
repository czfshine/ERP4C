#include<stdio.h>
int main()
{
    int a[3][4];
    int i,j,maxi,minj,yes=0,t,k;//maxi,minj分别表示行里面最大的数以及列里面最小的数.
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        yes=0;
        maxi=a[i][0];//假设每行中第一个数为该行中最大的数
        for(j=0;j<3;j++)//这个循环用于找出每行中最大的数。
        {
            if(maxi<a[i][j+1])
            {
                yes=1;
                maxi=a[i][j+1];
                t=j+1;//用t来记录下该行中最大的数所在的列。
            }
        }
        if(yes==0)  k=0;
        else k=t;
        minj=a[0][k];//假定每列中最小的数都是第一行的数
        for(i=0;i<2;i++)//这个循环用来找出每列中最小的数
        {
            if(minj>a[i+1][k])  minj=a[i+1][k];
        }
        if(maxi==minj)  printf("%d\n",minj);
    }
    
    printf("NO");
    return 0;
}
