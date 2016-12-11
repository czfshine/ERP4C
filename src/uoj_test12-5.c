#include "stdio.h"
char lucky(int n){
	int a;
	char has4=0,has8=0;
	while(n>0){
		a=n%10;
		n/=10;
		if(a==4)has4=1;
		if(a==8)has8=1;
	}
	return (has8 && (!has4));
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 1000; ++i)
	{
		if(lucky(i)){
			printf("%d\n",i);
		}
	}
	return 0;
}