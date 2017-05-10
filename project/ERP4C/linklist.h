#define ptr void *

typedef struct
{	ptr elem;
	struct LinkNode *next;
}  LinkNode,LinkList;


void init(LinkList);
LinkNode * newnode (ptr elem);
LinkNode * back(LinkList L);
int pushback(LinkList L,(ptr) elem);
int pushfront(LinkList L, ptr elem);
ptr foreach(LinkList L,(int *)fn(ptr ));