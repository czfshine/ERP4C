/*
General Linklist Library.
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
The general linklist,other infomation to see code .
*/
#ifndef LINKLIST_H
#define LINKLIST_H 
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define ptr void *

#define R(p) (((p)==NULL)?NULL:((p)->next))


typedef struct LinkNode
{	ptr elem;
	struct LinkNode *next;
}  LinkNode,*LinkList;


LinkList  LinkListInit();
LinkNode * newnode (ptr elem);
LinkNode * back(LinkList L);
int pushback(LinkList L,ptr elem);
int pushfront(LinkList L, ptr elem);
LinkNode * foreachwithcmp(LinkList L,int (* fn)(LinkList,ptr ,int (* cmp )(ptr,ptr)),int (* cmp) (ptr,ptr));
LinkNode * foreach(LinkList L,int (* fn)(LinkList,ptr ));
int RemoveNode(LinkNode *p, int(*freeelem)(ptr));
#endif
