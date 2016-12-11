#include "stdio.h"
int main(int argc, char const *argv[])
{
	float x,y,r;
	scanf("%f%f%f",&x,&y,&r);

	float m=x<y?x:y;
	if(m>=r*2)
		printf("Y");
	else
		printf("N");
	return 0;
}