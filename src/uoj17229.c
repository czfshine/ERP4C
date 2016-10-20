#include "stdio.h"

main(){
    int n,a,b;
    scanf("%d",&n);

    a=n+2;
    b=n*4;

    if(a%2==1){
    printf("%d",b);
    }else{
        if(b%a==0){
            printf("%d",a%b);}
        else{
            printf("%d",b/2);
       }
    }
}
