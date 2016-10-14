#include "stdio.h"

int main(int argc, char const *argv[])
{
	int ca=0,cn=0,ck=0,co=0;
	char ch;
	while((ch=getchar())!='\n'){
		if(ch>='A' && ch<='Z' || ch >='a' && ch<='z'){
			ca++;
		}else{
			if(ch>='0' && ch<='9'){
				cn++;
			}else{

				if(ch==' '){
					ck++;
				}else{
					co++;
				}
			}
		}
	}

	printf("%d %d %d %d",ca,cn,ck,co);
	return 0;
}