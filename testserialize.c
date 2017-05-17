#include "serialize.h"

int print( LinkList L,ptr elem){
	printf("%d",((goods *)elem)->id);
	return 0;
}

int writer(FILE * fp,goods *g){
	fwrite(g,sizeof (goods) ,1,fp);
}
int main(){
	Store *s;
	s=InitStore();

	LinkList L;
	L=s->L;

	goods a,b,c;
	a.id=1;
	b.id=2;
	c.id=3;


	pushback(L,&a);
	pushback(L,&b);
	pushfront(L,&c);

	foreach(L,print);
	FILE * fp;
	fp=fopen("testsave.dat","w");

	serialize(*s,fp,writer);

	return 0;
}