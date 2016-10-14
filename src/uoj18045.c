#include "stdio.h"
int main(int argc, char const *argv[])
{
	char ch;
	ch=getchar();
	if(ch<'0' || ch >'9'){
		printf("error");
	}else{
		switch(ch){
			case '0':{
				printf("first 1");//fuck !!!!
				break;
			}
			case '9':
			{
				printf("8 last");
				break;
			}
			default :
				printf("%c %c",ch-1,ch+1);
		}
	}
	return 0;
}