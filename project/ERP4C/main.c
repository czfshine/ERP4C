/*
THE ERP SYSTEM FOR C (ERP4C)
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
商品进销存管理程序
1、题目描述
   设计一个商品进销存管理程序，该程序具有以下功能：
   （1）录入商品信息；
   （2）给定商品编号，修改该商品信息；
   （3）给定商品编号，删除该商品信息；
   （4）录入商品的进货与销售信息；
   （5）给定商品编号或商品名，查看该商品及库存信息；
   （6）统计功能：提供一些统计各类信息的功能。
2、题目要求
   （1）按照分析、设计、编码、调试和测试过程完成应用程序；
   （2）学习并使用流程图等工具，并在撰写报告中使用；
   （3）程序的各项功能在程序运行时，以菜单方式选择并执行；
   （4）要求用户输入数据时，要给出清晰、明确的提示，包括：输入数据的内容、格式及结束方式等
   （5）所有的信息存储在一个文件或多个中，并实现文件读写操作。
   （6）程序中用链表存放商品及进销存信息并实现增删减功能。（必须）
3、提示
   （1）提醒事件信息可以设计一个结构体类型
   （2）自己构思并增加的除规定功能之外的新功能，酌情加分。

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LOOP(fn) while(!fn()){}
#define CleanScreen()  system("cls");SayHello();
int buildnum[]={
	#include "BUILDNUM"
};

char version[]="dev 0.0.1";


void SayHello(){
	
	printf("ERP4C %s ",version);
    printf("| dev-build %04d\n",buildnum[0]);
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
void InputClean(){
	char ch;
	while((ch=getchar())!='\n'){}

}
#define WANTTYPEERROR -1
#define WANTNULLERROR -2

int WantNum(){
	int res=0;
	char ch;
	char flag=0;
	while((ch=getchar())!='\n'){
		if(isdigit(ch)){
			res=res*10+ch-'0';
			flag=1;
		}else{
			InputClean();
			return -1;
		}
	}
	if(flag){
		return res;
	}else{
		return -2;
	}
	
}

#define T_NUM 0
#define T_STR 1
typedef int INPUTTYPE ;
char * TYPENAME[]={
	"number",
	"string"
};

void TypeError(INPUTTYPE T){

	printf("ERROR: Expect a %s but got another\n",TYPENAME[T]);
}
void TypeNullError(INPUTTYPE T){

	printf("ERROR: you must input a %s\n",TYPENAME[T]);
}


int ListenMainKey(){
	int op;

	op=WantNum();

	switch(op){
		case WANTTYPEERROR:
		{
			CleanScreen();
			TypeError(T_NUM);
			ShowMainMenu();
			return 0;
		}
		case WANTNULLERROR:
		{
			CleanScreen();
			TypeNullError(T_NUM);
			ShowMainMenu();
			return 0;
		}

	}
	printf("%d\n",op);
	
	return 0;
}

int main()
{
    CleanScreen();
    ShowMainMenu();
    LOOP(ListenMainKey);

    return 0;
}
