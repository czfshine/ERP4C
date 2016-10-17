#include <stdio.h> 

void input(int a[]) 
{ 
    int i; 
    for(i=0; i<10; i++) 
        scanf("%d", a+i); 
} 

void swap(int a[]) 
{ 
    int minn=0,min,i;
    min=a[0];
    for(i=0; i<10; i++) {
        if(a[i]<min){
            minn=i;
        }
    }
    int maxn=0,max;
    max=a[0];
    for(i=0; i<10; i++) {
        if(a[i]>max){
            maxn=i;
        }
    }
    a[0]=a[0]+a[minn];
    a[minn]=a[0]-a[minn];
    a[0]=a[0]-a[minn];
    a[9]=a[9]+a[maxn];
    a[maxn]=a[9]-a[maxn];
    a[9]=a[9]-a[maxn];


} 

void display(int a[]) 
{ 
    int i; 
    for(i=0; i<10; i++) 
        printf("%d\n", a[i]); 
} 

int main() 
{ 
    int a[10]; 
    input(a); 
    printf("input done\n"); 
    swap(a); 
    printf("swap done\n"); 
    display(a); 
    printf("display done\n"); 
    return 0; 
} 
