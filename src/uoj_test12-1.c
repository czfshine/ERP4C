#include "stsio.h"
#define abs(x) (x)>0:(x)?-(x)
int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",abs(a-b));
	return 0;
}