#include "stdio.h"
#define min(x,y) x<y?x:y
int main(int argc, char const *argv[])
{
	float a,b,c,d;
	scanf("%f%f%f%f",&a,&b,&c,&d);

	float n=min(a,min(b,c));

	printf("%c",n>d?'Y':'N');
	return 0;
}
