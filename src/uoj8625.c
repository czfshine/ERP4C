#include "stdio.h"
int main(int argc, char const *argv[])
{
	int T;
	char ch;
	scanf("%d",&T);
	ch=getchar();
	for (int i = 0; i < T; ++i)
	{
		
		int M=0,F=0;
		ch=' ';
		while(ch!='\n'){
		ch=getchar();
		switch(ch){
			case 'M':M++;break;
			case 'F':F++;break;
		}
		//printf("%c %d %d\n",ch,M,F);
	}	//printf("%d %d",M,F);
		printf("%s\n",M==F?"LOOP":"NO LOOP");
	}
	return 0;
}