#include "stdio.h"

main(){
    long long  n,a,b,c;
    scanf("%lld",&n);

    a=n+2;
    b=n*4;
    /*
    if(a%2==1){
    printf("%lld",b);
    }else{
        if(b%a==0){
            printf("%lld",b/a);
        }
        else{
            printf("%lld",b/2);
        }
    }*/
    while(a!=0)
    {
        c=b%a;
        b=a;
        a=c;
    }
    //printf("%d",b);
    printf("%lld",((n+2)*(n*4)/b)/(n+2));
}
