#include "stdio.h"
#include "string.h"

main(int argc, char const *argv[])
{	char data[10000][12];
	char *s1,*s2;

	int i=0;
	FILE * infile,*outfile;

	infile=fopen("case1.in","r");
	outfile=fopen("answer.txt","w");

	while(fgets(data[i],11,infile)!=NULL){
		i++;
	}

	for (int j = 0; j < i+1; ++j)
	{
		for (int k = 0; k < j; ++k)
		{
			if(strcmp(data[j],data[k])<0){
				s1=data[j];
				s2=data[k];
				char tmp[12];
				strcpy(tmp,s1);
				strcpy(s1,s2);
				strcpy(s2,tmp);
			}
		}
	}

	for (int j = 0; j < i+1; ++j)
	{
		//printf("%s\n",data[j]);
		fputs(data[j],outfile);
	}
	fclose(infile);
	fclose(outfile);
	
}