#include  "stdio.h" 

int test1(int m,int n)
{ 
    int  r; 
    while ((r=m%n)!=0) 
    { 
        m=n; 
        n=r; 
    } 
    return  n; 
} 

main() 
{ 
    int  a, b, n; 
    scanf("%d%d", &a, &b); 
    printf("%d\n", test1(a,b)); 
} 