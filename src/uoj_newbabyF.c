#include "stdio.h"
char data [100000]={0};

int find(char * str,int len){
	char  s[31]={0};
	int a=0;
	if(len<=1){
		//printf("a");
		return 0;
	}
	for (int i = 0; i < len; ++i)
	{
		s[i]=str[i];
		sscanf(s,"%d",&a);
		find(str+i,len-1);
		if(a>0) printf("%d",a);
	}
	printf("\n");
	
}
int main(int argc, char const *argv[])
{
	
	data[0]=1;
	data[1]=1;
	data[2]=0;
	int j,i;
	for (i = 2; i < 100000; ++i)
		if(!data[i])
			for (j = i+1; j < 100000; ++j)
				if(j%i==0)
					data[j]=1;

	char str[31];
	find("12345678",8);

	return 0;
}