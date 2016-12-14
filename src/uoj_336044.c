#include "stdio.h"

#include "string.h"

void rev(char *str ,int len){
	if(len%2==0)
		for (int i = 0; i < len/2; ++i)
		{	char t=str[i];
			str[i]=str[len-i-1];
			str[len-i-1]=t;
		}
		else
		for (int i = 0; i < len/2; ++i)
		{	char t=str[i];
			str[i]=str[len-i-1];
			str[len-i-1]=t;
		}
	
}
int main(int argc, char const *argv[])
{
	char data[101]="12g3";
	int sum=0,n;
	while(scanf("%s",data)>0){
		rev(data,strlen(data));
		sscanf(data,"%d",&n);
		printf("%s",data);
		sum+=n;
	}
	printf("%d",sum);
	return 0;
}