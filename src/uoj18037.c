#include "stdio.h"

int main(int argc, char const *argv[])
{
	int h,m,s;
	scanf("%d:%d:%d",&h,&m,&s);
	s=s+20;
	if(s>59){
		s-=60;
		m++;
	}
	if(m>59){
		m-=60;
		h++;
	}
	if(h>23){
		h=0;
	}

	printf("%02d:%02d:%02d",h,m,s);
	return 0;
}