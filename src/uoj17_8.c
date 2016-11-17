#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	char in[3],out[4];
	scanf("%c%c%c",in,in+1,in+2);

	int o=0;
	out[2]=in[0];
	out[1]=in[1];
	out[0]=in[2];
	out[3]='\0';
	sscanf(out,"%d",&o);
	printf("%d",o);
	return 0;
}