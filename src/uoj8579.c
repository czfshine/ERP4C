#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;

int CreateLink_L(LinkList &L,int n){
// 创建含有n个元素的单链表
  LinkList p,q;
  int i;
  ElemType e;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;              // 先建立一个带头结点的单链表
  q = (LinkList)malloc(sizeof(LNode));
  q = L;
  for (i=0; i<n; i++) {
	 scanf("%d", &e);
    p = (LinkList)malloc(sizeof(LNode));
    p->next=NULL;  // 生成新结点
    q->next=p;
    p->data=e;
    q=p;

  }
  return OK;
}

int LoadLink_L(LinkList &L){
// 单链表遍历
 LinkList p = L->next;
 if(p==NULL)printf("The List is empty!"); // 请填空
 else
 {
	 printf("The LinkList is:");
	 while(p)    // 请填空
	 {
		printf("%d ",p->data); 
		p=p->next;   // 请填空
	 }
 }
 printf("\n");
 return OK;
}

int LinkInsert_L(LinkList &L,int i,ElemType e){
LinkList p = L->next;
int j=0;
LinkList q ;
q=p;
 if(i==0 || p==NULL) return ERROR; // 请填空
 else
 {	if(i==1){

LinkList qq = (LinkList)malloc(sizeof(LNode));

 		qq->next=L->next;

 		L->next=qq;

 		qq->data=e;

 		return OK;



 }
	 while(p)    // 请填空
	 {
		 
		 if(j==i-1){break;}
		 j++;
		 q=p;
		p=p->next;   // 请填空
	 }


 }

 if(i-1<j){
 	return ERROR;
 }else{
 	if(i-1==j){
 		LinkList qq = (LinkList)malloc(sizeof(LNode));

 		qq->next=q->next;

 		q->next=qq;

 		qq->data=e;
 		return OK;
 	}else{
 	return ERROR;
 	}
 }

}

int LinkDelete_L(LinkList &L,int i, ElemType &e){


LinkList p = L->next;
int j=0;
LinkList q,qq ;
q=p;
 if(i==0 || p==NULL) return ERROR; // 请填空
 else
 {	if(i==1){

 		if(L->next){
qq=L->next;
L->next=L->next->next;
e=qq->data;
 		}else{

 			return ERROR;
 		}
 		return OK;



 }
	 while(p)    // 请填空
	 {
		 
		 if(j==i-1){break;}
		 j++;
		 q=p;
		p=p->next;   // 请填空
	 }


 }

 if(i-1<j){
 	return ERROR;
 }else{
 	if(i-1==j){
 		

 		 		if(q->next){
qq=q->next;
q->next=q->next->next;
e=qq->data;
 		}else{

 			return ERROR;
 		}
 		return OK;
 	}else{
 	return ERROR;
 	}
 }



}

int main()
{
 LinkList T;
 int a,n,i;
 ElemType x, e;
 printf("Please input the init size of the linklist:\n");
 scanf("%d",&n);
 printf("Please input the %d element of the linklist:\n", n);
 if(CreateLink_L(T,n))     // 判断链表是否创建成功，请填空
 {
	 printf("A Link List Has Created.\n");
	 LoadLink_L(T);
 }
 while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
				  if(!LinkInsert_L(T,i,x)) printf("Insert Error!\n"); // 判断i值是否合法，请填空
				  else printf("The Element %d is Successfully Inserted!\n", x); 
				  break;
			case 2: scanf("%d",&i);
				  if(!LinkDelete_L(T,i,e)) printf("Delete Error!\n"); // 判断i值是否合法，请填空
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: LoadLink_L(T);
				  break;
			case 0: return 1;
		}
	}
}