#include "linklist.h"

void init(LinkList L){
	L->next=NULL;
	return ;
}

LinkNode * newnode (ptr elem){
	ListNode * n;
	n=(ListNode *) malloc(sizeof(ListNode));
	n->elem=elem;
	n->next=NULL;
	return n;
}
LinkNode * back(LinkList L){
	ListNode * temp;
	temp=L;
	while(temp->next){
		temp=temp->next;
	}
	return temp;
}
int pushback(LinkList L,(ptr) elem){

	
	LinkNode * n;
	n=newnode(elem);

	ListNode * temp;
	temp=back(L);
	temp->next=n;

	return 0;
}

int pushfront(LinkList L, ptr elem){

	LinkNode * n,p;
	n=newnode(elem);

	p=L->next;

	L->next=n;
	n->next=p;

	return 0;
}

ptr foreach(LinkList L,(int *)fn(ptr )){

	LinkNode *p;
	p=L;

	while(p->next){
		if(fn(p->next->elem)){
			return p->next;
		}
		p=p->next;
	}
	return NULL;
}

