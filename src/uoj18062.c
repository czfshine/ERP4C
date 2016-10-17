#include <stdio.h> 

void find(int a[][4]) 
{ 
    int (*p)[4], *q, *max; 
    for(p=&a[0];p<a+4;p++) 
    { 
        max=*p; 
        for(q=*p;q<*p+4;q++) 
        { 
        	if(*q>*max) max=q;
        } 
        printf("%d\n", *max); 
    } 
} 

int main() 
{ 
    int a[4][4],i,j; 
    for(i=0; i<4; i++) 
        for(j=0; j<4; j++) 
            scanf("%d", &a[i][j]); 
    find(a); 
    return 0; 
} 