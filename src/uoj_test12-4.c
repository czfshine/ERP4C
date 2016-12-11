#include <stdio.h> 
int a[16]={2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 34, 71, 79, 97, 103}; 
void display() 
{ 
    int i; 
    for(i=0; i<16; i++) printf("%d ", a[i]); 
} 
int main() 
{ 
	int x;
	int i ;
	scanf("%d",&x);
	for (i= 0; i < 15; ++i)
	{
		if(x<=a[i]){
			
			for (int j = 14; j >i; --j)
			{
				a[j+1]=a[j];
			}
			a[i]=x;
			break;
		}
	}
	if(i==15){
		a[15]=x;
	}
    display(); 
    return 0; 
}
