#include "linklist.h"
typedef struct {
	int a;
} goods;


int print( ptr elem){
	printf("%d",((goods *)elem)->a);
	return 0;
}
int main(){
	LinkList L;
	L=init();

	goods a,b,c;
	a.a=1;
	b.a=2;
	c.a=3;

	pushback(L,&a);
	pushback(L,&b);
	pushfront(L,&c);

	foreach(L,print);

	return 0;
}