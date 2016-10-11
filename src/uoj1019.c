#include <stdio.h>

int main(int argc, char const *argv[])
{
	int nums[5]={0};

	int i=0;

	for (int i = 0; i < 5; ++i)
	{
		scanf("%d",&nums[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		printf("%s",nums[i]%27?"NO\n":"YES\n");
	}

	return 0;
}