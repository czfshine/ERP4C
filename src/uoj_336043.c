#include "stdio.h" 
#include "stdlib.h" 
#include "math.h" 
main() 
{    int a[20][20], n, i, j, m; 
    scanf("%d", &n); 
    m=n/2; 
    for(i=0; i<n; i++) 
        for(j=0; j<n; j++) 
        { 

                if(abs(j-m)+2<abs(i-m))
                    a[i][j]=0;
                else
                    a[i][j]=1;




        } 
for(i=0; i<n; i++) 
{    for(j=0; j<n; j++) 
            printf("%02d ", a[i][j]); 
        printf("\n"); 
    } 
} 