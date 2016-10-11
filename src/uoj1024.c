#include "stdio.h"

int f(int n){
	if(n==1){
		return 1;
	}else{
		return f(n-1)*n;
	}
}
int main(int argc, char const *argv[])
{
	int max;
	scanf("%d",&max);
	printf("%d",f(max));

	return 0;
}