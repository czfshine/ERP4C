/*
Serialize Linklist .
Author czfshine (https://github.com/czfshine)
Date :2017-05-10 11:10
Langage :ANSI C
Listen :MIT
Description:
seralize and unseralize linklist to/from file.
���л��ͷ����л�����
*/
#include "serialize.h"

int pretretment(LinkList L, ptr p, writerfn(writer)) {
	StoreInfo *si;
	si = L->elem;
	return writer(si->file, p);
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
