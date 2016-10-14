#include "stdio.h"
int a[16]={2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 34, 71, 79, 97, 103}; 
void display() 
{ 
    int i; 
    for(i=0; i<16; i++) printf("%d ", a[i]); 
} 
int main() 
{ 

	int i,x,k,t,yes=0;
	scanf("%d",&x);

	for ( i = 0; i < 15; ++i)
	{
		if(x<=a[i]){
			yes=1;
			for ( k = i; k <16; ++k)
			{
				t=a[k];
				a[k]=x;
				x=t;
			}
			break;
		}
	}
	if(yes!=1){
		a[15]=x;
	}
    display(); 
    return 0; 
} 









test