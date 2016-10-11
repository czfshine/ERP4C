#include "stdio.h" 
#include "math.h"
//TODO
int getpow(int n){
	int p=0;
	while(n<pow((double)2.0,(double)p)){
		p++;
	}
	return p;
}

void binary(int n){
	int p;
	p=getpow(n);
	printf("%d",p);
	if(p) {printf("1");
		binary((int)n-pow((double)2.0,(double)p));
	}
}
main() 
{ 
    int n; 
    scanf("%d", &n); 
    binary(n); 
} 