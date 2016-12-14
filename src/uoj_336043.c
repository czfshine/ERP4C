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

            if(i>j) 
                a[i][j] = m-abs(i-m); 
            else 
                a[i][j] = m-abs(j-m); 

        } 
for(i=0; i<n; i++) 
{    for(j=0; j<n; j++) 
            printf("%d ", a[i][j]); 
        printf("\n"); 
    } 
} 