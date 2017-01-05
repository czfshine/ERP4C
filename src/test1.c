#include "stdio.h"
struct {
	char a[30];
}abc;

int main(int argc, char const *argv[])
{
	printf("%d",sizeof(abc));
	return 0;
}