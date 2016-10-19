#include "stdio.h"
int main(int argc, char const *argv[])
{
	char str[81],ch,cur=0;
	int sum1=0,sum2=0;
	while((ch=getchar())!='\n')
		str[cur++]=ch;
	for (int i = 0; i < 81; ++i)
	{
		if(i==cur) break;
		sum1+=str[i];
	}
	cur=0;
	while((ch=getchar())!='\n')
		str[cur++]=ch;
	for (int i = 0; i < 81; ++i)
	{
		if(i==cur) break;
		sum2+=str[i];
	}
	printf("%d",sum1-sum2);
	return 0;
}