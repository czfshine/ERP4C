#include "linklist.h"
#include "common.h"
LinkList LinkListInit(){
	LinkNode *n;
	n=newnode(NULL);
	n->next=NULL;
	return n;
}

LinkNode * newnode (ptr elem){
	LinkNode * n;
	n=MAKE(LinkNode);
	n->elem=elem;
	n->next=NULL;
	return n;
}
LinkNode * back(LinkList L){
	LinkNode * temp;
	temp=L;
	while(temp->next){
		temp=temp->next;
	}
	return temp;
}
int pushback(LinkList L,ptr elem){

	
	LinkNode * n;
	n=newnode(elem);

	LinkNode * temp;
	temp=back(L);
	temp->next=n;

	return 0;
}

int pushfront(LinkList L, ptr elem){

	LinkNode * n,*p;
	n=newnode(elem);

	p=L->next;

	L->next=n;
	n->next=p;

	return 0;
}

ptr foreach(LinkList L,int (* fn)(LinkList,ptr )){

	LinkNode *p;
	p=L;

	while(p->next){
		LinkNode * a=p->next;
		ptr b=a->elem;
		if(fn(L,b)){
			return p->next;
		}
		p=p->next;
	}
	return NULL;
}

