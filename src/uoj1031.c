#include "stdio.h"
int main(int argc, char const *argv[])
{	char ch;
	char yes=0;
	int count=0;
	while((ch=getchar())!='\n'){
		//printf("%d",ch);
		if(ch==' ') {if(yes){}else{count++;yes=1;}}else{yes=0;}
	}
	printf("%d",count+1);
	return 0;
}