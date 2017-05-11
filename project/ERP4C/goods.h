#ifndef GOODS_H
#define GOODS_H 

#include <stdio.h>

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




Store * InitStore();
int AddGoods(Store s,int id,char * name,int count);
int ChangeGoodsName(Store s,int id,char * name);
int ChangeGoodsCount(Store s,int id,int count);
int findid(LinkList L,ptr );
goods * FindGoodsById(Store s,int id);

#endif