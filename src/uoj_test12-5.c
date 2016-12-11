#include "stdio.h"
char lucky(int n){

	while(n>0){
		a=n%10;
		n/=10;
		printf("%d",a);
	}
}
int main(int argc, char const *argv[])
{
	lucky(12345);
	return 0;
}