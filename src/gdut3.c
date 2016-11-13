#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kkk = 0; kkk < T; ++kkk)
	{
		int im,id;
		int od,om;

		scanf("%d-%d",&im,&id);
		scanf("%d-%d",&om,&od);

		int data[]={31,29,31,30,31,30,31,31,30,31,30,31};
		int sum=0;
		for (int i = im; i < om-1; ++i)
		{
			sum+=data[i];
		}
		sum+=data[im-1]-id;
		sum+=data[om-1]-od;

		printf("%d\n",sum);
	}
	return 0;
}