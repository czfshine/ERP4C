#include <stdio.h> 

void swap(int *a, int *b) 
{ 
    int temp; 
    temp=*a;*a=*b;*b=temp; 
} 

void col(int a[][4], int i, int j) 
{ 
    
     for (int k = 0; k < 4; ++k)
     {
     	swap((int *)a+i*4+k,(int *)a+j*4+k);
     } 
} 

void row(int a[][4], int i, int j) 
{ 
	for (int k = 0; k < 4; ++k)
     {
     	swap((int *)a+k*4+i,(int *)a+k*4+j);
     } 
} 

int main() 
{ 
    int a[4][4]; 
    int i,j; 
    for(i=0; i<4; i++) 
        for(j=0; j<4; j++) 
            scanf("%d", &a[i][j]); 
    col(a,0,2); 
    row(a,0,2); 
    col(a,1,3); 
    row(a,1,3); 
    col(a,0,3); 
    row(a,0,3); 
    for(i=0; i<4; i++) 
    { 
        for(j=0; j<4; j++) 
            printf("%d ", a[i][j]); 
        printf("\n"); 
    } 
    return 0; 
} 