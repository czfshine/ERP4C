#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a[3][4],flag=0,col,r;
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<3;i++)
    {
        col=0;
        for(j=1;j<4;j++)
            if(a[i][j]>a[i][col]) col=j;
        for(j=0;j<4;j++)
        {
            if(a[i][j]==a[i][col])
            {
                for(r=0;r<3;r++)
                    if(a[r][j]<a[i][j]) break;
                if(r==3)
                {
                    printf("%d\n", a[i][j]);
                    flag=1;
                }
            }
        }
    }
    if(!flag)
        printf("NO\n");
    return 0;
}