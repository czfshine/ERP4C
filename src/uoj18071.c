#include <stdio.h>

void average(double a[][5], int n)
{
    int i,j;
    double sum=0;
    for (i=0;i<10;i++){
        for(j=0;j<5;j++){
            sum+=a[i][j];
        }
        printf("%.2lf ",sum/5.0);
        sum=0;
    }
    printf("\n");
}

void average2(double a[][5], int n)
{
    int i,j;
    double sum=0;
    for (i=0;i<5;i++){
        for(j=0;j<10;j++){
            sum+=a[j][i];
        }
        printf("%.2lf ",sum/10.0);
        sum=0;
    }
    printf("\n");
}

void top(double a[][5], int n)
{   int i,j;
    double max=0;
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            if(a[j][i]>max)
                max=a[j][i];
        }

        printf("%.2lf ",max);
        max=0;
    }
}

int main()
{
    double a[10][5];
    int i, j;
    for(i=0; i<10; i++)
        for(j=0; j<5; j++)
            scanf("%lf", &a[i][j]);
    average(a,10);
    average2(a,10);
    top(a,10);
    return 0;
}
