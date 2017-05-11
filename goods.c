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
int findidwithcmp(LinkList L,ptr p,int (* cmp)(goods *,StoreInfo *)){
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

goods * FindGoodsById(Store s,int id){
	StoreInfo * si;
	si=	s.L->elem;
	si->waitid=id;
	LinkNode * p;
	p=foreach(s.L,findid,cmpid);

	if(p==NULL){
		return NULL;
	}else{
		goods * g;
		g=p->elem;
		return g;
	}
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