#include "stdio.h"
int main(int argc, char const *argv[])
{
	int a=0x04;
	int b=0x02;
	int c=6;
	if(c&a)
		printf("1");
	return 0;
}