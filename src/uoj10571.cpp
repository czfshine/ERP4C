//#hdu 4018
#include <string>
#include <iostream>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	char ch;
	int T;
	scanf("%d",&T);
	int i=1;
	while(i<=T){
		printf("Case #%d",i++);
		while((ch=getchar())!=EOF){

			if(ch==':') break;
		}
		getchar();getchar();

		while((ch=getchar())!=EOF){
			
			if(ch==':') break;
			if(ch=='/') break;
			putchar(ch);
		}
		putchar('\n');
		while((ch=getchar())!=EOF)if(ch=='\n') break;
	}
	return 0;
}