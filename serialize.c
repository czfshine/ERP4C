#include "goods.h"
#include "linklist.h"


#define writerfn(name) int(* name)(FILE* ,void *)
int serialize(Store s,FILE * fp,writerfn(writer)){
	
}