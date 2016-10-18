#include "stdio.h"
int pow(int x,int y){
    int i,re=1;
    for (i=0;i<y;i++)
        re*=x;
    return re;
}
int getlast1(int n){

}
void binary(int n){

    int c,i=0,j=0;
    while(n){
        c=n & -n;
        i=0;
        while(c){
            c/=2;
            i++;
        }
        for(j=1;j<i;j++)
            printf("0");
        printf("1");
        n/=1<<i;
    }
}

main()
{
    int n;
    scanf("%d", &n);
    binary(n);
}
