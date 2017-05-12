/*
The Goods And Store.
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
Some logic and function for good.
*/
#ifndef GOODS_H
#define GOODS_H 

#include <stdio.h>
#include <string.h>
#include "common.h"
#include "linklist.h"

typedef struct {
	int id;
	char name[255];
	int count;

} goods;

typedef struct {
	LinkList L;
}	Store;

typedef struct {
	int waitid;
	char * waitname;
	int sumconut;
}	StoreInfo;


#define CANTFIND 0;

#ifndef CHANGEOK
#define CHANGEOK 0
#endif

#ifndef CHANGEFINDERROR
#define CHANGEFINDERROR 1
#endif

#ifndef OK
#define OK 0
#endif

#ifndef ERROR
#define ERROR 1
#endif

#define REMOVENULL -1


Store * InitStore();
int AddGoods(Store s,int id,char * name,int count);
int ChangeGoodsName(Store s,int id,char * name);
int ChangeGoodsCount(Store s,int id,int count);
goods * FindGoodsById(Store s,int id);
goods * FindGoodsByName(Store s,char *name);
int ShowAllGoods(Store);
int RemoveGoodsById(Store s, int id);

int RemoveGoodsByName(Store s, char *name);

int SumCount(Store s);
int SumId(Store s);
#endif