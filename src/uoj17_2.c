#include "stdio.h"
#define min(x,y) (x)<(y)?(x):(y)
int main(int argc, char const *argv[])
{
	float a,b,c,d;
	scanf("%f%f%f%f",&a,&b,&c,&d);

	float n=0.0;
	n=min(a,min(b,c));
	//printf("%f%f%f%f%f",a,b,c,d,n);
	printf("%c",n>=d*2?'Y':'N');
	return 0;
}
