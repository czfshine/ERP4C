/*
Debug Library.
Author czfshine (https://github.com/czfshine)
Date :2017-05-18 21:12
Langage :ANSI C
Listen :MIT
Description:
���Կ⡣
*/

/*�ڿ�������ʱ��LOCAL��򿪣��������ģʽ*/
#ifndef LOCAL
int DEBUG = 0;
#else
int DEBUG = 1;
#endif 

/*���ļ�������������²��ԣ�Ȼ�󽫿���Ȩ�����û�*/
#ifdef __linux__ || __linux
#define WithDebug(code) code;
#else
#define WithDebug(code) do{\
	if(DEBUG){\
		/*����ԭʼstdout����Ȼ���������*/\
		int oldstdout = _dup(1);\
		freopen("testin1.txt", "r", stdin);\
		freopen("testout1.txt", "w", stdout);\
		code;\
		freopen("CON", "r", stdin);\
		freopen("CON", "w", stdout);\
		_dup2(oldstdout, 1);\
	} \
		code;\
}while (0);
#endif
