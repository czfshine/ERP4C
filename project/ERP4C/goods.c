/*
The Goods And Store.
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
Some logic and function for good.
*/

#include "goods.h"

Store * InitStore(){
	Store *s;
	s=MAKE(Store);
	s->L=LinkListInit();
	StoreInfo *si;
	si=MAKE(StoreInfo);
	s->L->elem=si;
	return s;
}
int AddGoods(Store s,int id,char * name,int count){
	goods * g;
	g=MAKE(goods);
	g->id=id;
	strcpy(g->name,name);
	g->count=count;
	pushfront(s.L,g);
	free(name);
	return OK;
}

int ChangeGoodsName(Store s,int id,char * name){

	goods *g;
	g=FindGoodsById(s,id);

	if(g==NULL){
		return CHANGEFINDERROR;
	}
	strcpy(g->name,name);
	return CHANGEOK;
}

int ChangeGoodsCount(Store s,int id,int count){

	goods *g;
	g=FindGoodsById(s,id);

	if(g==NULL){
		return CHANGEFINDERROR;
	}
	g->count=count;
	return CHANGEOK;
}
int cmpid(goods *g,StoreInfo * si){
	return g->id == si->waitid ;
}

int cmpname(goods *g,StoreInfo * si){
	return strcmp(g->name,si->waitname)==0;
}

int find(LinkList L,ptr p,int (* cmp)(goods *,StoreInfo *)){
	StoreInfo *si;
	si= L->elem;
	goods *g;
	g=(goods *) p;
	if(cmp(g,si)){
		return 1;
	}else{
		return 0;
	}
}

goods * getgood(LinkNode *p) {
	if (p == NULL) {
		return NULL;
	}
	goods * g;
	g = p->elem;
	return g;
}
LinkNode * FindLinkNodeById(Store s, int id) {
	StoreInfo * si;
	si = s.L->elem;
	si->waitid = id;
	LinkNode * p;
	p = foreachwithcmp(s.L, find, cmpid);
	return p;
}

goods * FindGoodsById(Store s,int id){
	LinkNode * p;
	/* note : it return last node ,so you must use R(p) to get correct node*/
	p = R(FindLinkNodeById(s, id));
	return getgood(p);
}

LinkNode * FindLinkNodeByName(Store s, char * name) {
	StoreInfo * si;
	si = s.L->elem;
	si->waitname = name;
	LinkNode * p;
	p = foreachwithcmp(s.L, find, cmpname);
	return p;

}
goods * FindGoodsByName(Store s,char *name){
	LinkNode * p;
	/* note : it return last node ,so you must use R(p) to get correct node*/
	p = R(FindLinkNodeByName(s, name));
	return getgood(p);
}

int freegood(goods * g) {
	free(g);
	return 0;
}
int RemoveGoodsById(Store s,int id) {
	LinkNode * p;

	p = FindLinkNodeById(s, id);/*last node*/
	RemoveNode(p,freegood);
	return 0;
}

int RemoveGoodsByName(Store s,char *name) {
	LinkNode * p;

	p = FindLinkNodeByName(s, name);/*last node*/
	RemoveNode(p, freegood);
	return 0;
}

int printgoods(LinkList L,ptr p){
	goods *g;
	g=(goods* )p;
	printf("id:%05d\tname:%-10s\tcount:%05d\n",g->id,g->name,g->count);
	return 0;
}
int ShowAllGoods(Store s){
	foreach(s.L,printgoods);
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
	si->sumconut = 0;
	foreach(s.L, sumcount);
	return si->sumconut;
}

int sumid(LinkList L, ptr p) {
	StoreInfo * si;
	si = L->elem;
	si->sumconut +=1;
	return 0;
}
int SumId(Store s) {
	StoreInfo *si;
	si = s.L->elem;
	si->sumconut = 0;
	foreach(s.L, sumcount);
	return si->sumconut;
}
