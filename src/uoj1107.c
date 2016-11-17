#include "stdio.h"
char data[10000][11];
int main(int argc, char const *argv[])
{
	int i=0;
	FILE * infile;

	infile=fopen("case1.in","r");

	while(fgets(data[i],11,infile)!=NULL){
		i++;
	}

	return 0;
}