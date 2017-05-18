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

#ifndef SERIALIZE_H
#define SERIALIZE_H
#include "goods.h"
#include "linklist.h"


/*�ڵ�д�뺯��*/
#define writerfn(name) int(* name)(FILE* ,void *)
/*�ڵ��ȡ����*/
#define readfn(name)	void*(*name)(FILE *)

int serialize(Store s, FILE * fp, writerfn(writer));

int unserialize(Store s, FILE * fp, readfn(reader));

#endif