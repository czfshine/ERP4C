//#hdu 4018
#include <string>
#include <iostream>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	char ch;
	while(1){
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