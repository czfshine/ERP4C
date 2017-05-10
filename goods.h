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
