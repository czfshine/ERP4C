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

#include "tui.h"
#include "goods.h"
#include "main.h"
#include <io.h>

Store GobalStore;

void Init(){
	Store * S;
	S=InitStore();
	GobalStore=*S;
}
void callback(){
	printf("test callback");
}		

goods * WantGoodsById(int * res){
	int id;
	id=WantId();
	/*TODO TYPE ERROR*/
	if(id == 0){
		ToMainScreen();
		return (goods *)-1;
	}

	*res=id;
	goods *g;
	g=FindGoodsById(GobalStore,id);

	return g;

}
int LogginGoods(){

	ToLogginScreen();
	char * name;
	int id,count;

	
	goods *g;
	g=WantGoodsById(&id);
	if(g==(goods *)-1) return 1;
	if(g!=NULL){
		
		ShowGoodsExist(id);
		WantEnter();
		return 0;
	}


	name=WantName();
	count=WantCount();

	AddGoods( GobalStore,id,name,count);

	ShowLogginSuccess();
	WantEnter();
	
	return 0;
}

int ChangeName(goods* g){                                 
	char * name;
	name=WantName();

	strcpy(g->name,name);
	return 0;
}

int ChangeCount(goods * g){

	int count ;
	count =WantCount();

	g->count=count;                                                                                         
	return 0;

}

int ChangeGoods(){
	ToChangeScreen();

	int id;
	goods * g;
	g=WantGoodsById(&id);

	if(g==(goods *)-1) return 1;
	if(g==NULL){
		ShowCantFind(id);
		WantEnter();
		return 0;
	}

	ShowChangeType();

	int type;
	type=WantNum();

	switch(type){
		case CHANGENAME:ChangeName(g);break;
		case CHANGECOUNT:ChangeCount(g);break;
	}
	ShowChangeSuccess();

	WantEnter();
	return 0;
}


void RemoveById() {
	int id;
	id = WantId();
	/*todo error*/
	RemoveGoodsById(GobalStore, id);
	return ;
}

void RemoveByName() {
	char *name;
	name = WantName();

	/*todo*/

	RemoveByName(GobalStore, name);
	return;
}
int RemoveGoods(){

	ToRemoveScreen();

	int type;
	type=WantNum();

	switch(type){
		case REMOVEBYID:RemoveById();break;
		case REMOVEBYNAME:RemoveByName();break;
		case REMOVETOEXIT: ToMainScreen(); return 1;
	}

	ShowRemoveSuccess();
	return 0;
}

int QueryGoods(){
	ToQueryScreen();
	ShowAllGoods(GobalStore);
	WantEnter();
	ToMainScreen();
	return 1;
}

void SaleGoods() {
	ToSaleScreen();

	int id;
	id = WantId();
	if (id == 0) {
		return;
	}

	int sc;
	ShowSaleCount();
	sc = WantNum();

	goods *g;
	g = FindGoodsById(GobalStore,id);

	g->count -= sc;

	ShowSaleSuccess();
	WantEnter();
	return;
}


void StockGoods() {
	ToStockScreen();

	int id;
	id = WantId();
	if (id == 0) {
		return;
	}
	int sc;
	ShowStockCount();
	sc = WantNum();

	goods *g;
	g = FindGoodsById(GobalStore, id);

	g->count += sc;

	ShowStockSuccess();
	WantEnter();
	return;
}

int  Loggin2S() {
	ToLoggin2SScreen();

	int type;
	/* todo*/
	type = WantNum();
	switch (type) {
	case SALE:SaleGoods(); break;
	case STOCK:StockGoods(); break;
	case EXIT: ToMainScreen(); return 1;
	}

	return 0;



}


void PrintSumCount() {
	ShowSumCount();
	printf("%d\n",SumCount(GobalStore));
	WantEnter();
}

void PrintIdCount() {
	ShowIdCount();
	printf("%d\n", SumId(GobalStore));
	WantEnter();
}

int StatisGoods() {
	ToStatisScreen(); 

	int type;
	type = WantNum();

	switch (type) {
	case SHOWSUMOFCOUNT:PrintSumCount(); break;
	case SHOWCOUNTID:PrintIdCount(); break;
	case EXIT: ToMainScreen(); return 1;
	}

	return 0;
}
int ListenMainKey(){
	int op;

	op=WantNum();

	switch(op){
		case WANTTYPEERROR:
			MainWantError (TypeError,T_NUM);
		case WANTNULLERROR:
			MainWantError (TypeNullError,T_NUM);
		case WANTLONGERROR:
			MainWantError (TypeLongError,T_NUM);
	}

	MENU(op)
		MENUITEM(MENULOGGIN,LOOP(LogginGoods));
		MENUITEM(MENUCHANGE,LOOP(ChangeGoods));
		MENUITEM(MENUREMOVE,LOOP(RemoveGoods));
		MENUITEM(MENULOG2S,LOOP(Loggin2S));
		MENUITEM(MENUQUERY,LOOP(QueryGoods));
		MENUITEM(MENUSTATIS,LOOP(StatisGoods));
		MENUITEM(MENUHELP,ShowHelp());
		MENUITEM(MENUEXIT,return 1);
	DEFAULTITEM(callback());
	
	return 0;
}
#define WithDebug(code) do{\
int oldstdout = dup(1);\
freopen("testin1.txt", "r", stdin);\
freopen("testout1.txt", "w", stdout);\
code;\
freopen("CON", "r", stdin);\
freopen("CON", "w", stdout);\
dup2(oldstdout, 1); \
}while (0);

int main(int argn,char * argv[] ){
	Init();
	
#ifdef LOCAL
	WithDebug(
	ToMainScreen();
	LOOP(ListenMainKey);
	SayGoodbye();)
#endif 
	ToMainScreen();
	LOOP(ListenMainKey);
	SayGoodbye();

    return 0;
}
