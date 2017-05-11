#ifndef LINKLIST_H
#define LINKLIST_H 
#include <stdlib.h>
#include <string.h>
#define ptr void *

typedef struct LinkNode
{	ptr elem;
	struct LinkNode *next;
}  LinkNode,*LinkList;


LinkList  LinkListInit();
LinkNode * newnode (ptr elem);
LinkNode * back(LinkList L);
int pushback(LinkList L,ptr elem);
int pushfront(LinkList L, ptr elem);
ptr foreach(LinkList L,int (* fn)(LinkList,ptr ,int (* cmp )(ptr,ptr)),int (* cmp) (ptr,ptr));
#endif
