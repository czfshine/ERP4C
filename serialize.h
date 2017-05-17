#ifndef SERIALIZE_H
#define SERIALIZE_H
#include "goods.h"
#include "linklist.h"



#define writerfn(name) int(* name)(FILE* ,void *)
#define readfn(name)	void*(*name)(FILE *)

int serialize(Store s, FILE * fp, writerfn(writer));

int unserialize(Store s, FILE * fp, readfn(reader));

#endif