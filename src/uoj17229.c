#include "stdio.h"

main(){
    long long  n,a,b;
    scanf("%lld",&n);

    a=n+2;
    b=n*4;

    if(a%2==1){
    printf("%lld",b);
    }else{
        if(b%a==0){
            printf("%lld",b/a);
        }
        else{
            printf("%lld",b/2);
        }
    }
}
