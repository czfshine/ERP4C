#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);

	for (int i = 0; i < T; ++i)
	{
		int x,y,n1,r,n,m;
		scanf("%d%d%d",&x,&y,&n1);
		x++;y++;
		n=x,m=y;
		x>y?r=x,x=y,y=r:1;
    	while ((r=y%x)!=0) 
   		{ 
        	y=x; 
       	 	x=r; 
    	}

    	printf("%d\n",n1/(m*n/x)*36);
	}
	return 0;
}