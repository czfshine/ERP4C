#include "stdio.h"

int main(int argc, char const *argv[])
{
	int a;
	scanf("%d",&a);
	for (int i =a%2; i < a; i+=2)
	{
		if(a%i==0){
			printf("%d\n",i);
		}
	}
	return 0;
}