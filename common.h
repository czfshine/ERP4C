#ifndef COMMON_H
#define COMMON_H 
#define MAKE(type) (type * ) malloc(sizeof(type));

#define LOOP(fn) while(!fn()){}



#endif