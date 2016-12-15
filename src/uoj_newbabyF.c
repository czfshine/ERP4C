#include "stdio.h"
#include "string.h"
#define min(x,y) x<y?x:y
char  str[31];
int end=0;
int find(int s){
	printf("%d %s\n",s,str+s);
	if(s==end) return 1+1;//print("%s",str+s);
	for (int i = s+1; i < min(end,s+5); ++i)
	{
		find(i);
	}
	if(end-s>6)
		find(s+6);
}
int main(int argc, char const *argv[])
{	
	scanf("%s",str);
	end=strlen(str)-1;
	find(0);

	return 0;
}