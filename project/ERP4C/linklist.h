/*
General Linklist Library.
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
	The general linklist,other infomation to see code .
	ͨ������⣬֧���������ɾ���Ѱ��
*/
#ifndef LINKLIST_H
#define LINKLIST_H 
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*ͨ��ָ��*/

#define ptr void *


/*ȡ��ȷ�Ľڵ�*/
#define R(p) (((p)==NULL)?NULL:((p)->next))


typedef struct LinkNode
{
	ptr elem;
	struct LinkNode *next;
}  LinkNode, *LinkList;
#define cmpfn(cmp)  int(*cmp)(ptr, ptr)

LinkList  LinkListInit();/*��ʼ��*/
LinkNode * newnode(ptr elem);/*�½ڵ�*/
LinkNode * back(LinkList L);/*�������һ���ڵ�*/
int pushback(LinkList L, ptr elem);/*�ӵ����*/
int pushfront(LinkList L, ptr elem);/*�ӵ���ǰ*/
LinkNode * foreach(LinkList L, int(*fn)(LinkList, ptr));/*����*/
LinkNode * foreachwithcmp(LinkList L, int(*fn)(LinkList, ptr, cmpfn(cmp)), cmpfn(cmp));/*���ȽϺ����ı���*/
int RemoveNode(LinkNode *p, int(*freeelem)(ptr));/*ɾ���ڵ�*/
#endif
