#include "stdio.h"

int sum(int n)
{   int re=0,a,i=1,b;
    while(n!=0){
        a=n%10;
        n=(n-a)/10;
        re+=a;
        //printf("%d\n",n);
    }
    return re;
}

main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sum(n));
}
