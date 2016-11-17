#include "stdio.h"
int main(int argc, char const *argv[])
{
	char ch;
	char fb=1;
	int count=0;
	while((ch=getchar())!='\n'){
		if(ch==' '){
			fb=1;
		}else{
			if(fb){
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}