/*
The Goods And Store.
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
Some logic and function for good.
��Ʒ��ִ���Ϣ��
*/

#include "goods.h"

Store * InitStore() {
	Store *s;
	s = MAKE(Store);
	s->L = LinkListInit();/*�����Ʒ������*/
	StoreInfo *si;
	si = MAKE(StoreInfo);/*������Ϣ*/
	s->L->elem = si;
	return s;
}
int AddGoods(Store s, int id, char * name, int count) {
	goods * g;
	g = MAKE(goods);
	g->id = id;
	strcpy(g->name, name);
	g->count = count;
	pushfront(s.L, g);
	return OK;
}

int ChangeGoodsName(Store s, int id, char * name) {
	goods *g;
	g = FindGoodsById(s, id);
	if (g == NULL) {
		return CHANGEFINDERROR;
	}
	strcpy(g->name, name);
	return CHANGEOK;
}

int ChangeGoodsCount(Store s, int id, int count) {

	goods *g;
	g = FindGoodsById(s, id);

	if (g == NULL) {
		return CHANGEFINDERROR;
	}
	g->count = count;
	return CHANGEOK;
}

/*id�ıȽϺ���*/
int cmpid(goods *g, StoreInfo * si) {
	/*��storeinfo�����ȡ������idֵ*/
	return g->id == si->waitid;
}
/*���ֵıȽϺ���*/
int cmpname(goods *g, StoreInfo * si) {
	return strcmp(g->name, si->waitname) == 0;
}

/*Ѱ�ҵ�һ������ȽϺ����Ľڵ�*/
int find(LinkList L, ptr p, int(*cmp)(goods *, StoreInfo *)) {
	return (cmp(p, L->elem));
}

goods * getgood(LinkNode *p) {
	if (p == NULL) 
		return NULL;
	return p->elem;
}
LinkNode * FindLinkNodeById(Store s, int id) {
	StoreInfo * si;
	si = s.L->elem;
	si->waitid = id;/*��������id���ȥ���ȽϺ������ܻ�ȡ��*/
	return foreachwithcmp(s.L, find, cmpid);;
}

goods * FindGoodsById(Store s, int id) {
	LinkNode * p;
	/* note : it return last node ,so you must use R(p) to get correct node*/
	p = R(FindLinkNodeById(s, id));
	return getgood(p);
}

LinkNode * FindLinkNodeByName(Store s, char * name) {
	StoreInfo * si;
	si = s.L->elem;
	si->waitname = name;/*ͬ��*/
	return foreachwithcmp(s.L, find, cmpname);;

}
goods * FindGoodsByName(Store s, char *name) {
	LinkNode * p;
	/* note : it return last node ,so you must use R(p) to get correct node*/
	p = R(FindLinkNodeByName(s, name));
	return getgood(p);
}

int freegood(goods * g) {
	free(g);
	return 0;
}

int RemoveGoodsById(Store s, int id) {
	LinkNode * p;

	p = FindLinkNodeById(s, id);/*last node*/
	if (p == NULL) {
		return REMOVENULL;
	}
	RemoveNode(p, freegood);
	return 0;
}

int RemoveGoodsByName(Store s, char *name) {
	LinkNode * p;

	p = FindLinkNodeByName(s, name);/*last node*/
	if (p == NULL) {
		return REMOVENULL;
	}
	RemoveNode(p, freegood);
	return OK;
}

/*�����ȽϺ����ı���*/
int printgoods(LinkList L, ptr p) {
	goods *g;
	g = (goods*)p;
	printf("id:%05d\tname:%-10s\tcount:%05d\n", g->id, g->name, g->count);
	return 0;
}
int ShowAllGoods(Store s) {
	foreach(s.L, printgoods);
	return 0;
}

int sumcount(LinkList L, ptr p) {
	StoreInfo * si;
	si = L->elem;
	goods *g;
	g = (goods*)p;
	si->sumconut += g->count;
	return 0;
}

int SumCount(Store s) {
	StoreInfo *si;
	si = s.L->elem;
	si->sumconut = 0;/*������Ϣ��*/
	foreach(s.L, sumcount);
	return si->sumconut;
}

int sumid(LinkList L, ptr p) {
	StoreInfo * si;
	si = L->elem;
	si->sumconut += 1;
	return 0;
}
int SumId(Store s) {
	StoreInfo *si;
	si = s.L->elem;
	si->sumconut = 0;
	foreach(s.L, sumid);
	return si->sumconut;
}

/*���ļ���ȡ��Ʒ��Ϣ*/
goods * goodreader(FILE *fp) {
	goods* g;
	g = MAKE(goods);
	if (fread(g, sizeof(goods), 1, fp))
		return g;
	return 0;
}
/*д����Ʒ��Ϣ*/
int goodswriter(FILE * fp, goods *g) {
	fwrite(g, sizeof(goods), 1, fp);
	return 0;
}