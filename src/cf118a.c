#include <stdio.h>
#include <string.h>
int main(){
	char s[101];
	scanf("%s",s);
	int len ;
	len=strlen(s);
	char ch;
	for(int i=0;i<len;i++){
		ch=s[i];

		if (ch<=90)ch+=32;
		if (ch=='a' || ch =='e' || ch == 'i' || ch =='o' ||ch=='u'){

		}else{
			printf(".%c",ch);
		}
	}
	return 0;
}