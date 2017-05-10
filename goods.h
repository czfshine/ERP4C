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
Store * InitStore();
int AddGoods(Store s,int id,char * name,int count);
int ChangeGoodsName(Store s,int id,char * name);
int ChangeGoodsCount(Store s,int id,int count);
int findid(LinkList L,ptr );
goods * FindGoodsById(Store s,int id);