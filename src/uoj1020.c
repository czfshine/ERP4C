#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a ;
	scanf("%d",&a);

	printf("%s\n%s",a>0?"positive":"negative",a%2==0?"even":"odd");
	return 0;
}