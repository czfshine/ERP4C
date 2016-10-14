#include "stdio.h"

int main(int argc, char const *argv[])
{
	int num=0,nums[10],fail;		
	for (int i = 0; i < 10; ++i)
	{
		fail=0;
		scanf("%d",&num);
		nums[i]=num;

		for (int k = 0; k < i; ++k)
		{
			if(nums[k]==num){
				fail=1;
			}
		}

		if(fail==0){
			printf("%d\n",num);
		}
	}
	return 0;
}