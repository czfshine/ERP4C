/*
Text User Interface (TUI)
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
The user interface in console.
*/
#ifndef TUI_H
#define TUI_H 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "common.h"
#ifdef DONTCLEARSCREEN 
#define CleanScreen()  SayHello();
#elif __linux__ || __linux
#define CleanScreen()  system("clear");SayHello();
#else
#define CleanScreen()  system("cls");SayHello();
#endif
#define ToMainScreen() CleanScreen();\
    					ShowMainMenu();

#define ToLogginScreen() CleanScreen();\
						ShowLogginGoods();
#define ToChangeScreen() CleanScreen();\
						ShowChangeGoods();




#define InputClean() 	char ch;\
						while((ch=getchar())!='\n'){}


#define WANTTYPEERROR -1
#define WANTNULLERROR -2
#define WANTLONGERROR -3


#ifndef MENULOGGIN
#define MENULOGGIN 1
#endif
#ifndef MENUCHANGE
#define MENUCHANGE 2
#endif
#ifndef MENUREMOVE
#define MENUREMOVE 3
#endif
#ifndef MENULOG2S
#define MENULOG2S 4
#endif
#ifndef MENUQUERY
#define MENUQUERY 5
#endif
#ifndef MENUSTATIS
#define MENUSTATIS 6
#endif
#ifndef MENUHELP
#define MENUHELP 7
#endif
#ifndef MENUEXIT
#define MENUEXIT 0
#endif


typedef int INPUTTYPE ;

#define T_NUM 0
#define T_STR 1


#define MainWantError(errortype,wanttype) 	CleanScreen();\
										   	errortype(wanttype);\
											ShowMainMenu();\
											return 0;
#define MENUITEM(ID,CALLBACK) case ID :CALLBACK;break;
#define MENU(op) switch(op){
#define DEFAULTITEM(CALLBACK) default : CALLBACK; }	


void SayHello();
void SayGoodbye();
void ShowMainMenu();
void ShowHelp();
void ShowLogginGoods();
void ShowGoodsExist(int id);
void ShowLogginSuccess();
void ShowChangeSuccess();
void ShowChangeGoods();
void ShowCantFind(int );
void ShowChangeType();
void TypeError(INPUTTYPE T);
void TypeNullError(INPUTTYPE T);
void TypeLongError(INPUTTYPE T);


int WantNum();
char * WantString();
char * WantName();
int WantId();
int WantCount();
void WantEnter();


#ifndef CHANGENAME
#define CHANGENAME 1
#endif
#ifndef CHANGECOUNT
#define CHANGECOUNT 2
#endif

#ifndef REMOVEBYID
#define REMOVEBYID 1
#endif /* !REMOVEBYID*/

#ifndef REMOVEBYNAME
#define REMOVEBYNAME 2
#endif /* !REMOVEBYNAME*/

#ifndef REMOVETOEXIT
#define REMOVETOEXIT  0
#endif /* !REMOVETOEXIT*/


#ifndef SALE
#define SALE 1 
#endif /* !SALE*/

#ifndef STOCK
#define STOCK 2		
#endif /* !STOCK*/

#ifndef EXIT
#define EXIT 0
#endif /* !EXIT */

#ifndef SHOWSUMOFCOUNT
#define SHOWSUMOFCOUNT 1
#endif /* !SHOWSUMOFCOUNT */

#ifndef SHOWCOUNTID
#define SHOWCOUNTID 2
#endif /* !SHOWCOUNTID*/

#endif

void ToLoggin2SScreen();

void ToSaleScreen();

void ShowSaleCount();

void ShowSaleSuccess();
	
void ToStockScreen();

void ShowStockCount();

void ShowStockSuccess();

void ShowSumCount();
void ShowIdCount();
void ToStatisScreen();
void ShowRemove();
void ShowRemoveSuccess();