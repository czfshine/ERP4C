//#hdu 4018
#include <string>
#include <iostream>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	char ch;

	while((ch=getchar())!=EOF){

		if(ch==':') break;
	}
	getchar();getchar();

	while((ch=getchar())!=EOF){
		putchar(ch);
		if(ch==':') break;
		if(ch=='/') break;
	}
	putchar('\n');


	return 0;
}