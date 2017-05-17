/*
Text User Interface (TUI)
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
The user interface in console.
文本用户界面（Text User Interface）。
包括屏幕，提醒，输入，输出等函数。
*/
#include "tui.h"

/*版本小序*/
int buildnum[]={
	#include "BUILDNUM"
};

/*版本号*/
char version[]="dev 1.0.1";

/*****************输入**********************/
int WantNum(){
	/*数字输入*/
	/*note: The input num must be > 0*/
	/*输入的数字必须为自然数，返回的错误码为负*/
	int res=0;
	char ch;
	char flag=0;

	while((ch=getchar())!='\n'){
		if(isdigit(ch)){
			res=res*10+ch-'0';
			if(res<0){
				/*溢出*/
				InputClean();
				return WANTLONGERROR;
			}
			flag=1;
		}else{
			/*不支持的字符类型[^0-9]*/
			InputClean();
			return WANTTYPEERROR;
		}
	}
	if(flag){
		return res;
	}else{
		/*未输入*/
		return WANTNULLERROR;
	}
	
}

char * WantString(){
	/*输入字符串*/
	/*用静态类型防止内存泄漏*/
	/*TODO*/
	static char * a = NULL;
	if (a == NULL) 
		a = (char *)malloc(255);
	/*TODO ： 用scanf不安全*/
	scanf("%s",a);
	getchar();
	return a;

}

char * WantName(){
	/*输入商品名*/
	printf("Please input the good's name:");
	return WantString();
	
}

int WantId(){
	printf("Please input the good's id:");

	/*默认为负，说明未正确输入*/
	int id=-1;

	while (id < 0) {

		id = WantNum();
		
		switch (id) {
		case WANTTYPEERROR:
		case WANTNULLERROR:
			printf("ERROR:Please input a positive integer\n");
			printf("Please input the good's id:");
			break;
		
		case WANTLONGERROR:
			printf("ERROR:Input id too long ,please input a small number!\n");
			printf("Please input the good's id:");
			break;
		}

	}
	/*直到id为正才返回*/

	return id;
}

int WantCount(){
	
	printf("Please input the good's count:");

	int count=-1;
	
	while (count < 0) {
		count = WantNum();
		switch (count) {
		case WANTTYPEERROR:
		case WANTNULLERROR:
			printf("ERROR:Please input a positive integer\n"); 
			printf("Please input the good's count:");
			break;
		case WANTLONGERROR:
			printf("ERROR:Input number too long ,please input a small number!\n");
			printf("Please input the good's count:"); 
			break;
		}
		
	}

	return count;

}

void WantEnter() {
	/*暂停进程，等待用户反馈*/
	puts("Push Enter to contuine.");
	InputClean();
}

/********类型检查******************/
char * TYPENAME[] = {
	"number",
	"string"
};
void TypeError(INPUTTYPE T) {
	printf("ERROR: Expect a %s but got another\n", TYPENAME[T]);
}
void TypeNullError(INPUTTYPE T) {
	printf("ERROR: you must input a %s\n", TYPENAME[T]);
}
void TypeLongError(INPUTTYPE T) {
	printf("ERROR: input %s is too long,try input a small %s\n", TYPENAME[T], TYPENAME[T]);
}


void SayHello() {

	printf("ERP4C %s ", version);
	printf("| dev-build %04d\n", buildnum[0]);
}
void SayGoodbye() {
	CleanScreen();
	printf("Thanks you use ERP4C!\n");
	printf("Goodbye~~~\n");
}

void ShowMainMenu() {


	char str[] = {
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

	printf("%s", str);

}

void ShowHelp() {
	char str[] = {
		"This a help doc\n"
		"More infomation to see https://github.com/czfshine/my_oj\n"
		"Thanks you !\n"
	};
	printf("%s", str);
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
	CleanScreen();
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

Screen(Query, {
	"Show all goods:\n"
})
void ShowRemoveNull() {
	char str[] = {
		"Not good in the store,remove error.\n"
	};
	printf("%s", str);
}

void ShowGoodNotFound() {
	char str[] = {
		"The good can't found!\n"
	};
	printf("%s", str);
}

void ShowStoreEmpty() {
	char str[] = {
		"The Store is emtpy.\n"
	};
	printf("%s",str);
}

void ShowInputTypeError() {
	char str[] = {
		"This choice isn't correct.\n"
	};
	printf("%s", str);
}