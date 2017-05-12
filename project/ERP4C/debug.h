
#ifndef LOCAL

int DEBUG = 0;
#else
int DEBUG = 1;
#endif 

#define WithDebug(code) do{\
	if(DEBUG){\
		int oldstdout = dup(1);\
		freopen("testin1.txt", "r", stdin);\
		freopen("testout1.txt", "w", stdout);\
		code;\
		freopen("CON", "r", stdin);\
		freopen("CON", "w", stdout);\
		dup2(oldstdout, 1);} \
		code;\
}while (0);
