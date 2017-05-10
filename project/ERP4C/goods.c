#include "goods.h"

Store * InitStore(){
	Store *s;
	s=(Store* ) malloc(sizeof(Store));
	s.L=LinkListInit();
	return s;
}
