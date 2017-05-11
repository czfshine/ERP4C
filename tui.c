#include "tui.h"

typedef int INPUTTYPE ;
char * TYPENAME[]={
	"number",
	"string"
};

int buildnum[]={
	#include "BUILDNUM"
};

char version[]="dev 0.0.1";

void SayHello(){
	
	printf("ERP4C %s ",version);
    printf("| dev-build %04d\n",buildnum[0]);
}
void SayGoodbye(){
	CleanScreen();
	printf("Thanks you use ERP4C!\n");
	printf("Goodbye~~~\n");
}

void ShowMainMenu(){
	
	
	char str[]={
		"Please choose a option:\n"
		"1)\tloggin goods\n"
		"2)\tchange goods\n"
		"3)\tremove goods\n"
		"4)\tloggin stock&sale info\n"
		"5)\tquery goods\n"
		"6)\tstatis goods\n"
		"7)\thelp\n"
		"0)\texit\n"
		"Input your choice:"
	};

	printf("%s",str);

}

void ShowHelp(){
	char str[]={
		"This a help doc\n"
		"More infomation to see https://github.com/czfshine/my_oj\n"
		"Thanks you !\n"
	};
	printf("%s",str);
}	

void TypeError(INPUTTYPE T){
	printf("ERROR: Expect a %s but got another\n",TYPENAME[T]);
}
void TypeNullError(INPUTTYPE T){
	printf("ERROR: you must input a %s\n",TYPENAME[T]);
}
void TypeLongError(INPUTTYPE T){
	printf("ERROR: input %s is too long,try input a small %s\n",TYPENAME[T],TYPENAME[T]);
}

int WantNum(){
	/*note: The input num must be > 0*/
	int res=0;
	char ch;
	char flag=0;
	while((ch=getchar())!='\n'){
		if(isdigit(ch)){
			res=res*10+ch-'0';
			if(res<0){
				InputClean();
				return WANTLONGERROR;
			}
			flag=1;
		}else{
			InputClean();
			return WANTTYPEERROR;
		}
	}
	if(flag){
		return res;
	}else{
		return WANTNULLERROR;
	}
	
}
