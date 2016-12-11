#include "stdio.h"
#include "string.h"

void revstr(char *str, size_t len)
{

    char    *start = str;
    char    *end = str + len - 1;
    char    ch;

    if (str != NULL)
    {
        while (start < end)
        {
            ch = *start;
            *start++ = *end;
            *end-- = ch;
        }
    }

}
main(int argc, char const *argv[])
{	char data[10000][13]={0};
	char *s1,*s2;

	int i=0;
	FILE * infile;

	infile=fopen("case1.in","r");

	while(fgets(data[i],12,infile)!=NULL){
		i++;
	}
	for (int j = 0; j < i; ++j){
		int len=strlen(data[j]);
		revstr(data[j],len);
		printf("%sggg",data[j]);
	}
	for (int j = 0; j < i; ++j)//fuck!!!!!!!!!!!!!!!!!
	{
		for (int k = 0; k < j; ++k)
		{
			if(strcmp(data[j],data[k])<0){
				s1=data[j];
				s2=data[k];
				char tmp[13];
				strcpy(tmp,s1);
				strcpy(s1,s2);
				strcpy(s2,tmp);
			}
		}
	}

	for (int j = 0; j < i; ++j)
	{
		printf("%s",data[j]);
		//printstrre(data[j]);
		//fputs(data[j],outfile);
	}
	fclose(infile);

}