#include "stdio.h"

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int kcase = 0; kcase < T; ++kcase)
	{
		int A,D;
		char B[102];

		//too young too simple
		//scanf("%d.%se%d",&A,B,&D);
		//printf("%d%s%d",A,B,D);

		scanf("%d",&A);
		char ch;
		int cur=0;
		while((ch=getchar())!='e')
			B[cur++]=ch;
		B[cur]='\0';

		scnaf("%d",&D);
		//printf("%d%s%d",A,B,D);
	}
	return 0;
}