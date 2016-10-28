#include "stdio.h"
int main(int argc, char const *argv[])
{
	char ch,flag=0;

	while((ch=getchar())!=EOF){
		switch(ch){
			case '"':if(flag){
				flag=0;
				printf("%s","''");
			}else{
				flag=1;
				printf("%s","``");
			}break;

			default:printf("%c",ch);
		}
	}
	return 0;
}