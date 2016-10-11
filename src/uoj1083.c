#include "stdio.h" 
int fanc(int n){
	if(n==1){
		return 1;
	}else{
		return fanc(n-1)*n;
	}
}
main() 
{    int n; 
    scanf("%d", &n); 
    printf("%ld", fanc(n)); 
} 