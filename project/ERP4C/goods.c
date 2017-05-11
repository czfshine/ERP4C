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
	return 0;
}

int ChangeGoodsName(Store s,int id,char * name){

	goods *g;
	g=FindGoodsById(s,id);

	strcpy(g->name,name);
	return 0;
}

int ChangeGoodsCount(Store s,int id,int count){

	goods *g;
	g=FindGoodsById(s,id);

	g->count=count;
	return 0;
}

int findid(LinkList L,ptr p){
	StoreInfo *si;
	si= L->elem;
	goods *g;
	g=(goods *) p;
	if(g->id == si->waitid ){
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
	p=foreach(s.L,findid);

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