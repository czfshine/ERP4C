/*
Common Library.
Author czfshine (https://github.com/czfshine)
Date :2017-05-18 21:12
Langage :ANSI C
Listen :MIT
Description:
ͨ�ú����������������ʩ��
*/
#ifndef COMMON_H
#define COMMON_H
/*�����ڴ�*/
#define MAKE(type) (type * ) malloc(sizeof(type));

#define LOOP(fn) while(!fn()){};

#endif