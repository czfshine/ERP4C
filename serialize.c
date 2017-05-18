#include "serialize.h"

int pretretment(LinkList L, ptr p, writerfn(writer)) {
	StoreInfo *si;
	si = L->elem;
	goods *g;
	g = (goods *)p;

	if (writer(si->file, g)) {
		return 1;
	}
	else {
		return 0;
	}
}


int serialize(Store s, FILE * fp, writerfn(writer)) {
	SI(s)->file = fp;
	foreachwithcmp(s.L, pretretment, writer);
	return 0;
}

int unserialize(Store s, FILE * fp, readfn(reader)) {

	void * elem;
	while (elem = reader(fp)) {
		pushfront(s.L, elem);
	}
	return 0;
}
