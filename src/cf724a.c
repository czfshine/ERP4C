#include <stdio.h>

int getnum(char * str){

	char ch=str[0];

	switch(ch){
		case 'm':return 0;
		case 't':
		if(str[1]=='u'){
			return 1;
		}else{
			return 3;
		}
		case 'w':return 2;
		case 'f':return 4;
		case 's':
			if (str[1]=='a'){
				return 5;
			}else{
				return 6;
			}
	}
}
int main (){

	char day[10];
	int f,s,i=0,sub=0;
	int data[12]={3,0,3,2,3,2,3,3,2,3,2,3};
	char can=0;
	scanf("%s",day);
	f=getnum(day);
	scanf("%s",day);
	s=getnum(day);
	sub=s-f;
	if (sub<0){
		sub=7+sub;
	}
	for(i=0;i<12;i++){
		if(sub==data[i]){
			can=1;
		}
	}
	printf("%s",can?"YES":"NO");



	return 0;
}