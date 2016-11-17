#include "stdio.h"
#include "string.h"
char data[10000][11];

void swap(char *s1,char *s2){

	char tmp[11];
	strcpy(tmp,s1);
	strcpy(s1,s2);
	strcpy(s2,tmp);

}
int main(int argc, char const *argv[])
{
	int i=0;
	FILE * infile;

	infile=fopen("case1.in","r");

	while(fgets(data[i],11,infile)!=NULL){
		i++;
	}

	for (int j = 0; j < i+1; ++j)
	{
		for (int k = 0; k < j; ++k)
		{
			if(strcmp(data[j],data[k])<0){
				swap(data[j],data[k]);
			}
		}
	}

	for (int j = 0; j < i+1; ++j)
	{
		printf("%s\n",data[j]);
	}

	return 0;
}