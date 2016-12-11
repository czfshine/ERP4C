#include "stdio.h"
int main(int argc, char const *argv[])
{
	int x,y,r;
	scanf("%d%d%d",&x,&y,&r);

	int m=x<y?x:y;
	if(m>=r*2)
		printf("Y");
	else
		printf("N");
	return 0;
}