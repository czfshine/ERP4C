#include "stdio.h"
main(){
	int a;
	scanf("%d",&a);
	printf("%d\n%d",(a-(a%100))/100,a%10);
}
