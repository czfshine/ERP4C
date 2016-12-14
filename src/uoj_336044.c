#include "stdio.h"

#include "string.h"

void rev(char *str ,int len){
		for (int i = 0; i < len/2; ++i)
		{	char t=str[i];
			str[i]=str[len-i-1];
			str[len-i-1]=t;
		}
	
}
int main(int argc, char const *argv[])
{
	char data[101]="123";
	rev(data);
	printf("%s",data,3);
	int sum;

	return 0;
}