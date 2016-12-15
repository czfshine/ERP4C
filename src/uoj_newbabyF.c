#include "stdio.h"

char * str[]="12345678";
int end=7;
int find(int s){
	printf("%s",str+s);
	if(s==end) 1+1//print("%s",str+s);
	for (int i = s; i < min(end,s+6); ++i)
	{
		find(i);
	}
	if(end-s>6)
		find(s+6);
}
int main(int argc, char const *argv[])
{	
	find(0);

	return 0;
}