#include <stdio.h>

int main(int argc, char const *argv[])
{
	freopen("test.txt","r",stdout);

	srand(1);

	for (int i = 0; i < 100; ++i)
	{
		printf("%d %d",rand(),rand());
	}
	return 0;
}