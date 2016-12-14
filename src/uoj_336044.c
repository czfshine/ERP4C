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
	char data[101]="12g3";
	rev(data,4);
	printf("%s",data);
	int sum;

	return 0;
}