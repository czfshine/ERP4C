#include "stdio.h"
#include "string.h"
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
		getchar();
		while((ch=getchar())!='e')
			B[cur++]=ch;
		B[cur]='\0';

		scanf("%d",&D);
		//printf("%d%s%d\n\n",A,B,D);

		int len=strlen(B);
		if(len==1&&B[0]=='0'&&D==0){
			printf("%d\n",A);
			continue;
		}
		
		if(len>D){
			int sub=len-D;
			int i;
			printf("%d",A);
			for (i = 0; i < D; ++i)
				printf("%c",B[i]);
			printf(".");
			for (int j = 0; j < sub; ++j)
				printf("%c",B[D+j]);
		}else if(len==D){
			if(A!=0)
			printf("%d",A);
			for (int i = 0; i < D; ++i)
				printf("%c",B[i]);
		}else{
			if(A!=0)
			printf("%d",A);
			int sub=D-len;
			int i;
			for (i = 0; i < len; ++i)
				printf("%c",B[i]);
			for (int j = 0; j < sub; ++j)
				printf("0");
		}
		printf("\n");
	}
	return 0;
}