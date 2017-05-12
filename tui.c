/*
Text User Interface (TUI)
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
The user interface in console.
*/
#include "tui.h"

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

char * WantString(){
	/*todo*/
	char * a;
	a=(char * )malloc(25);
	scanf("%s",a);
	getchar();
	return a;

}
char * WantName(){
	/*todo*/
	printf("Please input the good's name:");
	return WantString();
	
}

int WantId(){
	/*todo*/
	printf("Please input the good's id:");
	int id;
	id=WantNum();
	return id;
}

int WantCount(){
	/*todo*/
	printf("Please input the good's count:");

	int count;
	count=WantNum();

	return count;

}

void WantEnter(){
	puts("Push Enter to contuine.");
	InputClean();
}

void ShowLogginGoods(){
	char str[]={
		"Loggin goods infomation:\n"
		"Note : You can input a id equal 0 to exit loggin.\n"

	};

	printf("%s",str);


}

void ShowLogginSuccess(){

	char str[]={
		"The goods was success loggined.\n"
	};

	printf("%s",str);
}




void ShowGoodsExist(int id){
	
	char str[]={
		"The Goods id:%d is exist,please input another id\n"
	};

	printf(str,id);

}




void ShowChangeGoods(){

	char str[]={
		"Change goods infomation:\n"
		"Note : You can input a id equal 0 to exit loggin.\n"
	};

	printf("%s",str);
	return;
}
void ShowCantFind(int id){
	char str[]={
		"The Good with id:%d isn't exist,please input another id\n"
	};

	printf(str,id);
}
void ShowChangeType(){

	char str[]={
		"Please choose you want change infomation type:\n"
		"1) good's name\n"
		"2) good's count\n"
		"Input your choice:"
	};

	printf("%s",str);
}

void ShowChangeSuccess(){

	char str[]={
		"The goods was success changed.\n"
	};

	printf("%s",str);
}
void ShowRemove() {
	char str[] = {
		"Remove goods from the store:\n"
		"Please choose a option:\n"
		"1) remove good by id\n"
		"2) remove good by name\n"
		"0) return the main menu\n"
		"Input your choice:"
	};


	printf("%s", str);

}

void ShowRemoveSuccess() {
	char str[] = {
		"Remove good(s) success!\n"
	};
	printf("%s", str);
}

void ToLoggin2SScreen() {
	CleanScreen();
	char str[] = {
		"Sale or Stock good:"
		"Please choose a option:\n"
		"1) Sale good(s).\n"
		"2) Stock good(s).\n"
		"0) Exit.\n"
		"Input your choice:"
	};
	printf("%s", str);
}
void ToSaleScreen() {
	CleanScreen();
	char str[] = {
		"Sell the goods:\n"
		"Note : You can input a id equal 0 to exit loggin.\n"
	};
	printf("%s", str);
}
void ShowSaleCount() {
	char str[] = {
		"How many good(s) you want to sell: "
	};
	printf("%s", str);
}

void ShowSaleSuccess() {
	char str[] = {
		"The goods was  success sold!\n"
	};
	printf("%s", str);
}
void ToStockScreen() {
	CleanScreen();
	char str[] = {
		"Stock the good:\n"
		"Note : You can input a id equal 0 to exit loggin.\n"
	};

	printf("%s", str);
}

void ShowStockCount() {
	char str[] = {
		"How many good(s) you want to stock: "
	};
	printf("%s", str);
}

void ShowStockSuccess() {
	char str[] = {
			"The goods was  success stocked!\n"
	};
	printf("%s", str);

}


void ShowSumCount() {
	char str[] = {
		"The sum of the good's count is:"
	};
	printf("%s", str);
}

void ShowIdCount() {
	char str[] = {
		"The sum of good's type is:"
	};
	printf("%s", str);

}

void ToStatisScreen() {

	char str[] = {
		"Statis good's infomation:\n "
		"Please choose a option:\n"
		"1) Count sum of good's count.\n"
		"2) Count sum of good's type. \n"
		"0) Exit\n"
		"Input your choice:"
	};
	printf("%s", str);
}