#include "serialize.h"

int print( LinkList L,ptr elem){
	printf("%d",((goods *)elem)->id);
	return 0;
}

int writer(FILE * fp,goods *g){
	fwrite(g,sizeof (goods) ,1,fp);
	return 0;
}

goods * reader(FILE *fp){
	goods* g;
	g=MAKE(goods);

	fread(g,sizeof(goods),1,fp);
	return 0;
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

	strcpy(a.name,"test");
	strcpy(b.name,"test");
	strcpy(c.name,"test");

	pushback(L,&a);
	pushback(L,&b);
	pushfront(L,&c);

	foreach(L,print);
	FILE * fp;
	fp=fopen("testsave.dat","w");

	serialize(*s,fp,writer);
	fclose(fp);


	fp=fopen("testsave.dat","r");

	unserialize(*s,fp,reader);

	foreach(L,print);
	return 0;
}